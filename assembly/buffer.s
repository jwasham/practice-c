	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	calll	L0$pb
L0$pb:
	popl	%eax
	movl	L___stack_chk_guard$non_lazy_ptr-L0$pb(%eax), %eax
	movl	(%eax), %ecx
	movl	%ecx, -4(%ebp)
	movl	$0, -48(%ebp)
	movb	$10, -44(%ebp)
	movb	$13, -41(%ebp)
	movb	$42, -5(%ebp)
	movl	(%eax), %eax
	cmpl	-4(%ebp), %eax
	jne	LBB0_2
## BB#1:                                ## %SP_return
	movl	$725005, %eax           ## imm = 0xB100D
	addl	$56, %esp
	popl	%ebp
	retl
LBB0_2:                                 ## %CallStackCheckFailBlk
	calll	___stack_chk_fail


	.section	__IMPORT,__pointers,non_lazy_symbol_pointers
L___stack_chk_guard$non_lazy_ptr:
	.indirect_symbol	___stack_chk_guard
	.long	0

.subsections_via_symbols
