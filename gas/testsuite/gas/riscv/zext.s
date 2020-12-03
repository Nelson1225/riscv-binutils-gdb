target:
	zext.b	a0, a1
	zext.h	a0, a1

.ifdef __64_bit__
	zext.w  a0, a1
	sext.w  a0, a1
.endif
