#name: Link shared ifunc resolver with ifunc-caller (pic)
#source: ifunc-caller.s
#as:
#ld: -z nocombreloc -shared tmpdir/ifunc-resolver.so
#readelf: -rW

Relocation section '.rela.data' at .*
[ ]+Offset[ ]+Info[ ]+Type[ ]+.*
[0-9a-f]+[ 	]+[0-9a-f]+[ 	]+R_RISCV_(32|64)[ 	]+[0-9a-f]+[ 	]+foo \+ 0
#...
Relocation section '.rela.got' at .*
[ ]+Offset[ ]+Info[ ]+Type[ ]+.*
[0-9a-f]+[ 	]+[0-9a-f]+[ 	]+R_RISCV_(32|64)[ 	]+[0-9a-f]+[ 	]+foo \+ 0
#...
Relocation section '.rela.plt' at .*
[ ]+Offset[ ]+Info[ ]+Type[ ]+.*
[0-9a-f]+[ 	]+[0-9a-f]+[ 	]+R_RISCV_JUMP_SLOT[ 	]+[0-9a-f]+[ 	]+foo \+ 0
