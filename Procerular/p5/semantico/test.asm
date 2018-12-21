segment .data
	msg_div_0	db "Division por 0", 0
	msg_tam_vector	db "Index out of range", 0
segment .bss
	__esp resd 1
	_i resd 1
	_x resd 8
segment .text
	global main
extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean, print_endofline, print_blank, print_string, malloc, free
main:
	mov dword [__esp], __esp
	jmp init
init:
	push dword 0
	;fin escritura operando -----
	pop dword eax
	mov [_i], eax
	;fin asignacion -----

while_1:
	push dword _i
	;fin escritura operando -----
	push dword 8
	;fin escritura operando -----
	pop edx
	pop eax
	mov eax, [eax]
	cmp eax, edx
	jl near menor_2
	push dword 0
	jmp near final_2
menor_2:
	push dword 1
final_2:
	pop eax
	cmp eax, 0
	je near fin_while_1
	push dword _i
	;fin escritura operando -----
	pop dword eax
	mov eax, [eax]
	cmp eax, 0
	jl near mensaje_tam_vector
	cmp eax, 7
	jg near mensaje_tam_vector
	mov dword edx, _x
	lea eax, [edx + eax*4]
	push dword eax
	push dword _i
	;fin escritura operando -----
	push dword _i
	;fin escritura operando -----
	push dword 1
	;fin escritura operando -----
	pop eax
	pop edx
	mov edx, [edx]
	sub edx, eax
	push edx
	pop ecx
	pop eax
	mov eax, [eax]
	imul ecx
	push eax
	pop dword eax
	pop dword edx
	mov [edx], eax
	push dword _i
	;fin escritura operando -----
	push dword 1
	;fin escritura operando -----
	pop eax
	pop edx
	mov edx, [edx]
	add edx, eax
	push edx
	;fin suma -----

	pop dword eax
	mov [_i], eax
	;fin asignacion -----

	jmp while_1
fin_while_1:
	push dword 0
	;fin escritura operando -----
	pop dword eax
	mov [_i], eax
	;fin asignacion -----

while_3:
	push dword _i
	;fin escritura operando -----
	pop dword eax
	mov eax, [eax]
	cmp eax, 0
	jl near mensaje_tam_vector
	cmp eax, 7
	jg near mensaje_tam_vector
	mov dword edx, _x
	lea eax, [edx + eax*4]
	push dword eax
	push dword 40
	;fin escritura operando -----
	pop edx
	pop eax
	mov eax, [eax]
	cmp eax, edx
	jl near menor_4
	push dword 0
	jmp near final_4
menor_4:
	push dword 1
final_4:
	pop eax
	cmp eax, 0
	je near fin_while_3
	push dword _i
	;fin escritura operando -----
	pop dword eax
	mov eax, [eax]
	cmp eax, 0
	jl near mensaje_tam_vector
	cmp eax, 7
	jg near mensaje_tam_vector
	mov dword edx, _x
	lea eax, [edx + eax*4]
	push dword eax
	pop eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	;fin escritura -----

	push dword _i
	;fin escritura operando -----
	push dword 1
	;fin escritura operando -----
	pop eax
	pop edx
	mov edx, [edx]
	add edx, eax
	push edx
	;fin suma -----

	pop dword eax
	mov [_i], eax
	;fin asignacion -----

	jmp while_3
fin_while_3:
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
