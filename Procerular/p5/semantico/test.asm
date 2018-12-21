segment .data
	msg_error_division_por_0	db "Division por 0", 0
segment .bss
	__esp resd 1
	_x resd 1
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
	mov [_x], eax
	;fin asignacion -----

while_1:
	push dword _x
	;fin escritura operando -----
	push dword 100
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
	push dword _x
	;fin escritura operando -----
	pop eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	;fin escritura -----

	push dword _x
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
	mov [_x], eax
	;fin asignacion -----

	jmp while_1
fin_while_1:
fin:
	mov dword [__esp], __esp
	ret
