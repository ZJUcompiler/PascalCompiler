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
	subl	$21, %esp
	movl	$2, %eax
	movl	%ebp, %edx
	movl	%eax, -4(%edx)
	movl	$5, %eax
	movl	%ebp, %edx
	movl	%eax, -8(%edx)
	movl	$1080033280, %eax
	movl	%ebp, %edx
	movl	%eax, -13(%edx)
	movl	$1082759578, %eax
	movl	%ebp, %edx
	movl	%eax, -17(%edx)
	movl	$1082759578, %eax
	movl	%ebp, %edx
	movl	%eax, -21(%edx)
	movl	%ebp, %edx
	movl	-21(%edx), %eax
	pushl	%eax
	movl	%ebp, %edx
	movl	-17(%edx), %eax
	pushl	%eax
	flds	0(%esp)
	flds	4(%esp)
	fxch	%st(1)
	fucomip	%st(1), %st
	fstp	%st(0)
	seta	%al
	movzbl	%al, %edi
	addl	$8, %esp
	movl	$0, %eax
	cmpl	%edi, %eax
	sete	%al
	movzbl	%al, %edi
	movl	%ebp, %edx
	movl	%edi, %eax
	movb	%al, -9(%edx)
	movl	%ebp, %edx
	movb	-9(%edx), %al
	movzbl	%al, %eax
	pushl	%eax
	subl	$4, %esp
	call	_writeln_int
	movl	%ebp, %edx
	movl	-21(%edx), %eax
	pushl	%eax
	movl	%ebp, %edx
	movl	-17(%edx), %eax
	pushl	%eax
	flds	0(%esp)
	flds	4(%esp)
	fxch	%st(1)
	fucomip	%st(1), %st
	fstp	%st(0)
	seta	%al
	movzbl	%al, %edi
	addl	$8, %esp
	movl	%ebp, %edx
	movl	%edi, %eax
	movb	%al, -9(%edx)
	movl	%ebp, %edx
	movb	-9(%edx), %al
	movzbl	%al, %eax
	pushl	%eax
	subl	$4, %esp
	call	_writeln_int
	movl	%ebp, %edx
	movl	-17(%edx), %eax
	pushl	%eax
	movl	%ebp, %edx
	movl	-21(%edx), %eax
	pushl	%eax
	flds	0(%esp)
	flds	4(%esp)
	fxch	%st(1)
	fucomip	%st(1), %st
	fstp	%st(0)
	seta	%al
	movzbl	%al, %edi
	addl	$8, %esp
	movl	%ebp, %edx
	movl	%edi, %eax
	movb	%al, -9(%edx)
	movl	%ebp, %edx
	movb	-9(%edx), %al
	movzbl	%al, %eax
	pushl	%eax
	subl	$4, %esp
	call	_writeln_int
	movl	%ebp, %edx
	movl	-21(%edx), %eax
	pushl	%eax
	movl	%ebp, %edx
	movl	-17(%edx), %eax
	pushl	%eax
	flds	0(%esp)
	flds	4(%esp)
	fxch	%st(1)
	fucomip	%st(1), %st
	fstp	%st(0)
	setnp	%dl
	movl	$0, %eax
	flds	0(%esp)
	flds	4(%esp)
	fxch	%st(1)
	fucomip	%st(1), %st
	fstp	%st(0)
	cmove	%edx, %eax
	movzbl	%al, %edi
	addl	$8, %esp
	movl	%ebp, %edx
	movl	%edi, %eax
	movb	%al, -9(%edx)
	movl	%ebp, %edx
	movb	-9(%edx), %al
	movzbl	%al, %eax
	pushl	%eax
	subl	$4, %esp
	call	_writeln_int
	movl	%ebp, %edx
	movl	-17(%edx), %eax
	pushl	%eax
	movl	%ebp, %edx
	movl	-21(%edx), %eax
	pushl	%eax
	flds	0(%esp)
	flds	4(%esp)
	fxch	%st(1)
	fucomip	%st(1), %st
	fstp	%st(0)
	seta	%al
	movzbl	%al, %edi
	addl	$8, %esp
	movl	$0, %eax
	cmpl	%edi, %eax
	sete	%al
	movzbl	%al, %edi
	movl	%ebp, %edx
	movl	%edi, %eax
	movb	%al, -9(%edx)
	movl	%ebp, %edx
	movb	-9(%edx), %al
	movzbl	%al, %eax
	pushl	%eax
	subl	$4, %esp
	call	_writeln_int
	leave
	ret
.LFE0:
	.size	main, .-main

.section	.rodata
.ident	"PasC v1.0"
.section	.node.GNU-stack,"",@progbits
