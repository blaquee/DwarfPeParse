/* Generated routines, do not edit. */
/* Generated on Jun 19 2018  14:33:00 */

/* BEGIN FILE */

#include "dwarf.h"

#include "libdwarf.h"

/* ARGSUSED */
int
dwarf_get_TAG_name (unsigned int val,const char ** s_out)
{
    switch (val) {
    case DW_TAG_array_type:
        *s_out = "DW_TAG_array_type";
        return DW_DLV_OK;
    case DW_TAG_class_type:
        *s_out = "DW_TAG_class_type";
        return DW_DLV_OK;
    case DW_TAG_entry_point:
        *s_out = "DW_TAG_entry_point";
        return DW_DLV_OK;
    case DW_TAG_enumeration_type:
        *s_out = "DW_TAG_enumeration_type";
        return DW_DLV_OK;
    case DW_TAG_formal_parameter:
        *s_out = "DW_TAG_formal_parameter";
        return DW_DLV_OK;
    case DW_TAG_imported_declaration:
        *s_out = "DW_TAG_imported_declaration";
        return DW_DLV_OK;
    case DW_TAG_label:
        *s_out = "DW_TAG_label";
        return DW_DLV_OK;
    case DW_TAG_lexical_block:
        *s_out = "DW_TAG_lexical_block";
        return DW_DLV_OK;
    case DW_TAG_member:
        *s_out = "DW_TAG_member";
        return DW_DLV_OK;
    case DW_TAG_pointer_type:
        *s_out = "DW_TAG_pointer_type";
        return DW_DLV_OK;
    case DW_TAG_reference_type:
        *s_out = "DW_TAG_reference_type";
        return DW_DLV_OK;
    case DW_TAG_compile_unit:
        *s_out = "DW_TAG_compile_unit";
        return DW_DLV_OK;
    case DW_TAG_string_type:
        *s_out = "DW_TAG_string_type";
        return DW_DLV_OK;
    case DW_TAG_structure_type:
        *s_out = "DW_TAG_structure_type";
        return DW_DLV_OK;
    case DW_TAG_subroutine_type:
        *s_out = "DW_TAG_subroutine_type";
        return DW_DLV_OK;
    case DW_TAG_typedef:
        *s_out = "DW_TAG_typedef";
        return DW_DLV_OK;
    case DW_TAG_union_type:
        *s_out = "DW_TAG_union_type";
        return DW_DLV_OK;
    case DW_TAG_unspecified_parameters:
        *s_out = "DW_TAG_unspecified_parameters";
        return DW_DLV_OK;
    case DW_TAG_variant:
        *s_out = "DW_TAG_variant";
        return DW_DLV_OK;
    case DW_TAG_common_block:
        *s_out = "DW_TAG_common_block";
        return DW_DLV_OK;
    case DW_TAG_common_inclusion:
        *s_out = "DW_TAG_common_inclusion";
        return DW_DLV_OK;
    case DW_TAG_inheritance:
        *s_out = "DW_TAG_inheritance";
        return DW_DLV_OK;
    case DW_TAG_inlined_subroutine:
        *s_out = "DW_TAG_inlined_subroutine";
        return DW_DLV_OK;
    case DW_TAG_module:
        *s_out = "DW_TAG_module";
        return DW_DLV_OK;
    case DW_TAG_ptr_to_member_type:
        *s_out = "DW_TAG_ptr_to_member_type";
        return DW_DLV_OK;
    case DW_TAG_set_type:
        *s_out = "DW_TAG_set_type";
        return DW_DLV_OK;
    case DW_TAG_subrange_type:
        *s_out = "DW_TAG_subrange_type";
        return DW_DLV_OK;
    case DW_TAG_with_stmt:
        *s_out = "DW_TAG_with_stmt";
        return DW_DLV_OK;
    case DW_TAG_access_declaration:
        *s_out = "DW_TAG_access_declaration";
        return DW_DLV_OK;
    case DW_TAG_base_type:
        *s_out = "DW_TAG_base_type";
        return DW_DLV_OK;
    case DW_TAG_catch_block:
        *s_out = "DW_TAG_catch_block";
        return DW_DLV_OK;
    case DW_TAG_const_type:
        *s_out = "DW_TAG_const_type";
        return DW_DLV_OK;
    case DW_TAG_constant:
        *s_out = "DW_TAG_constant";
        return DW_DLV_OK;
    case DW_TAG_enumerator:
        *s_out = "DW_TAG_enumerator";
        return DW_DLV_OK;
    case DW_TAG_file_type:
        *s_out = "DW_TAG_file_type";
        return DW_DLV_OK;
    case DW_TAG_friend:
        *s_out = "DW_TAG_friend";
        return DW_DLV_OK;
    case DW_TAG_namelist:
        *s_out = "DW_TAG_namelist";
        return DW_DLV_OK;
    case DW_TAG_namelist_items:
        *s_out = "DW_TAG_namelist_items";
        return DW_DLV_OK;
    case DW_TAG_packed_type:
        *s_out = "DW_TAG_packed_type";
        return DW_DLV_OK;
    case DW_TAG_subprogram:
        *s_out = "DW_TAG_subprogram";
        return DW_DLV_OK;
    case DW_TAG_template_type_parameter:
        *s_out = "DW_TAG_template_type_parameter";
        return DW_DLV_OK;
    case DW_TAG_template_value_param:
        *s_out = "DW_TAG_template_value_param";
        return DW_DLV_OK;
    case DW_TAG_thrown_type:
        *s_out = "DW_TAG_thrown_type";
        return DW_DLV_OK;
    case DW_TAG_try_block:
        *s_out = "DW_TAG_try_block";
        return DW_DLV_OK;
    case DW_TAG_variant_part:
        *s_out = "DW_TAG_variant_part";
        return DW_DLV_OK;
    case DW_TAG_variable:
        *s_out = "DW_TAG_variable";
        return DW_DLV_OK;
    case DW_TAG_volatile_type:
        *s_out = "DW_TAG_volatile_type";
        return DW_DLV_OK;
    case DW_TAG_dwarf_procedure:
        *s_out = "DW_TAG_dwarf_procedure";
        return DW_DLV_OK;
    case DW_TAG_restrict_type:
        *s_out = "DW_TAG_restrict_type";
        return DW_DLV_OK;
    case DW_TAG_interface_type:
        *s_out = "DW_TAG_interface_type";
        return DW_DLV_OK;
    case DW_TAG_namespace:
        *s_out = "DW_TAG_namespace";
        return DW_DLV_OK;
    case DW_TAG_imported_module:
        *s_out = "DW_TAG_imported_module";
        return DW_DLV_OK;
    case DW_TAG_unspecified_type:
        *s_out = "DW_TAG_unspecified_type";
        return DW_DLV_OK;
    case DW_TAG_partial_unit:
        *s_out = "DW_TAG_partial_unit";
        return DW_DLV_OK;
    case DW_TAG_imported_unit:
        *s_out = "DW_TAG_imported_unit";
        return DW_DLV_OK;
    case DW_TAG_mutable_type:
        *s_out = "DW_TAG_mutable_type";
        return DW_DLV_OK;
    case DW_TAG_condition:
        *s_out = "DW_TAG_condition";
        return DW_DLV_OK;
    case DW_TAG_shared_type:
        *s_out = "DW_TAG_shared_type";
        return DW_DLV_OK;
    case DW_TAG_type_unit:
        *s_out = "DW_TAG_type_unit";
        return DW_DLV_OK;
    case DW_TAG_rvalue_reference_type:
        *s_out = "DW_TAG_rvalue_reference_type";
        return DW_DLV_OK;
    case DW_TAG_template_alias:
        *s_out = "DW_TAG_template_alias";
        return DW_DLV_OK;
    case DW_TAG_coarray_type:
        *s_out = "DW_TAG_coarray_type";
        return DW_DLV_OK;
    case DW_TAG_generic_subrange:
        *s_out = "DW_TAG_generic_subrange";
        return DW_DLV_OK;
    case DW_TAG_dynamic_type:
        *s_out = "DW_TAG_dynamic_type";
        return DW_DLV_OK;
    case DW_TAG_atomic_type:
        *s_out = "DW_TAG_atomic_type";
        return DW_DLV_OK;
    case DW_TAG_call_site:
        *s_out = "DW_TAG_call_site";
        return DW_DLV_OK;
    case DW_TAG_call_site_parameter:
        *s_out = "DW_TAG_call_site_parameter";
        return DW_DLV_OK;
    case DW_TAG_lo_user:
        *s_out = "DW_TAG_lo_user";
        return DW_DLV_OK;
    case DW_TAG_MIPS_loop:
        *s_out = "DW_TAG_MIPS_loop";
        return DW_DLV_OK;
    case DW_TAG_HP_array_descriptor:
        *s_out = "DW_TAG_HP_array_descriptor";
        return DW_DLV_OK;
    case DW_TAG_format_label:
        *s_out = "DW_TAG_format_label";
        return DW_DLV_OK;
    case DW_TAG_function_template:
        *s_out = "DW_TAG_function_template";
        return DW_DLV_OK;
    case DW_TAG_class_template:
        *s_out = "DW_TAG_class_template";
        return DW_DLV_OK;
    case DW_TAG_GNU_BINCL:
        *s_out = "DW_TAG_GNU_BINCL";
        return DW_DLV_OK;
    case DW_TAG_GNU_EINCL:
        *s_out = "DW_TAG_GNU_EINCL";
        return DW_DLV_OK;
    case DW_TAG_GNU_template_template_param:
        *s_out = "DW_TAG_GNU_template_template_param";
        return DW_DLV_OK;
    case DW_TAG_GNU_template_parameter_pack:
        *s_out = "DW_TAG_GNU_template_parameter_pack";
        return DW_DLV_OK;
    case DW_TAG_GNU_formal_parameter_pack:
        *s_out = "DW_TAG_GNU_formal_parameter_pack";
        return DW_DLV_OK;
    case DW_TAG_GNU_call_site:
        *s_out = "DW_TAG_GNU_call_site";
        return DW_DLV_OK;
    case DW_TAG_GNU_call_site_parameter:
        *s_out = "DW_TAG_GNU_call_site_parameter";
        return DW_DLV_OK;
    case DW_TAG_SUN_function_template:
        *s_out = "DW_TAG_SUN_function_template";
        return DW_DLV_OK;
    case DW_TAG_SUN_class_template:
        *s_out = "DW_TAG_SUN_class_template";
        return DW_DLV_OK;
    case DW_TAG_SUN_struct_template:
        *s_out = "DW_TAG_SUN_struct_template";
        return DW_DLV_OK;
    case DW_TAG_SUN_union_template:
        *s_out = "DW_TAG_SUN_union_template";
        return DW_DLV_OK;
    case DW_TAG_SUN_indirect_inheritance:
        *s_out = "DW_TAG_SUN_indirect_inheritance";
        return DW_DLV_OK;
    case DW_TAG_SUN_codeflags:
        *s_out = "DW_TAG_SUN_codeflags";
        return DW_DLV_OK;
    case DW_TAG_SUN_memop_info:
        *s_out = "DW_TAG_SUN_memop_info";
        return DW_DLV_OK;
    case DW_TAG_SUN_omp_child_func:
        *s_out = "DW_TAG_SUN_omp_child_func";
        return DW_DLV_OK;
    case DW_TAG_SUN_rtti_descriptor:
        *s_out = "DW_TAG_SUN_rtti_descriptor";
        return DW_DLV_OK;
    case DW_TAG_SUN_dtor_info:
        *s_out = "DW_TAG_SUN_dtor_info";
        return DW_DLV_OK;
    case DW_TAG_SUN_dtor:
        *s_out = "DW_TAG_SUN_dtor";
        return DW_DLV_OK;
    case DW_TAG_SUN_f90_interface:
        *s_out = "DW_TAG_SUN_f90_interface";
        return DW_DLV_OK;
    case DW_TAG_SUN_fortran_vax_structure:
        *s_out = "DW_TAG_SUN_fortran_vax_structure";
        return DW_DLV_OK;
    case DW_TAG_SUN_hi:
        *s_out = "DW_TAG_SUN_hi";
        return DW_DLV_OK;
    case DW_TAG_ALTIUM_circ_type:
        *s_out = "DW_TAG_ALTIUM_circ_type";
        return DW_DLV_OK;
    case DW_TAG_ALTIUM_mwa_circ_type:
        *s_out = "DW_TAG_ALTIUM_mwa_circ_type";
        return DW_DLV_OK;
    case DW_TAG_ALTIUM_rev_carry_type:
        *s_out = "DW_TAG_ALTIUM_rev_carry_type";
        return DW_DLV_OK;
    case DW_TAG_ALTIUM_rom:
        *s_out = "DW_TAG_ALTIUM_rom";
        return DW_DLV_OK;
    case DW_TAG_upc_shared_type:
        *s_out = "DW_TAG_upc_shared_type";
        return DW_DLV_OK;
    case DW_TAG_upc_strict_type:
        *s_out = "DW_TAG_upc_strict_type";
        return DW_DLV_OK;
    case DW_TAG_upc_relaxed_type:
        *s_out = "DW_TAG_upc_relaxed_type";
        return DW_DLV_OK;
    case DW_TAG_PGI_kanji_type:
        *s_out = "DW_TAG_PGI_kanji_type";
        return DW_DLV_OK;
    case DW_TAG_PGI_interface_block:
        *s_out = "DW_TAG_PGI_interface_block";
        return DW_DLV_OK;
    case DW_TAG_hi_user:
        *s_out = "DW_TAG_hi_user";
        return DW_DLV_OK;
    }
    return DW_DLV_NO_ENTRY; 
}
/* ARGSUSED */
int
dwarf_get_children_name (unsigned int val,const char ** s_out)
{
    switch (val) {
    case DW_children_no:
        *s_out = "DW_children_no";
        return DW_DLV_OK;
    case DW_children_yes:
        *s_out = "DW_children_yes";
        return DW_DLV_OK;
    }
    return DW_DLV_NO_ENTRY; 
}
/* ARGSUSED */
int
dwarf_get_FORM_name (unsigned int val,const char ** s_out)
{
    switch (val) {
    case DW_FORM_addr:
        *s_out = "DW_FORM_addr";
        return DW_DLV_OK;
    case DW_FORM_block2:
        *s_out = "DW_FORM_block2";
        return DW_DLV_OK;
    case DW_FORM_block4:
        *s_out = "DW_FORM_block4";
        return DW_DLV_OK;
    case DW_FORM_data2:
        *s_out = "DW_FORM_data2";
        return DW_DLV_OK;
    case DW_FORM_data4:
        *s_out = "DW_FORM_data4";
        return DW_DLV_OK;
    case DW_FORM_data8:
        *s_out = "DW_FORM_data8";
        return DW_DLV_OK;
    case DW_FORM_string:
        *s_out = "DW_FORM_string";
        return DW_DLV_OK;
    case DW_FORM_block:
        *s_out = "DW_FORM_block";
        return DW_DLV_OK;
    case DW_FORM_block1:
        *s_out = "DW_FORM_block1";
        return DW_DLV_OK;
    case DW_FORM_data1:
        *s_out = "DW_FORM_data1";
        return DW_DLV_OK;
    case DW_FORM_flag:
        *s_out = "DW_FORM_flag";
        return DW_DLV_OK;
    case DW_FORM_sdata:
        *s_out = "DW_FORM_sdata";
        return DW_DLV_OK;
    case DW_FORM_strp:
        *s_out = "DW_FORM_strp";
        return DW_DLV_OK;
    case DW_FORM_udata:
        *s_out = "DW_FORM_udata";
        return DW_DLV_OK;
    case DW_FORM_ref_addr:
        *s_out = "DW_FORM_ref_addr";
        return DW_DLV_OK;
    case DW_FORM_ref1:
        *s_out = "DW_FORM_ref1";
        return DW_DLV_OK;
    case DW_FORM_ref2:
        *s_out = "DW_FORM_ref2";
        return DW_DLV_OK;
    case DW_FORM_ref4:
        *s_out = "DW_FORM_ref4";
        return DW_DLV_OK;
    case DW_FORM_ref8:
        *s_out = "DW_FORM_ref8";
        return DW_DLV_OK;
    case DW_FORM_ref_udata:
        *s_out = "DW_FORM_ref_udata";
        return DW_DLV_OK;
    case DW_FORM_indirect:
        *s_out = "DW_FORM_indirect";
        return DW_DLV_OK;
    case DW_FORM_sec_offset:
        *s_out = "DW_FORM_sec_offset";
        return DW_DLV_OK;
    case DW_FORM_exprloc:
        *s_out = "DW_FORM_exprloc";
        return DW_DLV_OK;
    case DW_FORM_flag_present:
        *s_out = "DW_FORM_flag_present";
        return DW_DLV_OK;
    case DW_FORM_strx:
        *s_out = "DW_FORM_strx";
        return DW_DLV_OK;
    case DW_FORM_addrx:
        *s_out = "DW_FORM_addrx";
        return DW_DLV_OK;
    case DW_FORM_ref_sup:
        *s_out = "DW_FORM_ref_sup";
        return DW_DLV_OK;
    case DW_FORM_strp_sup:
        *s_out = "DW_FORM_strp_sup";
        return DW_DLV_OK;
    case DW_FORM_data16:
        *s_out = "DW_FORM_data16";
        return DW_DLV_OK;
    case DW_FORM_line_strp:
        *s_out = "DW_FORM_line_strp";
        return DW_DLV_OK;
    case DW_FORM_ref_sig8:
        *s_out = "DW_FORM_ref_sig8";
        return DW_DLV_OK;
    case DW_FORM_GNU_addr_index:
        *s_out = "DW_FORM_GNU_addr_index";
        return DW_DLV_OK;
    case DW_FORM_GNU_str_index:
        *s_out = "DW_FORM_GNU_str_index";
        return DW_DLV_OK;
    case DW_FORM_GNU_ref_alt:
        *s_out = "DW_FORM_GNU_ref_alt";
        return DW_DLV_OK;
    case DW_FORM_GNU_strp_alt:
        *s_out = "DW_FORM_GNU_strp_alt";
        return DW_DLV_OK;
    }
    return DW_DLV_NO_ENTRY; 
}
