# DwarfPeParse
Dwarf Lib for PE files, compiles with VIsual Studio

This is a Work in Progress base for a library that supports processing Dwarf Symbols from PE files, to work for debuggers and other related software

**DwarfPeParse** project includes the libdwarf and libelf code base with some fixes to compile on visual studio (tested on Visual Studio 2017)

**DwarfGenNames** is just a project using the gennames.c code from the libdwarf library to automatically generates helper functions in the:
* dwarf_names.c/h
* dwarf_names_enum and dwarf_names_new.h files.

DwarfGenNames doesn't need to be ran since these files are already included in the DwarfPeParse project. Run it only if an update to the dwarf.h header file occurs.

This project actually uses the libdwarf revised in 2015, but changelog files show 2008 (the files are copied from the drmingw project)


Thanks to some of the work from these projects:
* https://github.com/WolfgangSt/libdwarf
* https://github.com/jrfonseca/drmingw
