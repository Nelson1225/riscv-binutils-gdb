/* RISC-V ELF specific backend routines.
   Copyright (C) 2011-2020 Free Software Foundation, Inc.

   Contributed by Andrew Waterman (andrew@sifive.com).
   Based on MIPS target.

   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING3. If not,
   see <http://www.gnu.org/licenses/>.  */

#include "elf/common.h"
#include "elf/internal.h"

extern reloc_howto_type *
riscv_reloc_name_lookup (bfd *, const char *);

extern reloc_howto_type *
riscv_reloc_type_lookup (bfd *, bfd_reloc_code_real_type);

extern reloc_howto_type *
riscv_elf_rtype_to_howto (bfd *, unsigned int r_type);

#define RISCV_DONT_CARE_VERSION -1

/* The information of architecture attribute.  */
struct riscv_subset_t
{
  const char *name;
  int major_version;
  int minor_version;
  struct riscv_subset_t *next;
};

typedef struct riscv_subset_t riscv_subset_t;

typedef struct {
  riscv_subset_t *head;
  riscv_subset_t *tail;
} riscv_subset_list_t;

extern void
riscv_release_subset_list (riscv_subset_list_t *);

extern void
riscv_add_subset (riscv_subset_list_t *,
		  const char *,
		  int, int);

extern riscv_subset_t *
riscv_lookup_subset (const riscv_subset_list_t *,
		     const char *);

extern riscv_subset_t *
riscv_lookup_subset_version (const riscv_subset_list_t *,
			     const char *,
			     int, int);

typedef struct {
  riscv_subset_list_t *subset_list;
  void (*error_handler) (const char *,
			 ...) ATTRIBUTE_PRINTF_1;
  unsigned *xlen;
} riscv_parse_subset_t;

extern bfd_boolean
riscv_parse_subset (riscv_parse_subset_t *,
		    const char *);

extern const char *
riscv_supported_std_ext (void);

extern void
riscv_release_subset_list (riscv_subset_list_t *);

extern char *
riscv_arch_str (unsigned, const riscv_subset_list_t *);

/* ISA extension name class. E.g. "zbb" corresponds to RV_ISA_CLASS_Z,
   "xargs" corresponds to RV_ISA_CLASS_X, etc.  Order is important
   here.  */

typedef enum riscv_isa_ext_class
  {
   RV_ISA_CLASS_S,
   RV_ISA_CLASS_Z,
   RV_ISA_CLASS_X,
   RV_ISA_CLASS_UNKNOWN
  } riscv_isa_ext_class_t;

/* Classify the argument 'ext' into one of riscv_isa_ext_class_t.  */

riscv_isa_ext_class_t
riscv_get_prefix_class (const char *);

/* All information about a function elf attribute.  */
/* Use the function name to be the key of bfd_hash.  */

struct riscv_elf_func_attrs_entry
{
  /* Base hash table entry structure.  */
  struct bfd_hash_entry root;

  asymbol *asymbol;

  /* For the output bfd in linker.  */
  struct elf_link_hash_entry *h;

  /* Store all known elf attributes for the function.  */
  obj_attribute known_elf_attributes[NUM_KNOWN_OBJ_ATTRIBUTES];
};

extern struct riscv_elf_func_attrs_entry *
riscv_find_function_elf_attr_entry (bfd *, const char *);
extern void
riscv_elf_add_obj_func_attr_int (bfd *, unsigned int, unsigned int,
				 asymbol *, struct elf_link_hash_entry *);
extern void
riscv_elf_add_obj_func_attr_string (bfd *, unsigned int, const char *,
				    asymbol *, struct elf_link_hash_entry *);
extern void
riscv_elf_add_obj_func_attr_int_string (bfd *, unsigned int, unsigned int,
					const char *, asymbol *,
					struct elf_link_hash_entry *);

/* RISCV ELF private object data.  */ 

struct _bfd_riscv_elf_obj_tdata
{
  struct elf_obj_tdata root;

  /* tls_type for each local got entry.  */
  char *local_got_tls_type;

  struct bfd_hash_table function_elf_attrs_table;
};

#define _bfd_riscv_elf_tdata(abfd) \
  ((struct _bfd_riscv_elf_obj_tdata *)(abfd)->tdata.any)

#define riscv_function_attr_table(abfd) \
  (_bfd_riscv_elf_tdata(abfd)->function_elf_attrs_table)
