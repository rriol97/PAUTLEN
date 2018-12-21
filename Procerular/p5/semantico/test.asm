segment .data
	msg_div_0	db "****Error de ejecucion: Division por cero.", 0
	msg_tam_vector	db "****Error de ejecucion: Indice fuera de rango.", 0
segment .bss
	__esp resd 1
	_x1 resd 1
	_x2 resd 1
	_y1 resd 1
segment .text
	global main
extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean, print_endofline, print_blank, print_string, malloc, free
main:
	mov dword [__esp], __esp
	jmp init
init:
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

	push dword _y1
	;fin escritura operando -----
	call scan_boolean
	add esp, 4
	;fin lectura -----

	push dword _x1
	;fin escritura operando -----
	push dword _x2
	;fin escritura operando -----
	pop ecx
	pop eax
	mov eax, [eax]
	mov ecx, [ecx]
	cmp eax, ecx
	je near igual_1
	push dword 0
	jmp near final_1
igual_1:
	push dword 1
final_1:
	;fin igualacion -----

	pop eax
	cmp eax, 0
	je near fin_if_2
	push dword _y1
	;fin escritura operando -----
	pop eax
	mov eax, [eax]
	cmp eax, 0
	je near fin_if_3
	push dword 110
	;fin escritura operando -----
	pop eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	;fin escritura -----

	jmp near fin_ifelse_3
fin_if_3:
	push dword 111
	;fin escritura operando -----
	pop eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	;fin escritura -----

fin_ifelse_3:
	jmp near fin_ifelse_2
fin_if_2:
	push dword _y1
	;fin escritura operando -----
	pop eax
	mov eax, [eax]
	cmp eax, 0
	je near fin_if_4
	push dword 10
	;fin escritura operando -----
	pop eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	;fin escritura -----

	jmp near fin_ifelse_4
fin_if_4:
	push dword 11
	;fin escritura operando -----
	pop eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	;fin escritura -----

fin_ifelse_4:
fin_ifelse_2:
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
