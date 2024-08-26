.global _main
.align 4

_main:
	sub sp, sp, #16
	mov wzr, [sp, #12]
	mov w8, #6
	str [sp, #12]
