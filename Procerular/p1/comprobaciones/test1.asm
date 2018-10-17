segment .data
	msg_error_division_por_0	db "Division por 0", 0
segment .bss
	__esp resd 1
	_b1 resd 1
	_x resd 1
segment .text
	global main
extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean, print_endofline, print_blank, print_string
main:
	mov dword [__esp], __esp
	push dword _b1
	call scan_boolean
	add esp, 4
	push dword _x
	call scan_int
	add esp, 4
	push dword _x
	push dword 3
	pop edx
	pop eax
	mov eax, [eax]
	cmp eax, edx
	jg mayor_0
	push dword 0
	jmp final_0
mayor_0:
	push dword 1
final_0:
	pop eax
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	push dword _x
	push dword 3
	pop edx
	pop eax
	mov eax, [eax]
	cmp eax, edx
	jge mayor_igual_1
	push dword 0
	jmp final_1
mayor_igual_1:
	push dword 1
final_1:
	pop eax
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	push dword _x
	push dword 3
	pop edx
	pop eax
	mov eax, [eax]
	cmp eax, edx
	jl menor_2
	push dword 0
	jmp final_2
menor_2:
	push dword 1
final_2:
	pop eax
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	push dword _x
	push dword 3
	pop edx
	pop eax
	mov eax, [eax]
	cmp eax, edx
	jle menor_igual_3
	push dword 0
	jmp final_3
menor_igual_3:
	push dword 1
final_3:
	pop eax
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	push dword _x
	push dword 3
	pop ecx
	pop eax
	mov eax, [eax]
	cmp eax, ecx
	je igual_4
	push dword 0
	jmp final_4
igual_4:
	push dword 1
final_4:
	pop eax
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	push dword _x
	push dword 3
	pop ecx
	pop eax
	mov eax, [eax]
	cmp eax, ecx
	je igual_5
	push dword 1
	jmp final_5
igual_5:
	push dword 0
final_5:
	pop eax
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	push dword _b1
	push dword 0
	pop ecx
	pop eax
	mov eax, [eax]
	and eax, ecx
	push eax
	pop eax
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	push dword _b1
	push dword 1
	pop ecx
	pop eax
	mov eax, [eax]
	or eax, ecx
	push eax
	pop eax
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
fin:
	mov dword [__esp], __esp
	ret
