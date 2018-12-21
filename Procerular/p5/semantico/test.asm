segment .data
	msg_div_0	db "****Error de ejecucion: Division por cero.", 0
	msg_tam_vector	db "****Error de ejecucion: Indice fuera de rango.", 0
segment .bss
	__esp resd 1
	_i resd 1
segment .text
	global main
extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean, print_endofline, print_blank, print_string, malloc, free
main:
	mov dword [__esp], __esp
	jmp init
_sinIva@1:
	push ebp
	mov ebp, esp
	sub esp, 8
	lea eax, [ebp + 8]
	push dword eax
	; escribir operando -----

	push dword 5
	;fin escritura operando -----
	pop ecx
	pop eax
	mov eax, [eax]
	imul ecx
	push eax
	pop dword eax
	mov [ebp-4], eax
	; fin asignacion en funcion -----

	push dword 1
	;fin escritura operando -----
	pop dword eax
	mov [ebp-8], eax
	; fin asignacion en funcion -----

	lea eax, [ebp - 8]
	push dword eax
	; escribir variable -----

	lea eax, [ebp - 4]
	push dword eax
	; escribir variable -----

	pop eax
	pop edx
	mov edx, [edx]
	mov eax, [eax]
	add edx, eax
	push edx
	;fin suma -----

	pop eax
	mov esp, ebp
	pop ebp
	ret
	; Fin Funcion  ^^^^^^
init:
	push dword 1000
	;fin escritura operando -----
	call _sinIva@1
	add esp, 4
	push dword eax
	pop eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	;fin escritura -----

jmp fin
mensaje_tam_vector:
	push dword msg_tam_vector
	call print_string
	add esp, 4
	jmp near fin
mensaje_div_0:
	push dword msg_div_0
	call print_string
	add esp, 4
fin:
	mov dword [__esp], __esp
	ret
