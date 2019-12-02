# START ASM GEN
	.section	.rodata

#	.section	__DATA,__data

	.globl	_a
	.data
	.type	_a, @object
	.size	_a, 4
_a:	.long	1

	.globl	_b
	.data
	.type	_b, @object
	.size	_b, 4
_b:	.long	2


_string0:	.string	"Ok!\n"
# STRING

.meuString:
	.string "%d\n" 
	.text

# BEGIN FUN
	.globl	main
	.type	main, @function
main:
	.cfi_startproc
	pushq	%rbp
	movq	%rsp, %rbp

# PRINT
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$4, %edx
	movl	$1, %esi
	leaq	_string0(%rip), %rdi
	call	fwrite@PLT

# END FUN
	popq	%rbp
	ret
	.cfi_endproc

# FIXED
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.2.0-18ubuntu2) 7.2.0"
	.section	.note.GNU-stack,"",@progbits
