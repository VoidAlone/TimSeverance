	.att_syntax
	.file	"ex2.c"
	.text
	.globl	counter                         # -- Begin function counter
	.prefalign	4, .Lfunc_end0, nop
	.type	counter,@function
counter:                                # @counter
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	$1, asdf(%rip)
	movl	asdf(%rip), %eax
	addl	$1, %eax
	movl	%eax, asdf(%rip)
	movl	asdf(%rip), %esi
	leaq	.L.str(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	counter, .Lfunc_end0-counter
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
	callq	counter
	callq	counter
	callq	counter
	xorl	%eax, %eax
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	asdf,@object                    # @asdf
	.local	asdf
	.comm	asdf,4,4
	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Counter is: %d"
	.size	.L.str, 15

	.ident	"clang version 23.1.1"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym counter
	.addrsig_sym printf
	.addrsig_sym asdf
