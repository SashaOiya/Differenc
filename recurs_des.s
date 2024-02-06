	.file	"recurs_des.cpp"
	.section	.text$_ZN10Position_tC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10Position_tC1Ev
	.def	__ZN10Position_tC1Ev;	.scl	2;	.type	32;	.endef
__ZN10Position_tC1Ev:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	$0, (%eax)
	movl	-4(%ebp), %eax
	movl	$0, 4(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.text
	.globl	__Z11Get_GeneralPcP6Node_t
	.def	__Z11Get_GeneralPcP6Node_t;	.scl	2;	.type	32;	.endef
__Z11Get_GeneralPcP6Node_t:
LFB8:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA8
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -20(%ebp)
	movl	$0, -16(%ebp)
	leal	-20(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN10Position_tC1Ev
	movl	8(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	$0, -16(%ebp)
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
LEHB0:
	call	__Z14Get_ExpressionP10Position_t
LEHE0:
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp	L6
L5:
	movl	%eax, (%esp)
LEHB1:
	call	__Unwind_Resume
LEHE1:
L6:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA8:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE8-LLSDACSB8
LLSDACSB8:
	.uleb128 LEHB0-LFB8
	.uleb128 LEHE0-LEHB0
	.uleb128 L5-LFB8
	.uleb128 0
	.uleb128 LEHB1-LFB8
	.uleb128 LEHE1-LEHB1
	.uleb128 0
	.uleb128 0
LLSDACSE8:
	.text
	.section .rdata,"dr"
LC0:
	.ascii "recurs_des.cpp\0"
LC1:
	.ascii "position->index > prev_index\0"
	.text
	.globl	__Z10Get_NumberP10Position_t
	.def	__Z10Get_NumberP10Position_t;	.scl	2;	.type	32;	.endef
__Z10Get_NumberP10Position_t:
LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -16(%ebp)
	jmp	L8
L9:
	movl	-12(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %ecx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	addl	%edx, %eax
	subl	$48, %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%eax)
L8:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	L9
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-16(%ebp), %eax
	jg	L10
	movl	$24, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	__assert
L10:
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$1, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE12:
	.section .rdata,"dr"
LC2:
	.ascii "%c\0"
LC3:
	.ascii "sin\0"
LC4:
	.ascii "cos\0"
LC5:
	.ascii "tg\0"
LC6:
	.ascii "ctg\0"
	.text
	.globl	__Z9Get_IndexP10Position_t
	.def	__Z9Get_IndexP10Position_t;	.scl	2;	.type	32;	.endef
__Z9Get_IndexP10Position_t:
LFB13:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA13
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	$0, -40(%ebp)
	movl	$0, -36(%ebp)
	movl	$0, -32(%ebp)
	movl	$0, -28(%ebp)
	movl	$0, -24(%ebp)
	movl	$0, -12(%ebp)
	jmp	L13
L14:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	-12(%ebp), %edx
	leal	-40(%ebp), %ecx
	addl	%ecx, %edx
	movl	%eax, 8(%esp)
	movl	$LC2, 4(%esp)
	movl	%edx, (%esp)
	call	_sprintf
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%eax)
	addl	$1, -12(%ebp)
L13:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, (%esp)
	call	_isalpha
	testl	%eax, %eax
	jne	L14
	movl	$0, -16(%ebp)
	movl	$LC3, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L15
	movl	$115, -16(%ebp)
	jmp	L16
L15:
	movl	$LC4, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L17
	movl	$99, -16(%ebp)
	jmp	L16
L17:
	movl	$LC5, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L18
	movl	$116, -16(%ebp)
	jmp	L16
L18:
	movl	$LC6, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L16
	movl	$103, -16(%ebp)
L16:
	cmpl	$115, -16(%ebp)
	je	L19
	cmpl	$99, -16(%ebp)
	je	L19
	cmpl	$116, -16(%ebp)
	je	L19
	cmpl	$103, -16(%ebp)
	jne	L20
L19:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB2:
	call	__Z14Get_ExpressionP10Position_t
	movl	%eax, -20(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	-20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$0, 8(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	jmp	L25
L20:
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	movl	$120, 4(%esp)
	movl	$3, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
LEHE2:
	jmp	L25
L24:
	movl	%eax, (%esp)
LEHB3:
	call	__Unwind_Resume
LEHE3:
L25:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.section	.gcc_except_table,"w"
LLSDA13:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE13-LLSDACSB13
LLSDACSB13:
	.uleb128 LEHB2-LFB13
	.uleb128 LEHE2-LEHB2
	.uleb128 L24-LFB13
	.uleb128 0
	.uleb128 LEHB3-LFB13
	.uleb128 LEHE3-LEHB3
	.uleb128 0
	.uleb128 0
LLSDACSE13:
	.text
	.section .rdata,"dr"
LC7:
	.ascii "Error\0"
	.text
	.globl	__Z14Get_ExpressionP10Position_t
	.def	__Z14Get_ExpressionP10Position_t;	.scl	2;	.type	32;	.endef
__Z14Get_ExpressionP10Position_t:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z8Get_TermP10Position_t
	movl	%eax, -12(%ebp)
	jmp	L27
L31:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, -16(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z8Get_TermP10Position_t
	movl	%eax, -20(%ebp)
	movl	-16(%ebp), %eax
	cmpl	$43, %eax
	je	L29
	cmpl	$45, %eax
	je	L30
	jmp	L33
L29:
	movl	-20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$43, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, -12(%ebp)
	jmp	L27
L30:
	movl	-20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$45, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, -12(%ebp)
	jmp	L27
L33:
	movl	$LC7, (%esp)
	call	_printf
	nop
L27:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$43, %al
	je	L31
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$45, %al
	je	L31
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.globl	__Z8Get_TermP10Position_t
	.def	__Z8Get_TermP10Position_t;	.scl	2;	.type	32;	.endef
__Z8Get_TermP10Position_t:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z14Get_PartititonP10Position_t
	movl	%eax, -12(%ebp)
	jmp	L35
L39:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -13(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z14Get_PartititonP10Position_t
	movl	%eax, -20(%ebp)
	movsbl	-13(%ebp), %eax
	cmpl	$42, %eax
	je	L37
	cmpl	$47, %eax
	je	L38
	jmp	L41
L37:
	movl	-20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$42, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, -12(%ebp)
	jmp	L35
L38:
	movl	-20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$47, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, -12(%ebp)
	jmp	L35
L41:
	movl	$LC7, (%esp)
	call	_printf
	nop
L35:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$42, %al
	je	L39
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$47, %al
	je	L39
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE15:
	.globl	__Z14Get_PartititonP10Position_t
	.def	__Z14Get_PartititonP10Position_t;	.scl	2;	.type	32;	.endef
__Z14Get_PartititonP10Position_t:
LFB16:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$40, %al
	jne	L43
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z14Get_ExpressionP10Position_t
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	-12(%ebp), %eax
	jmp	L44
L43:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, (%esp)
	call	_isalpha
	testl	%eax, %eax
	je	L45
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z9Get_IndexP10Position_t
	jmp	L44
L45:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10Get_NumberP10Position_t
L44:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE16:
	.ident	"GCC: (GNU) 4.8.1"
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__assert;	.scl	2;	.type	32;	.endef
	.def	__Z11Create_Node11Node_Type_tiP6Node_tS1_;	.scl	2;	.type	32;	.endef
	.def	_sprintf;	.scl	2;	.type	32;	.endef
	.def	_isalpha;	.scl	2;	.type	32;	.endef
	.def	_strcmp;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
