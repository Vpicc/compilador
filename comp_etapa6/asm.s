# START
	.file "assembly.c"
	.text
	.data

	.globl	_l
	.data
	.type	_l, @object
	.size	_l, 4
_l:	.long	2

_LC0:
		.string	"Tela"

_Temp_0:	.long	0

_Temp_1:	.long	0

_Temp_2:	.long	0

# STRING
.meuString:
	.string "%d\n" 
	.text

	.section	.rodata
# BEGIN FUN
	.globl	main
	.type	main, @function
main:
	.cfi_startproc
	pushq	%rbp
	movq	%rsp, %rbp


# EQUAL
	movl	_l(%rip), %eax
	cmpl	$5, %eax
	jne
# EQUAL
	movl	_l(%rip), %eax
	cmpl	$2, %eax
	jne		Label_0

# PRINT
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$4, %edx
	movl	$1, %esi
	leaq	_LC0(%rip), %rdi
	call	fwrite@PLT

# LABEL
Label_0:
# END FUN
	popq	%rbp
	ret
	.cfi_endproc

# FIXED
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
