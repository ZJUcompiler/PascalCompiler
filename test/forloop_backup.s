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
	subl	$8, %esp
	movl	$0, %eax
	movl	%ebp, %edx
	movl	%eax, -8(%edx)
    leal    -8(%edx), %eax
    pushl   %eax
    subl    $4, %esp
    call    _read_int
	movl	%ebp, %edx
	movl	$1, %eax
	movl	%ebp, %edx
	movl	%eax, -4(%edx)
_$JMP$_L0:
	movl	$10, %eax
	movl	%ebp, %edx
	movl	-4(%edx), %ebx
	cmpl	%ebx, %eax
	setl	%al
	movzbl	%al, %edi
	movl	$0, %eax
	cmpl	%edi, %eax
	sete	%al
	movzbl	%al, %edi
	movl	$1, %eax
	movl	%ebp, %edx
	movl	-4(%edx), %ecx
	addl	%eax, %ecx
	movl	%ebp, %edx
	movl	%ecx, -4(%edx)
	cmpl	$0, %edi
	je	_$JMP$_L1
	movl	$1, %eax
	movl	%ebp, %edx
	movl	-8(%edx), %edi
	addl	%eax, %edi
	movl	%ebp, %edx
	movl	%edi, -8(%edx)
    movl    $_$CONST$_L1, %eax
    pushl   %eax
    pushl   %ebp
    call    _write_string
    pushl   %edi
    pushl   %ebp
    call    _writeln_int
	jmp	_$JMP$_L0
_$JMP$_L1:
	leave
	ret
.LFE0:
	.size	main, .-main

.section	.rodata
_$CONST$_L1:
    .string "r = "
.ident	"PasC v1.0"
.section	.node.GNU-stack,"",@progbits
