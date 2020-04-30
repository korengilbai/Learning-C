	.file	"print_longest.c"
	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "test\0"
LC1:
	.ascii "Enter a sentence...\0"
LC2:
	.ascii "line: %s\12length: %i\0"
LC3:
	.ascii "stop\12\0"
LC4:
	.ascii "\12\12Longest line: %s\12Length: %i\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB22:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$160, %esp
	call	___main
	movl	$0, 156(%esp)
L3:
	movl	$LC0, (%esp)
	call	_puts
	movl	$LC1, (%esp)
	call	_puts
	movl	__imp___iob, %eax
	movl	%eax, 8(%esp)
	movl	$64, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_fgets
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_get_length
	movl	%eax, 152(%esp)
	movl	152(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	152(%esp), %eax
	cmpl	156(%esp), %eax
	jle	L2
	movl	152(%esp), %eax
	movl	%eax, 156(%esp)
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	leal	88(%esp), %eax
	movl	%eax, (%esp)
	call	_strcpy
L2:
	movl	$LC3, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L3
	movl	156(%esp), %eax
	movl	%eax, 8(%esp)
	leal	88(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE22:
	.section .rdata,"dr"
LC5:
	.ascii "func addr: %x\0"
	.text
	.globl	_get_length
	.def	_get_length;	.scl	2;	.type	32;	.endef
_get_length:
LFB23:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	$0, -16(%ebp)
	movl	$0, -20(%ebp)
	jmp	L6
L9:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_atoi
	testl	%eax, %eax
	je	L11
	addl	$1, -16(%ebp)
	addl	$1, -12(%ebp)
	addl	$1, -20(%ebp)
L6:
	cmpl	$63, -20(%ebp)
	jle	L9
	jmp	L8
L11:
	nop
L8:
	movl	-16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE23:
	.ident	"GCC: (MinGW.org GCC Build-20200227-1) 9.2.0"
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_fgets;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_strcpy;	.scl	2;	.type	32;	.endef
	.def	_strcmp;	.scl	2;	.type	32;	.endef
	.def	_atoi;	.scl	2;	.type	32;	.endef
