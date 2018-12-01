segment .data
	msg_error_division_por_0	db "Division por 0", 0
segment .bss
	__esp resd 1
	_x1 resd 1
	_x2 resd 1
segment .text
	global main
extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean, print_endofline, print_blank, print_string
main:
	mov dword [__esp], __esp
	push dword 1
	pop dword eax
	mov [_x1], eax
	push dword 2
	pop dword eax
	mov [_x2], eax
	push dword x2
	pop eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
fin:
	mov dword [__esp], __esp
	ret
