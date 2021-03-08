/* RISC-V-specific vendor support for ELF.
   Copyright (C) 2011-2021 Free Software Foundation, Inc.

   Contributed by Andrew Waterman (andrew@sifive.com).
   Based on TILE-Gx and MIPS targets.

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


static const char * const riscv_sifive_ext_strtab[] =
{
  "xsfcache", NULL
};

static const char ** const riscv_vendor_ext_strtab[] =
{
  (const char **) riscv_sifive_ext_strtab,
  NULL
};

static bfd_boolean
riscv_vendor_ext_valid_p (const char *arg)
{
  unsigned int i;
  for (i = 0; riscv_vendor_ext_strtab[i] != NULL; i++)
    if (riscv_multi_letter_ext_valid_p (arg, riscv_vendor_ext_strtab[i]))
      return TRUE;
  return FALSE;
}
