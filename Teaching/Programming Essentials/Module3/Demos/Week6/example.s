	.att_syntax
	.file	"example.c"
	.text
	.globl	add_two_nums                    # -- Begin function add_two_nums
	.prefalign	4, .Lfunc_end0, nop
	.type	add_two_nums,@function
add_two_nums:                           # @add_two_nums
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %edi
	addl	$1, %edi
	movl	-8(%rbp), %esi
	addl	$1, %esi
	callq	add_two_nums
	addq	$16, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	add_two_nums, .Lfunc_end0-add_two_nums
	.cfi_endproc
                                        # -- End function
	.globl	main                            # -- Begin function main
	.prefalign	4, .Lfunc_end1, nop
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movl	$1, %edi
	movl	$2, %esi
	callq	add_two_nums
	movl	%eax, -8(%rbp)
	movl	$3, %edi
	movl	$5, %esi
	callq	add_two_nums
	movl	%eax, -12(%rbp)
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.ident	"clang version 23.1.1"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym add_two_nums
