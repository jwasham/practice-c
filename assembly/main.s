	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	subl	$36, %esp
	calll	L0$pb
L0$pb:
	popl	%eax
	movl	12(%ebp), %ecx
	movl	8(%ebp), %edx
	leal	L_.str-L0$pb(%eax), %eax
	movl	$24, %esi
	movl	$0, -8(%ebp)
	movl	%edx, -12(%ebp)
	movl	%ecx, -16(%ebp)
	movl	%eax, (%esp)
	movl	$24, 4(%esp)
	movl	%esi, -20(%ebp)         ## 4-byte Spill
	calll	_printf
	movl	$61453, %ecx            ## imm = 0xF00D
	movl	%eax, -24(%ebp)         ## 4-byte Spill
	movl	%ecx, %eax
	addl	$36, %esp
	popl	%esi
	popl	%ebp
	retl

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"I like the number %d.\n"


.subsections_via_symbols
