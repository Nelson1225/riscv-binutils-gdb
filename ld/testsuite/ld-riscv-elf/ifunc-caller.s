	.text

	# Call the ifunc `foo` which is defined in the other modules.
	.globl	foo
	.type	foo, %function

	.globl	main
	.type	main, @function
main:
.L1:
	auipc	x1, %got_pcrel_hi (foo)
.ifdef __64_bit__
	ld	x1, %pcrel_lo (.L1) (x1)
.else
	lw	x1, %pcrel_lo (.L1) (x1)
.endif

.L2:
	auipc	x2, %pcrel_hi (foo_addr)
.ifdef __64_bit__
	ld	x2, %pcrel_lo (.L2) (x2)
.else
	lw	x2, %pcrel_lo (.L2) (x2)
.endif

	call	foo
	call	foo@plt

	ret
	.size	main, .-main

	.data
foo_addr:
.ifdef __64_bit__
	.quad	foo
.else
	.long	foo
.endif
