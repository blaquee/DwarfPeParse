// DwarfPeParse.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>

// include these to configure the preprocessor directives for libdwarf and libelf
#include <libdwarf\config.h>
#include <libelf\config.h>

#include "dwarf_pe_helper.h"

static void print_die_data(Dwarf_Debug dbg, Dwarf_Die print_me, int level)
{
	char *name = 0;
	Dwarf_Error error = 0;
	Dwarf_Half tag = 0;
	const char *tagname = 0;
	int res = dwarf_diename(print_me, &name, &error);
	if (res == DW_DLV_ERROR) {
		printf("Error in dwarf_diename , level %d \n", level);
		exit(1);
	}
	if (res == DW_DLV_NO_ENTRY) {
		return;
	}
	res = dwarf_tag(print_me, &tag, &error);
	if (res != DW_DLV_OK) {
		printf("Error in dwarf_tag , level %d \n", level);
		exit(1);
	}
	res = dwarf_get_TAG_name(tag, &tagname);
	if (res != DW_DLV_OK) {
		printf("Error in dwarf_get_TAG_name , level %d \n", level);
		exit(1);
	}
	printf("<%d> tag: %d %s  name: %s\n", level, tag, tagname, name);
	dwarf_dealloc(dbg, name, DW_DLA_STRING);
}

static void get_die_and_siblings(Dwarf_Debug dbg, Dwarf_Die in_die, int in_level)
{
	int res = DW_DLV_ERROR;
	Dwarf_Die cur_die = in_die;
	Dwarf_Die child = 0;
	Dwarf_Error error;
	print_die_data(dbg, in_die, in_level);

	for (;;) {
		Dwarf_Die sib_die = 0;
		res = dwarf_child(cur_die, &child, &error);
		if (res == DW_DLV_ERROR) {
			printf("Error in dwarf_child , level %d \n", in_level);
			exit(1);
		}
		if (res == DW_DLV_OK) {
			get_die_and_siblings(dbg, child, in_level + 1);
		}
		/* res == DW_DLV_NO_ENTRY */
		res = dwarf_siblingof(dbg, cur_die, &sib_die, &error);
		if (res == DW_DLV_ERROR) {
			printf("Error in dwarf_siblingof , level %d \n", in_level);
			exit(1);
		}
		if (res == DW_DLV_NO_ENTRY) {
			/* Done at this level. */
			break;
		}
		/* res == DW_DLV_OK */
		if (cur_die != in_die) {
			dwarf_dealloc(dbg, cur_die, DW_DLA_DIE);
		}
		cur_die = sib_die;
	}
	return;
}

static void read_cu_list(Dwarf_Debug dbg)
{
	Dwarf_Unsigned cu_header_length = 0;
	Dwarf_Half version_stamp = 0;
	Dwarf_Unsigned abbrev_offset = 0;
	Dwarf_Half address_size = 0;
	Dwarf_Unsigned next_cu_header = 0;
	Dwarf_Error error;
	int cu_number = 0;

	for (;; ++cu_number) {
		Dwarf_Die no_die = 0;
		Dwarf_Die cu_die = 0;
		int res = DW_DLV_ERROR;
		res = dwarf_next_cu_header(dbg, &cu_header_length,
			&version_stamp, &abbrev_offset, &address_size,
			&next_cu_header, &error);
		if (res == DW_DLV_ERROR) {
			printf("Error in dwarf_next_cu_header\n");
			exit(1);
		}
		if (res == DW_DLV_NO_ENTRY) {
			/* Done. */
			return;
		}
		/* The CU will have a single sibling, a cu_die. */
		res = dwarf_siblingof(dbg, no_die, &cu_die, &error);
		if (res == DW_DLV_ERROR) {
			printf("Error in dwarf_siblingof on CU die \n");
			exit(1);
		}
		if (res == DW_DLV_NO_ENTRY) {
			/* Impossible case. */
			printf("no entry! in dwarf_siblingof on CU die \n");
			exit(1);
		}
		get_die_and_siblings(dbg, cu_die, 0);
		dwarf_dealloc(dbg, cu_die, DW_DLA_DIE);
	}
}

int main(int argc, char** argv)
{
	Dwarf_Debug dbg = 0;
	//int fd = -1;
	FILE* fd = nullptr;


	const TCHAR* filepath = TEXT("hello_print.exe");
	int res = DW_DLV_ERROR;
	Dwarf_Error err;
	Dwarf_Handler errhandler = 0;
	Dwarf_Ptr errarg = 0;
	HANDLE hFile = NULL;

	// open the file
	hFile = CreateFile(filepath, GENERIC_READ,
		FILE_SHARE_READ, NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		0);

	res = dwarf_pe_init(hFile, filepath, errhandler, errarg, &dbg, &err);
	if (res != DW_DLV_OK) {
		printf("Could not process DWARF symbols\n");
		exit(1);
	}

	read_cu_list(dbg);
	res = dwarf_pe_finish(dbg, &err);
	if (res != DW_DLV_OK) {
		printf("Dwarf finish failed\n");
	}

	CloseHandle(hFile);
	getchar();
	return 0;
}

