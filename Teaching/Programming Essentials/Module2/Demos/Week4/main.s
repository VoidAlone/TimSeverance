	.att_syntax
	.file	"main.c"
	.text
	.globl	main                            # -- Begin function main
	.prefalign	4, .Lfunc_end0, nop
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
	movl	$0, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)                 # 4-byte Spill
	subl	$1, %eax
	je	.LBB0_1
	jmp	.LBB0_5
.LBB0_5:
	movl	-12(%rbp), %eax                 # 4-byte Reload
	subl	$2, %eax
	je	.LBB0_2
	jmp	.LBB0_3
.LBB0_1:
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	.LBB0_4
.LBB0_2:
	movl	-8(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -8(%rbp)
.LBB0_3:
	leaq	.L.str(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
.LBB0_4:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"x is something"
	.size	.L.str, 15

	.ident	"clang version 23.1.0"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym printf
