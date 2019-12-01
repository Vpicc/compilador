# START
	.file "assembly.c"
	.text
	.data

_ve:
	.globl _ve
	.long 7
	.long 6
_LC0:
		.string	"A=17\n"

_Temp_0:	.long	0

_Temp_1:	.long	0

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


# VECTOR ASS
	movb	$5, 0+_ve(%rip)

# VEC READ
	movl	0+_ve(%rip), %eax
	movl %eax,  _Temp_0(%rip)

# EQUAL
	movl	_Temp_0(%rip), %eax
	cmpl	$5, %eax
	jne	Label_0

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
