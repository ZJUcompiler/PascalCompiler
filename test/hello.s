	.file "test.pas"
###########################
#    Generated by PasC    #
###########################

.section	.text
	.globl	main
	.type	main,@function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$17, %esp
	movl	$0, %eax
	movl	%ebp, %edx
	movl	%eax, -13(%edx)
	movl	$0, %eax
	movl	%ebp, %edx
	movl	%eax, -9(%edx)
_$JMP$_L0:
	movl	$1, %eax
	movl	%ebp, %edx
	movl	-13(%edx), %edi
	addl	%eax, %edi
	movl	%ebp, %edx
	movl	%edi, -13(%edx)
	movl	$2, %eax
	movl	%ebp, %edx
	movl	-13(%edx), %ebx
	cmpl	%ebx, %eax
	setl	%al
	movzbl	%al, %edi
	cmpl	$0, %edi
	je	_$JMP$_L0
	movl	%ebp, %edx
	movl	-13(%edx), %eax
	pushl	%eax
	subl	$4, %esp
	call	_writeln_int
	addl	$8, %esp
	movl	%ebp, %edx
	movl	-13(%edx), %eax
	movl	$1, %ebx
	cmpl	%ebx, %eax
	sete	%al
	movzbl	%al, %edi
	cmpl	$0, %edi
	je	_$JMP$_L2
	movl	%ebp, %edx
	movl	-13(%edx), %eax
	movl	$2, %ebx
	cmpl	%ebx, %eax
	sete	%al
	movzbl	%al, %edi
	cmpl	$0, %edi
	je	_$JMP$_L3
	movl	%ebp, %edx
	movl	-13(%edx), %eax
	movl	$3, %ebx
	cmpl	%ebx, %eax
	sete	%al
	movzbl	%al, %edi
	cmpl	$0, %edi
	je	_$JMP$_L4
_$JMP$_L2:
	movl	$5, %eax
	movl	%ebp, %edx
	movl	-9(%edx), %edi
	addl	%eax, %edi
	movl	%ebp, %edx
	movl	%edi, -9(%edx)
	jmp	_$JMP$_L1
_$JMP$_L3:
	movl	$2, %eax
	movl	%ebp, %edx
	movl	-9(%edx), %edi
	addl	%eax, %edi
	movl	%ebp, %edx
	movl	%edi, -9(%edx)
	jmp	_$JMP$_L1
_$JMP$_L4:
	movl	$3, %eax
	movl	%ebp, %edx
	movl	-9(%edx), %edi
	addl	%eax, %edi
	movl	%ebp, %edx
	movl	%edi, -9(%edx)
	jmp	_$JMP$_L1
_$JMP$_L1:
	movl	%ebp, %edx
	movl	-9(%edx), %eax
	pushl	%eax
	subl	$4, %esp
	call	_writeln_int
	addl	$8, %esp
	movl	$1, %eax
	movl	$1, %eax
	andl	%eax, %eax
	movl	%ebp, %edx
	movl	%edi, %eax
	movb	%al, -1(%edx)
	leave
	ret
.LFE0:
	.size	main, .-main

	.globl	 ff
	.type	 ff,@function
ff:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$0, %esp
	movl	$2, %eax
	movl	%ebp, %edx
	movl	%eax, 12(%edx)
	leave
	ret
.LFE1:
	.size	ff, .-ff

	.globl	 func
	.type	 func,@function
func:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$0, %esp
	movl	$97, %eax
	movl	%ebp, %edx
	movl	%eax, %eax
	movb	%al, 9(%edx)
	leave
	ret
.LFE2:
	.size	func, .-func

.section	.rodata
.ident	"PasC v1.0"
.section	.node.GNU-stack,"",@progbits
