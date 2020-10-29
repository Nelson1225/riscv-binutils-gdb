	.option norvc
target:
	flh	fa0, 0x10(a1)
	flh	fa0, %lo (target)(a1)
	flh	fa0, target, a1

	flw	fa0, 0x10(a1)
	flw	fa0, %lo (target)(a1)
	flw	fa0, target, a1

.ifdef __64_bit__
	fld	fa0, 0x10(a1)
	fld	fa0, %lo (target)(a1)
	fld	fa0, target, a1

	flq	fa0, 0x10(a1)
	flq	fa0, %lo (target)(a1)
.endif

	.option rvc
	flw	fa0, 0x10(a1)
	flw	fa0, 0x10(sp)
.ifdef __64_bit__
	fld	fa0, 0x10(a1)
	fld	fa0, 0x10(sp)
.endif
