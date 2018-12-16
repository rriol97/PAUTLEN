segment .data
	msg_error_division_por_0	db "Division por 0", 0
segment .bss
	__esp resd 1
	_a resd 1
	_b resd 1
	_c resd 1
segment .text
	global main
extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean, print_endofline, print_blank, print_string, malloc, free
	extern _msA,  _msB, _BmsA, _msC, _CmsA, _CmsB, _no_defined_method, _mcA, _mcB, _mcC,  _set_offsets, _create_ms_table, _offset_msA, _offset_msB,  _offset_msC,  _offset_aia, _offset_aib, _offset_aic, _msA, _msB, _msC, _aca, _acb, _acc
main:
	mov dword [__esp], __esp
	call _create_ms_table
	push dword 16
	call malloc
	add esp, 4
	mov dword [eax], _msC
	push eax
	push dword _c
	;fin escritura operando -----
	pop dword edx
	pop dword eax
	mov [edx], eax
	push dword _c
	;fin escritura operando -----
	push dword _b
	;fin escritura operando -----
	pop dword edx
	pop dword eax
	mov eax, [eax]
	mov [edx], eax
	push dword _b
	;fin escritura operando -----
	push dword _a
	;fin escritura operando -----
	pop dword edx
	pop dword eax
	mov eax, [eax]
	mov [edx], eax
	push dword _c
	;fin escritura operando -----
	pop dword ebx
	push dword [ebx]
	call free
	add esp, 4
	push dword 12
	call malloc
	add esp, 4
	mov dword [eax], _msB
	push eax
	push dword _b
	;fin escritura operando -----
	pop dword edx
	pop dword eax
	mov [edx], eax
	push dword 8
	call malloc
	add esp, 4
	mov dword [eax], _msA
	push eax
	push dword _a
	;fin escritura operando -----
	pop dword edx
	pop dword eax
	mov [edx], eax
	push dword _a
	;fin escritura operando -----
	pop dword ebx
	push dword [ebx]
	call free
	add esp, 4
	push dword _b
	;fin escritura operando -----
	pop dword ebx
	push dword [ebx]
	call free
	add esp, 4
fin:
	mov dword [__esp], __esp
	ret
