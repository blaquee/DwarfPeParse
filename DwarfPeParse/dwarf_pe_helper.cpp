#include "dwarf_pe_helper.h"

#include <windows.h>
#include <stdlib.h>



typedef struct
{
	HANDLE hFileMapping;
	DWORD_PTR szFileSize;
	union {
		PBYTE lpFileBase;
		PIMAGE_DOS_HEADER pDosHeader;
	};

	PIMAGE_NT_HEADERS pNtHeaders;
	PIMAGE_SECTION_HEADER Sections;
	PIMAGE_SYMBOL pSymbolTable;
	PSTR pStringTable;
}PeObject;

static int pe_get_section_info(void *obj, Dwarf_Half section_index,
	Dwarf_Obj_Access_Section *return_section,
	int *error)
{
	PeObject* pe_obj = (PeObject*)obj;
	return_section->addr = 0;
	if (section_index == 0)
	{
		return_section->size = 0;
		return_section->name = "";
	}
	else
	{
		PIMAGE_SECTION_HEADER pSection = pe_obj->Sections + section_index - 1;
		if (pSection->Misc.VirtualSize < pSection->SizeOfRawData)
			return_section->size = pSection->Misc.VirtualSize;
		else
			return_section->size = pSection->SizeOfRawData;

		return_section->name = (const char*)pSection->Name;
		if (return_section->name[0] == '/') {
			return_section->name = &pe_obj->pStringTable[atoi(&return_section->name[1])];
		}
	}
	return_section->link = 0;
	return_section->entrysize = 0;

	return DW_DLV_OK;
}

static Dwarf_Endianness pe_get_byte_order(void *obj)
{
	return DW_OBJECT_LSB;
}

static Dwarf_Small pe_get_length_pointer_size(void *obj)
{
	PeObject *pe_obj = (PeObject *)obj;
	PIMAGE_OPTIONAL_HEADER pOptionalHeader = &pe_obj->pNtHeaders->OptionalHeader;

	switch (pOptionalHeader->Magic)
	{
	case IMAGE_NT_OPTIONAL_HDR32_MAGIC:
		return 4;
	case IMAGE_NT_OPTIONAL_HDR64_MAGIC:
		return 8;
	default:
		return 0;
	}
}

static Dwarf_Unsigned pe_get_section_count(void *obj)
{
	PeObject *pe_obj = (PeObject*)obj;
	PIMAGE_FILE_HEADER pFileHeader = &pe_obj->pNtHeaders->FileHeader;
	return pFileHeader->NumberOfSections + 1;
}

static int pe_load_section(void *obj,
	Dwarf_Half section_index,
	Dwarf_Small **return_data,
	int *error)
{
	PeObject* pe_obj = (PeObject*)obj;
	if (section_index == 0)
		return DW_DLV_NO_ENTRY;
	else {
		PIMAGE_SECTION_HEADER pSection = pe_obj->Sections + section_index - 1;
		*return_data = pe_obj->lpFileBase + pSection->PointerToRawData;
		return DW_DLV_OK;
	}
}

// define the methods for the dwarflib object interface
static const Dwarf_Obj_Access_Methods pe_methods
{
	pe_get_section_info,
	pe_get_byte_order,
	pe_get_length_pointer_size,
	pe_get_length_pointer_size,
	pe_get_section_count,
	pe_load_section
};


int dwarf_pe_init(HANDLE hFile, const TCHAR* chFilePath,
	Dwarf_Handler errHandler, Dwarf_Ptr errArg,
	Dwarf_Debug *retDbg, Dwarf_Error *dwErr)
{
	int res = DW_DLV_ERROR;
	PeObject* pe_obj;
	LARGE_INTEGER lpSize;

	pe_obj = (PeObject*)calloc(1, sizeof(PeObject));
	if (!pe_obj)
		return res;

	pe_obj->hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
	if (!pe_obj) {
		goto failmap;
	}

	//Map view
	pe_obj->lpFileBase = (PBYTE)MapViewOfFile(pe_obj->hFileMapping, FILE_MAP_READ, 0, 0, 0);
	if (!pe_obj->lpFileBase) {
		goto failmapview;
	}

	if (!GetFileSizeEx(hFile, &lpSize)) {
		goto badsize;
	}

#ifdef _WIN64
	pe_obj->szFileSize = lpSize.QuadPart;
#else
	pe_obj->szFileSize = lpSize.LowPart;
#endif

	// fill in PE headers
	pe_obj->pNtHeaders = (PIMAGE_NT_HEADERS)(
		pe_obj->lpFileBase + pe_obj->pDosHeader->e_lfanew);

	// Pointer to PE sections table
	pe_obj->Sections = IMAGE_FIRST_SECTION(pe_obj->pNtHeaders);

	// Symbol Table
	pe_obj->pSymbolTable = (PIMAGE_SYMBOL)(
		pe_obj->lpFileBase + pe_obj->pNtHeaders->FileHeader.PointerToSymbolTable);

	// String table starts at end of symbol table
	pe_obj->pStringTable = (PSTR)&pe_obj->pSymbolTable[pe_obj->pNtHeaders->FileHeader.NumberOfSymbols];

	// TODO: support external symbol files (drmingw.dwarf_pe.cpp:208 for ref) 

	// Create the Dwarf Object Access Interface
	Dwarf_Obj_Access_Interface* dwarfInterface;

	dwarfInterface = (Dwarf_Obj_Access_Interface*)calloc(1, sizeof(Dwarf_Obj_Access_Interface));
	if (!dwarfInterface)
		goto nointerface;

	//assign the object
	dwarfInterface->object = pe_obj;
	dwarfInterface->methods = &pe_methods;

	res = dwarf_object_init(dwarfInterface, errHandler, errArg, retDbg, dwErr);
	if (res == DW_DLV_OK) {
		return res;
	}

badsize:
nointerface:
	UnmapViewOfFile(pe_obj->lpFileBase);
failmapview:
	CloseHandle(pe_obj->hFileMapping);
failmap:
	free(pe_obj);

	return res;
}

int dwarf_pe_finish(Dwarf_Debug dbg, Dwarf_Error *err)
{
	Dwarf_Obj_Access_Interface *intf = dbg->de_obj_file;
	PeObject *pe_obj = (PeObject*)intf->object;
	free(intf);
	UnmapViewOfFile(pe_obj->lpFileBase);
	CloseHandle(pe_obj->hFileMapping);
	free(pe_obj);
	return dwarf_object_finish(dbg, err);
}
