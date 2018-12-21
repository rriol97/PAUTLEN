segment .data
	msg_error_division_por_0	db "Division por 0", 0
segment .bss
	__esp resd 1
	_y resd 1
segment .text
	global main
extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean, print_endofline, print_blank, print_string, malloc, free
main:
	mov dword [__esp], __esp
	jmp init
_doble@3:
	push ebp
	mov ebp, esp
	sub esp, 8
	lea eax, [ebp - 4]
	push dword eax
	; escribir variable -----

	call scan_boolean
	add esp, 4
	;fin lectura -----

	lea eax, [ebp + 8]
	push dword eax
	; escribir operando -----

	lea eax, [ebp - 4]
	push dword eax
	; escribir variable -----

	pop ecx
	pop eax
	mov eax, [eax]
	mov ecx, [ecx]
	and eax, ecx
	push eax
	; fin AND -----

	pop dword eax
	mov [ebp-8], eax
	; fin asignacion en funcion -----

	lea eax, [ebp - 8]
	push dword eax
	; escribir variable -----

	pop eax
	mov eax, [eax]
	mov esp, ebp
	pop ebp
	ret
	; Fin Funcion  ^^^^^^
init:
	push dword _y
	;fin escritura operando -----
	call scan_boolean
	add esp, 4
	;fin lectura -----

	push dword _y
	;fin escritura operando -----
	pop eax
	mov eax, [eax]
	push eax
	; operando en pila a argumento -----

	call _doble@3
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
