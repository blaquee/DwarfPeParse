#ifndef _PCH_H
#define _PCH_H

#include <windows.h>
#include <tchar.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <libdwarf/dwarf_incl.h>
#include "dwarf_pe_helper.h"


#ifdef __cplusplus
extern "C"
{
#endif

	int dwarf_pe_init(HANDLE hFile, const TCHAR* tcFilePath, Dwarf_Handler errHandler,
		Dwarf_Ptr errArg, Dwarf_Debug *retDbg, Dwarf_Error *dwErr);

	int dwarf_pe_finish(Dwarf_Debug dbg, Dwarf_Error *err);

#ifdef __cplusplus
}
#endif


#endif
