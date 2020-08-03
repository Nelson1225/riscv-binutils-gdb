#name: Link shared ifunc resolver with ifunc-caller-pcrel (pic)
#source: ifunc-caller-pcrel.s
#as:
#ld: -z nocombreloc -pie tmpdir/ifunc-resolver.so
#error: .*unresolvable R_RISCV_PCREL_HI20 relocation.*
