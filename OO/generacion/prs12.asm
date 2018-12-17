segment .data
	msg_error_division_por_0	db "Division por 0", 0
segment .bss
	__esp resd 1
	_a resd 1
	_b resd 1
	_c resd 1
	_c2 resd 1
segment .text
	global main
extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean, print_endofline, print_blank, print_string, malloc, free
	extern _msbA,  _msbB, _BmsbA, _msbC, _CmsbA, _CmsbB, _no_defined_method, _mcA, _mcB, _mcC,  _set_offsets, _create_ms_table, _offset_msbA, _offset_msbB,  _offset_msbC,  _offset_aia, _offset_aib, _offset_aic, _msA, _msB, _msC, _aca, _acb, _acc
_main_factorial@o2:
	push ebp
	mov ebp, esp
	sub esp, 8
	push dword 28
	call malloc
	add esp, 4
	mov dword [eax], _msC
	push eax
	lea eax, [ebp - 8]
	push dword eax
	pop dword edx
	pop dword eax
	mov [edx], eax
	push dword 9999
	;fin escritura operando -----
	lea eax, [ebp - 8]
	push dword eax
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aic]
	lea ecx, [ebx+ecx]
	push dword ecx
	pop dword edx
	pop dword eax
	mov [edx], eax
	lea eax, [ebp - 8]
	push dword eax
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aic]
	lea ecx, [ebx+ecx]
	push dword ecx
	pop eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	;fin escritura -----

	lea eax, [ebp + 8]
	push dword eax
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aic]
	lea ecx, [ebx+ecx]
	push dword ecx
	pop eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	;fin escritura -----

	lea eax, [ebp - 8]
	push dword eax
	pop eax
	mov eax, [eax]
	mov esp, ebp
	pop ebp
	ret
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
	push dword 10
	;fin escritura operando -----
	push dword _c
	;fin escritura operando -----
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aia]
	lea ecx, [ebx+ecx]
	push dword ecx
	pop dword edx
	pop dword eax
	mov [edx], eax
	push dword 100
	;fin escritura operando -----
	push dword _c
	;fin escritura operando -----
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aib]
	lea ecx, [ebx+ecx]
	push dword ecx
	pop dword edx
	pop dword eax
	mov [edx], eax
	push dword 1000
	;fin escritura operando -----
	push dword _c
	;fin escritura operando -----
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aic]
	lea ecx, [ebx+ecx]
	push dword ecx
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
	push dword _a
	;fin escritura operando -----
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aia]
	lea ecx, [ebx+ecx]
	push dword ecx
	pop eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	;fin escritura -----

	push dword _b
	;fin escritura operando -----
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aib]
	lea ecx, [ebx+ecx]
	push dword ecx
	pop eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	;fin escritura -----

	push dword _c
	;fin escritura operando -----
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aic]
	lea ecx, [ebx+ecx]
	push dword ecx
	pop eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	;fin escritura -----

	push dword _c
	;fin escritura operando -----
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_msbC]
	lea ecx, [ebx+ecx]
	mov ecx, [ecx]
	call ecx
	push dword _c
	;fin escritura operando -----
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_msbA]
	lea ecx, [ebx+ecx]
	mov ecx, [ecx]
	call ecx
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
	mov dword ebx, [ebx]
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_msbA]
	lea ecx, [ebx+ecx]
	mov ecx, [ecx]
	call ecx
	push dword _b
	;fin escritura operando -----
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_msbA]
	lea ecx, [ebx+ecx]
	mov ecx, [ecx]
	call ecx
	push dword _c
	;fin escritura operando -----
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_msbA]
	lea ecx, [ebx+ecx]
	mov ecx, [ecx]
	call ecx
	push dword _c
	;fin escritura operando -----
	pop eax
	mov eax, [eax]
	push eax
	call _main_factorial@o2
	add esp, 4
	push dword eax
	pop dword eax
	mov [_c2], eax
	;fin asignacion -----

	push dword _c2
	;fin escritura operando -----
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aic]
	lea ecx, [ebx+ecx]
	push dword ecx
	pop eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	;fin escritura -----

	push dword _c2
	;fin escritura operando -----
	pop dword ebx
	push dword [ebx]
	call free
	add esp, 4
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
	push dword _c
	;fin escritura operando -----
	pop dword ebx
	push dword [ebx]
	call free
	add esp, 4
fin:
	mov dword [__esp], __esp
	ret
