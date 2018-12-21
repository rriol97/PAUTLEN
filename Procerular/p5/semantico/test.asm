segment .data
	msg_error_division_por_0	db "Division por 0", 0
segment .bss
	__esp resd 1
	_z resd 1
segment .text
	global main
extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean, print_endofline, print_blank, print_string, malloc, free
main:
	mov dword [__esp], __esp
	jmp init
_doble@1:
	push ebp
	mov ebp, esp
	sub esp, 4
	lea eax, [ebp + 8]
	push dword eax
	pop dword eax
	mov eax, [eax]
	mov [ebp-4], eax
	push dword 2
	;fin escritura operando -----
	lea eax, [ebp - 4]
	push dword eax
	pop eax
	pop edx
	mov eax, [eax]
	add edx, eax
	push edx
	;fin suma -----

	pop eax
	mov esp, ebp
	pop ebp
	ret
	; Fin Funcion
init:
	push dword _z
	;fin escritura operando -----
	call scan_int
	add esp, 4
	;fin lectura -----

	push dword _z
	;fin escritura operando -----
	pop eax
	mov eax, [eax]
	push eax
	call _doble@1
	add esp, 4
	push dword eax
	pop eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	;fin escritura -----

fin:
	mov dword [__esp], __esp
	ret
