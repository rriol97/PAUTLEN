segment .data
	msg_error_division_por_0	db "Division por 0", 0
segment .bss
	__esp resd 1
	_x1 resd 1
	_x2 resd 1
	_y1 resd 1
segment .text
	global main
extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean, print_endofline, print_blank, print_string
main:
	mov dword [__esp], __esp
	push dword _x1
	;fin escritura operando -----

	call scan_int
	add esp, 4
	;fin lectura -----

	push dword _x2
	;fin escritura operando -----

	call scan_int
	add esp, 4
	;fin lectura -----

	push dword 0
	;fin escritura operando -----

	pop dword eax
	mov [_y1], eax
	;fin asignacion -----

	push dword _y1
	;fin escritura operando -----

	pop eax
	mov eax, [eax]
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	;fin escritura -----

	push dword 3
	;fin escritura operando -----

	push dword _x1
	;fin escritura operando -----



	pop eax
	pop edx
	mov eax, [eax]
	add edx, eax
	push edx
	;fin suma -----

	push dword _x2
	;fin escritura operando -----

	pop eax
	pop edx
	mov eax, [eax]
	add edx, eax
	push edx
	;fin suma -----

	pop eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	;fin escritura -----

fin:
	mov dword [__esp], __esp
	ret
