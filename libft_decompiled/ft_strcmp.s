	.text
	.intel_syntax noprefix
	.file	"ft_strcmp.c"
	.globl	ft_strcmp                       # -- Begin function ft_strcmp
	.p2align	4, 0x90
	.type	ft_strcmp,@function
ft_strcmp:                              # @ft_strcmp
	.cfi_startproc
# %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 8], rdi
	mov	qword ptr [rbp - 16], rsi
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	mov	rax, qword ptr [rbp - 8]
	movsx	ecx, byte ptr [rax]
	xor	eax, eax
                                        # kill: def $al killed $al killed $eax
	cmp	ecx, 0
	mov	byte ptr [rbp - 17], al         # 1-byte Spill
	je	.LBB0_3
# %bb.2:                                #   in Loop: Header=BB0_1 Depth=1
	mov	rax, qword ptr [rbp - 8]
	mov	rcx, rax
	add	rcx, 1
	mov	qword ptr [rbp - 8], rcx
	movsx	eax, byte ptr [rax]
	mov	rcx, qword ptr [rbp - 16]
	mov	rdx, rcx
	add	rdx, 1
	mov	qword ptr [rbp - 16], rdx
	movsx	ecx, byte ptr [rcx]
	cmp	eax, ecx
	setne	al
	mov	byte ptr [rbp - 17], al         # 1-byte Spill
.LBB0_3:                                #   in Loop: Header=BB0_1 Depth=1
	mov	al, byte ptr [rbp - 17]         # 1-byte Reload
	test	al, 1
	jne	.LBB0_4
	jmp	.LBB0_5
.LBB0_4:                                #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_1
.LBB0_5:
	mov	rax, qword ptr [rbp - 8]
	movsx	eax, byte ptr [rax]
	mov	rcx, qword ptr [rbp - 16]
	movsx	ecx, byte ptr [rcx]
	sub	eax, ecx
	pop	rbp
	.cfi_def_cfa rsp, 8
	ret
.Lfunc_end0:
	.size	ft_strcmp, .Lfunc_end0-ft_strcmp
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 18.1.3 (1ubuntu1)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
