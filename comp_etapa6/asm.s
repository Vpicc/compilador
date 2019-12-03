# START
	.file "assembly.c"
	.text
	.data

	.globl	_a
	.data
	.type	_a, @object
	.size	_a, 4
_a:	.long	2

_vector:
	.size	_vector, 12
	.globl	_vector
	.long 1
	.long 2
	.long 3
	.globl	_x
	.data
	.type	_x, @object
	.size	_x, 1
_x:	.long	TRUE

_LC0:
		.string	"Correto\n"

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

	movl	$1, %edx
	movl	$2, %eax
	cmpl	%eax,%edx
	jl	labelTemp21
	movl	_Temp_0(%rip), %eax
	movl	%eax, _x(%rip)

	movl	_a(%rip), %edx
	movl	$2, %eax
	cmpl	%eax,%edx
	jz	labelTemp21
	jmp	Label_0
labelTemp21:
# PRINT
	leaq	_LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT


Label_0:
# END FUN
	popq	%rbp
	ret
	.cfi_endproc

# FIXED
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
