#as: -march=rv32ib
#source: zext.s
#objdump: -d -Mno-aliases

.*:[ 	]+file format .*


Disassembly of section .text:

0+000 <target>:
[ 	]+0:[ 	]+0ff5f513[ 	]+andi[ 	]+a0,a1,255
[ 	]+4:[ 	]+0805c533[ 	]+pack[ 	]+a0,a1,zero
