	.file	"front.cpp"
	.section	.text$feof,"x"
	.linkonce discard
	.globl	_feof
	.def	_feof;	.scl	2;	.type	32;	.endef
_feof:
LFB4:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	andl	$16, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4:
	.section	.text$ferror,"x"
	.linkonce discard
	.globl	_ferror
	.def	_ferror;	.scl	2;	.type	32;	.endef
_ferror:
LFB5:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	andl	$32, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5:
	.globl	_logfile
	.bss
	.align 4
_logfile:
	.space 4
	.section	.text$_ZN6Tree_tC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6Tree_tC1Ev
	.def	__ZN6Tree_tC1Ev;	.scl	2;	.type	32;	.endef
__ZN6Tree_tC1Ev:
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
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.section	.text$_ZN6File_tC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6File_tC1Ev
	.def	__ZN6File_tC1Ev;	.scl	2;	.type	32;	.endef
__ZN6File_tC1Ev:
LFB14:
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
	movl	-4(%ebp), %eax
	movl	$0, 8(%eax)
	movl	-4(%ebp), %eax
	movl	$0, 12(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "w\0"
LC1:
	.ascii "eval.txt\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB8:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA8
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	call	___main
	movl	$0, 36(%esp)
	leal	36(%esp), %eax
	movl	%eax, %ecx
	call	__ZN6Tree_tC1Ev
	movl	$0, 20(%esp)
	movl	$0, 24(%esp)
	movl	$0, 28(%esp)
	movl	$0, 32(%esp)
	leal	20(%esp), %eax
	movl	%eax, %ecx
	call	__ZN6File_tC1Ev
	movl	12(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	leal	36(%esp), %edx
	movl	%edx, 8(%esp)
	leal	20(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB0:
	call	__Z14Diff_Tree_CtorPcP6File_tP6Tree_t
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z15Tree_Graph_DumpPK6Node_t
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z14Tree_Text_DumpPK6Node_t
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	_fopen
	movl	%eax, 44(%esp)
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	__Z1dPK6Node_t
	movl	%eax, 40(%esp)
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	call	__Z14Tree_Text_DumpPK6Node_t
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	_fclose
	leal	36(%esp), %eax
	movl	%eax, 4(%esp)
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	__Z14Diff_Tree_DtorP6File_tP6Tree_t
LEHE0:
	movl	$0, %eax
	jmp	L11
L10:
	movl	%eax, (%esp)
LEHB1:
	call	__Unwind_Resume
LEHE1:
L11:
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
	.uleb128 L10-LFB8
	.uleb128 0
	.uleb128 LEHB1-LFB8
	.uleb128 LEHE1-LEHB1
	.uleb128 0
	.uleb128 0
LLSDACSE8:
	.text
	.section .rdata,"dr"
LC2:
	.ascii "r\0"
LC3:
	.ascii "File opening error\0"
	.align 4
LC4:
	.ascii "buffer memory allocation error\0"
	.align 4
LC5:
	.ascii "Error reading test.bin: unexpected end of file\0"
LC6:
	.ascii "Error reading test.bin\0"
	.text
	.globl	__Z11File_ReaderP6File_t
	.def	__Z11File_ReaderP6File_t;	.scl	2;	.type	32;	.endef
__Z11File_ReaderP6File_t:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	$LC2, 4(%esp)
	movl	%eax, (%esp)
	call	_fopen
	movl	8(%ebp), %edx
	movl	%eax, 4(%edx)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	testl	%eax, %eax
	jne	L13
	movl	$LC3, (%esp)
	call	_puts
	movl	$1, %eax
	jmp	L14
L13:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	__Z11GetFileSizeP6_iobuf
	movl	8(%ebp), %edx
	movl	%eax, 12(%edx)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	addl	$1, %eax
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	_calloc
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	testl	%eax, %eax
	jne	L15
	movl	$LC4, (%esp)
	call	_puts
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$1, %eax
	jmp	L14
L15:
	movl	8(%ebp), %eax
	movl	4(%eax), %ecx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	_fread
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	cmpl	-12(%ebp), %eax
	je	L16
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	_feof
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	L17
	movl	$LC5, (%esp)
	call	_puts
	jmp	L18
L17:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	_ferror
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	L18
	movl	$LC6, (%esp)
	call	_perror
L18:
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	_free
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$1, %eax
	jmp	L14
L16:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$8, %eax
L14:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE15:
	.globl	__Z11GetFileSizeP6_iobuf
	.def	__Z11GetFileSizeP6_iobuf;	.scl	2;	.type	32;	.endef
__Z11GetFileSizeP6_iobuf:
LFB16:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ftell
	movl	%eax, -12(%ebp)
	movl	$2, 8(%esp)
	movl	$0, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_fseek
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ftell
	movl	%eax, -16(%ebp)
	movl	$0, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_fseek
	movl	-16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE16:
	.globl	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	.def	__Z11Create_Node11Node_Type_tiP6Node_tS1_;	.scl	2;	.type	32;	.endef
__Z11Create_Node11Node_Type_tiP6Node_tS1_:
LFB17:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$16, 4(%esp)
	movl	$1, (%esp)
	call	_calloc
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	L22
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
L22:
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	-12(%ebp), %eax
	movl	20(%ebp), %edx
	movl	%edx, 12(%eax)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE17:
	.globl	__Z16File_Skip_SpacesPci
	.def	__Z16File_Skip_SpacesPci;	.scl	2;	.type	32;	.endef
__Z16File_Skip_SpacesPci:
LFB18:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	addl	$1, %eax
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	_calloc
	movl	%eax, -16(%ebp)
	cmpl	$0, -16(%ebp)
	jne	L25
	movl	$LC4, (%esp)
	call	_puts
	movl	8(%ebp), %eax
	jmp	L26
L25:
	movl	$0, -12(%ebp)
	jmp	L27
L30:
	jmp	L28
L29:
	addl	$1, 8(%ebp)
L28:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	je	L29
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$9, %al
	je	L29
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$10, %al
	je	L29
	movl	-12(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -12(%ebp)
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	addl	%eax, %edx
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	addl	$1, 8(%ebp)
L27:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L30
	movl	-12(%ebp), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
	movl	-16(%ebp), %eax
L26:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE18:
	.section .rdata,"dr"
LC7:
	.ascii " ( \0"
LC8:
	.ascii "%d\0"
LC9:
	.ascii "%s\0"
LC10:
	.ascii " ) \0"
	.text
	.globl	__Z14Tree_Text_DumpPK6Node_t
	.def	__Z14Tree_Text_DumpPK6Node_t;	.scl	2;	.type	32;	.endef
__Z14Tree_Text_DumpPK6Node_t:
LFB19:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 8(%ebp)
	jne	L32
	jmp	L31
L32:
	movl	$LC7, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	__Z14Tree_Text_DumpPK6Node_t
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$1, %eax
	jne	L34
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC8, (%esp)
	call	_printf
	jmp	L35
L34:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$2, %eax
	je	L36
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$3, %eax
	jne	L35
L36:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__Z11Get_Op_Namei
	movl	%eax, 4(%esp)
	movl	$LC9, (%esp)
	call	_printf
L35:
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, (%esp)
	call	__Z14Tree_Text_DumpPK6Node_t
	movl	$LC10, (%esp)
	call	_printf
L31:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE19:
	.section .rdata,"dr"
LC11:
	.ascii "tree.dot\0"
LC12:
	.ascii "File opening failed\0"
	.align 4
LC13:
	.ascii "digraph G { \12node [shape = record];\12 \"%p\" \0"
LC14:
	.ascii "}\12\0"
	.align 4
LC15:
	.ascii "<img src=\"tree%d.png\" alt=\"-\" width=\"500\" height=\"600\">\12\0"
	.align 4
LC16:
	.ascii "dot -T png tree.dot -o logs/tree%d.png\0"
	.text
	.globl	__Z15Tree_Graph_DumpPK6Node_t
	.def	__Z15Tree_Graph_DumpPK6Node_t;	.scl	2;	.type	32;	.endef
__Z15Tree_Graph_DumpPK6Node_t:
LFB20:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA20
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%ebx
	addl	$-128, %esp
	.cfi_offset 7, -12
	.cfi_offset 3, -16
	movl	$LC0, 4(%esp)
	movl	$LC11, (%esp)
	call	_fopen
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	L38
	movl	$LC12, (%esp)
	call	_perror
	movl	$3, %eax
	jmp	L43
L38:
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC13, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB2:
	call	__Z14Tree_Dump_BodyPK6Node_tP6_iobuf
LEHE2:
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$2, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC14, (%esp)
	call	_fwrite
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$100, -16(%ebp)
	leal	-116(%ebp), %ebx
	movl	$0, %eax
	movl	$25, %edx
	movl	%ebx, %edi
	movl	%edx, %ecx
	rep stosl
	movl	__ZZ15Tree_Graph_DumpPK6Node_tE10file_count, %edx
	movl	_logfile, %eax
	movl	%edx, 8(%esp)
	movl	$LC15, 4(%esp)
	movl	%eax, (%esp)
	call	_fprintf
	movl	__ZZ15Tree_Graph_DumpPK6Node_tE10file_count, %eax
	leal	1(%eax), %edx
	movl	%edx, __ZZ15Tree_Graph_DumpPK6Node_tE10file_count
	movl	%eax, 8(%esp)
	movl	$LC16, 4(%esp)
	leal	-116(%ebp), %eax
	movl	%eax, (%esp)
	call	_sprintf
	leal	-116(%ebp), %eax
	movl	%eax, (%esp)
	call	_system
	movl	$0, %eax
	jmp	L43
L42:
	movl	%eax, (%esp)
LEHB3:
	call	__Unwind_Resume
LEHE3:
L43:
	subl	$-128, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE20:
	.section	.gcc_except_table,"w"
LLSDA20:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE20-LLSDACSB20
LLSDACSB20:
	.uleb128 LEHB2-LFB20
	.uleb128 LEHE2-LEHB2
	.uleb128 L42-LFB20
	.uleb128 0
	.uleb128 LEHB3-LFB20
	.uleb128 LEHE3-LEHB3
	.uleb128 0
	.uleb128 0
LLSDACSE20:
	.text
	.section .rdata,"dr"
	.align 4
LC17:
	.ascii " \"%p\" [shape = Mrecord, style = filled, fillcolor = lightpink  label = \"%d \"];\12\0"
	.align 4
LC18:
	.ascii " \"%p\" [shape = Mrecord, style = filled, fillcolor = lightpink  label = \"%s \"];\12\0"
LC19:
	.ascii "\"%p\" -> \"%p\" \0"
LC20:
	.ascii "\12 \"%p\" -> \"%p\" \12\0"
	.text
	.globl	__Z14Tree_Dump_BodyPK6Node_tP6_iobuf
	.def	__Z14Tree_Dump_BodyPK6Node_tP6_iobuf;	.scl	2;	.type	32;	.endef
__Z14Tree_Dump_BodyPK6Node_tP6_iobuf:
LFB21:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 8(%ebp)
	jne	L45
	jmp	L44
L45:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$1, %eax
	jne	L47
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 12(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC17, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
	jmp	L48
L47:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$3, %eax
	je	L49
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$2, %eax
	jne	L48
L49:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__Z11Get_Op_Namei
	movl	%eax, 12(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC18, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
L48:
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	testl	%eax, %eax
	je	L50
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, 12(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
L50:
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	testl	%eax, %eax
	je	L51
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, 12(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
L51:
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__Z14Tree_Dump_BodyPK6Node_tP6_iobuf
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__Z14Tree_Dump_BodyPK6Node_tP6_iobuf
L44:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE21:
	.section .rdata,"dr"
	.align 4
LC22:
	.ascii "Error, because i dont't know this value\0"
LC24:
	.ascii "ERROR\0"
	.text
	.globl	__Z4EvalPK6Node_t
	.def	__Z4EvalPK6Node_t;	.scl	2;	.type	32;	.endef
__Z4EvalPK6Node_t:
LFB22:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	cmpl	$0, 8(%ebp)
	jne	L53
	fldz
	jmp	L54
L53:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$1, %eax
	jne	L55
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -28(%ebp)
	fildl	-28(%ebp)
	jmp	L54
L55:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$3, %eax
	jne	L56
	movl	$LC22, (%esp)
	call	_puts
	fldz
	jmp	L54
L56:
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	__Z4EvalPK6Node_t
	fstpl	-16(%ebp)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, (%esp)
	call	__Z4EvalPK6Node_t
	fstpl	-24(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$2, %eax
	jne	L57
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	subl	$42, %eax
	cmpl	$74, %eax
	ja	L58
	movl	L60(,%eax,4), %eax
	jmp	*%eax
	.section .rdata,"dr"
	.align 4
L60:
	.long	L59
	.long	L61
	.long	L58
	.long	L62
	.long	L58
	.long	L63
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L64
	.long	L58
	.long	L58
	.long	L58
	.long	L65
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L58
	.long	L66
	.long	L67
	.text
L61:
	fldl	-16(%ebp)
	faddl	-24(%ebp)
	jmp	L54
L62:
	fldl	-16(%ebp)
	fsubl	-24(%ebp)
	jmp	L54
L63:
	fldl	-16(%ebp)
	fdivl	-24(%ebp)
	jmp	L54
L59:
	fldl	-16(%ebp)
	fmull	-24(%ebp)
	jmp	L54
L66:
	fldl	-24(%ebp)
	fstpl	(%esp)
	call	_sin
	jmp	L54
L64:
	fldl	-24(%ebp)
	fstpl	(%esp)
	call	_cos
	jmp	L54
L67:
	fldl	-24(%ebp)
	fstpl	(%esp)
	call	_tan
	jmp	L54
L65:
	fldl	-24(%ebp)
	fstpl	(%esp)
	call	_tan
	fld1
	fdivp	%st, %st(1)
	jmp	L54
L58:
	movl	$LC24, (%esp)
	call	_puts
	nop
L57:
	fldl	LC25
L54:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE22:
	.globl	__Z1dPK6Node_t
	.def	__Z1dPK6Node_t;	.scl	2;	.type	32;	.endef
__Z1dPK6Node_t:
LFB23:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	cmpl	$0, 8(%ebp)
	jne	L69
	movl	$0, %eax
	jmp	L70
L69:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$1, %eax
	jne	L71
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	movl	$0, 4(%esp)
	movl	$1, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	jmp	L70
L71:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$3, %eax
	jne	L72
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	movl	$1, 4(%esp)
	movl	$1, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	jmp	L70
L72:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$2, %eax
	jne	L73
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	subl	$42, %eax
	cmpl	$74, %eax
	ja	L74
	movl	L76(,%eax,4), %eax
	jmp	*%eax
	.section .rdata,"dr"
	.align 4
L76:
	.long	L75
	.long	L77
	.long	L74
	.long	L78
	.long	L74
	.long	L79
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L80
	.long	L74
	.long	L74
	.long	L74
	.long	L81
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L74
	.long	L82
	.long	L83
	.text
L77:
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, (%esp)
	call	__Z1dPK6Node_t
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	__Z1dPK6Node_t
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$43, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z12OptimizationP6Node_t
	movl	-28(%ebp), %eax
	jmp	L70
L78:
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, (%esp)
	call	__Z1dPK6Node_t
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	__Z1dPK6Node_t
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$45, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z12OptimizationP6Node_t
	movl	-32(%ebp), %eax
	jmp	L70
L75:
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, (%esp)
	call	__Z1dPK6Node_t
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	__Z1cPK6Node_t
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$42, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, (%esp)
	call	__Z1cPK6Node_t
	movl	%eax, %esi
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	__Z1dPK6Node_t
	movl	%esi, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$42, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$43, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z12OptimizationP6Node_t
	movl	-36(%ebp), %eax
	jmp	L70
L79:
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, (%esp)
	call	__Z1cPK6Node_t
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, (%esp)
	call	__Z1cPK6Node_t
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$42, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, (%esp)
	call	__Z1dPK6Node_t
	movl	%eax, %esi
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	__Z1cPK6Node_t
	movl	%esi, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$42, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, %esi
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, (%esp)
	call	__Z1cPK6Node_t
	movl	%eax, %edi
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	__Z1dPK6Node_t
	movl	%edi, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$42, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%esi, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$45, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%ebx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$47, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, -40(%ebp)
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z12OptimizationP6Node_t
	movl	-40(%ebp), %eax
	jmp	L70
L82:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z1cPK6Node_t
	movl	%eax, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	$99, (%eax)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, (%esp)
	call	__Z1dPK6Node_t
	movl	%eax, 12(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$42, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, -44(%ebp)
	movl	-44(%ebp), %eax
	jmp	L70
L80:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z1cPK6Node_t
	movl	%eax, -48(%ebp)
	movl	-48(%ebp), %eax
	movl	$115, (%eax)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, (%esp)
	call	__Z1dPK6Node_t
	movl	%eax, 12(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$42, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, -48(%ebp)
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	movl	$-1, 4(%esp)
	movl	$1, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	-48(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$42, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, -48(%ebp)
	movl	-48(%ebp), %eax
	jmp	L70
L83:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z1cPK6Node_t
	movl	%eax, -52(%ebp)
	movl	-52(%ebp), %eax
	movl	$99, (%eax)
	movl	-52(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$42, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, -52(%ebp)
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	movl	$1, 4(%esp)
	movl	$1, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	-52(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$47, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, -52(%ebp)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, (%esp)
	call	__Z1dPK6Node_t
	movl	%eax, 12(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$42, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, -52(%ebp)
	movl	-52(%ebp), %eax
	jmp	L70
L81:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z1cPK6Node_t
	movl	%eax, -56(%ebp)
	movl	-56(%ebp), %eax
	movl	$115, (%eax)
	movl	-56(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-56(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$42, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, -56(%ebp)
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	movl	$-1, 4(%esp)
	movl	$1, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	-56(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$47, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, -56(%ebp)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, (%esp)
	call	__Z1dPK6Node_t
	movl	%eax, 12(%esp)
	movl	-56(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$42, 4(%esp)
	movl	$2, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
	movl	%eax, -56(%ebp)
	movl	-56(%ebp), %eax
	jmp	L70
L74:
	movl	$LC24, (%esp)
	call	_puts
L73:
	movl	$0, %eax
L70:
	addl	$60, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE23:
	.globl	__Z1cPK6Node_t
	.def	__Z1cPK6Node_t;	.scl	2;	.type	32;	.endef
__Z1cPK6Node_t:
LFB24:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	cmpl	$0, 8(%ebp)
	jne	L85
	movl	$0, %eax
	jmp	L86
L85:
	movl	8(%ebp), %eax
	movl	12(%eax), %ebx
	movl	8(%ebp), %eax
	movl	8(%eax), %ecx
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__Z11Create_Node11Node_Type_tiP6Node_tS1_
L86:
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE24:
	.globl	__Z18Optimization_ConstP6Node_t
	.def	__Z18Optimization_ConstP6Node_t;	.scl	2;	.type	32;	.endef
__Z18Optimization_ConstP6Node_t:
LFB25:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 8(%ebp)
	je	L88
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	testl	%eax, %eax
	je	L88
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	testl	%eax, %eax
	jne	L89
L88:
	movl	$0, %eax
	jmp	L90
L89:
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	4(%eax), %eax
	cmpl	$1, %eax
	jne	L91
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	4(%eax), %eax
	cmpl	$1, %eax
	jne	L91
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z4EvalPK6Node_t
	fnstcw	-10(%ebp)
	movzwl	-10(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -12(%ebp)
	fldcw	-12(%ebp)
	fistpl	-16(%ebp)
	fldcw	-10(%ebp)
	movl	-16(%ebp), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	$1, 4(%eax)
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	%eax, (%esp)
	call	__Z9Node_FreePP6Node_t
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
	call	__Z9Node_FreePP6Node_t
	movl	$9, %eax
	jmp	L90
L91:
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	__Z18Optimization_ConstP6Node_t
	testl	%eax, %eax
	jne	L92
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, (%esp)
	call	__Z18Optimization_ConstP6Node_t
	testl	%eax, %eax
	je	L93
L92:
	movl	$1, %eax
	jmp	L94
L93:
	movl	$0, %eax
L94:
	movzbl	%al, %eax
L90:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE25:
	.globl	__Z19Optimization_OptionPP6Node_t
	.def	__Z19Optimization_OptionPP6Node_t;	.scl	2;	.type	32;	.endef
__Z19Optimization_OptionPP6Node_t:
LFB26:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L96
	movl	$0, %eax
	jmp	L97
L96:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	4(%eax), %eax
	cmpl	$2, %eax
	jne	L98
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	cmpl	$42, %eax
	jne	L98
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%eax), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L99
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%eax), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L100
L99:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	$0, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	$1, 4(%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movl	%eax, (%esp)
	call	__Z9Node_FreePP6Node_t
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
	call	__Z9Node_FreePP6Node_t
	movl	$9, %eax
	jmp	L97
L100:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%eax), %eax
	movl	(%eax), %eax
	cmpl	$1, %eax
	jne	L101
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movl	%eax, (%esp)
	call	__Z9Node_FreePP6Node_t
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	$9, %eax
	jmp	L97
L101:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%eax), %eax
	movl	(%eax), %eax
	cmpl	$1, %eax
	jne	L102
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
	call	__Z9Node_FreePP6Node_t
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	$9, %eax
	jmp	L97
L102:
	movl	$0, %eax
	jmp	L97
L98:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movl	%eax, (%esp)
	call	__Z19Optimization_OptionPP6Node_t
	testl	%eax, %eax
	jne	L103
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
	call	__Z19Optimization_OptionPP6Node_t
	testl	%eax, %eax
	je	L104
L103:
	movl	$1, %eax
	jmp	L105
L104:
	movl	$0, %eax
L105:
	movzbl	%al, %eax
L97:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE26:
	.globl	__Z12OptimizationP6Node_t
	.def	__Z12OptimizationP6Node_t;	.scl	2;	.type	32;	.endef
__Z12OptimizationP6Node_t:
LFB27:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	nop
L110:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z18Optimization_ConstP6Node_t
	testl	%eax, %eax
	jne	L107
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z19Optimization_OptionPP6Node_t
	testl	%eax, %eax
	je	L108
L107:
	movl	$1, %eax
	jmp	L109
L108:
	movl	$0, %eax
L109:
	testb	%al, %al
	jne	L110
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE27:
	.globl	__Z9Node_FreePP6Node_t
	.def	__Z9Node_FreePP6Node_t;	.scl	2;	.type	32;	.endef
__Z9Node_FreePP6Node_t:
LFB28:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L111
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movl	%eax, (%esp)
	call	__Z9Node_FreePP6Node_t
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$12, %eax
	movl	%eax, (%esp)
	call	__Z9Node_FreePP6Node_t
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	$0, 8(%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	$0, 12(%eax)
	movl	8(%ebp), %eax
	movl	$0, (%eax)
L111:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE28:
	.globl	__Z14Diff_Tree_CtorPcP6File_tP6Tree_t
	.def	__Z14Diff_Tree_CtorPcP6File_tP6Tree_t;	.scl	2;	.type	32;	.endef
__Z14Diff_Tree_CtorPcP6File_tP6Tree_t:
LFB29:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z11File_ReaderP6File_t
	movl	%eax, -12(%ebp)
	cmpl	$8, -12(%ebp)
	je	L114
	movl	$1, %eax
	jmp	L115
L114:
	movl	12(%ebp), %eax
	movl	12(%eax), %edx
	movl	12(%ebp), %eax
	movl	8(%eax), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__Z16File_Skip_SpacesPci
	movl	12(%ebp), %edx
	movl	%eax, 8(%edx)
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	8(%eax), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__Z11Get_GeneralPcP6Node_t
	movl	16(%ebp), %edx
	movl	%eax, (%edx)
	movl	$8, %eax
L115:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE29:
	.globl	__Z14Diff_Tree_DtorP6File_tP6Tree_t
	.def	__Z14Diff_Tree_DtorP6File_tP6Tree_t;	.scl	2;	.type	32;	.endef
__Z14Diff_Tree_DtorP6File_tP6Tree_t:
LFB30:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z9Node_FreePP6Node_t
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	_free
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	_fclose
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE30:
	.section .rdata,"dr"
LC27:
	.ascii "sin\0"
LC28:
	.ascii "cos\0"
LC29:
	.ascii "tg\0"
LC30:
	.ascii "ctg\0"
	.text
	.globl	__Z11Get_Op_Namei
	.def	__Z11Get_Op_Namei;	.scl	2;	.type	32;	.endef
__Z11Get_Op_Namei:
LFB31:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	cmpl	$115, %eax
	jne	L118
	movl	$LC27, %eax
	jmp	L119
L118:
	movl	8(%ebp), %eax
	cmpl	$99, %eax
	jne	L120
	movl	$LC28, %eax
	jmp	L119
L120:
	movl	8(%ebp), %eax
	cmpl	$116, %eax
	jne	L121
	movl	$LC29, %eax
	jmp	L119
L121:
	movl	8(%ebp), %eax
	cmpl	$103, %eax
	jne	L122
	movl	$LC30, %eax
	jmp	L119
L122:
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_strdup
L119:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE31:
	.section .rdata,"dr"
LC31:
	.ascii "logs/log.html\0"
	.text
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB32:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L123
	cmpl	$65535, 12(%ebp)
	jne	L123
	movl	$LC0, 4(%esp)
	movl	$LC31, (%esp)
	call	_fopen
	movl	%eax, _logfile
L123:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE32:
	.def	__GLOBAL__sub_I_logfile;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_logfile:
LFB33:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE33:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_logfile
.lcomm __ZZ15Tree_Graph_DumpPK6Node_tE10file_count,4,4
	.section .rdata,"dr"
	.align 8
LC25:
	.long	0
	.long	1075576832
	.ident	"GCC: (GNU) 4.8.1"
	.def	_fopen;	.scl	2;	.type	32;	.endef
	.def	_fclose;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_calloc;	.scl	2;	.type	32;	.endef
	.def	_fread;	.scl	2;	.type	32;	.endef
	.def	_perror;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
	.def	_ftell;	.scl	2;	.type	32;	.endef
	.def	_fseek;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_fprintf;	.scl	2;	.type	32;	.endef
	.def	_fwrite;	.scl	2;	.type	32;	.endef
	.def	_sprintf;	.scl	2;	.type	32;	.endef
	.def	_system;	.scl	2;	.type	32;	.endef
	.def	_sin;	.scl	2;	.type	32;	.endef
	.def	_cos;	.scl	2;	.type	32;	.endef
	.def	_tan;	.scl	2;	.type	32;	.endef
	.def	__Z11Get_GeneralPcP6Node_t;	.scl	2;	.type	32;	.endef
	.def	_strdup;	.scl	2;	.type	32;	.endef
