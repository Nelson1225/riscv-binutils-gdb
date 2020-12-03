#as: -march=rv32ib
#source: zext.s
#objdump: -d

.*:[ 	]+file format .*


Disassembly of section .text:

0+000 <target>:
[ 	]+0:[ 	]+0ff5f513[ 	]+zext.b[ 	]+a0,a1
[ 	]+4:[ 	]+0805c533[ 	]+zext.h[ 	]+a0,a1
