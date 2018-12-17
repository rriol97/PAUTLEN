
	global _A, _B, _C, _BmsA, _CmsA, _CmsB, _no_defined_method, _mcA, _mcB, _mcC, _set_offsets, _create_ms_table, _offset_msbA, _offset_msbB, _offset_msbC, _offset_aia, _offset_aib, _offset_aic, _msA, _msB, _msC, _msD, _acA1, _acB1, _acC1, _acD1


segment .data
	msg_error_indice_vector     db "Indice de vector fuera de rango", 0
	msg_asignacion     db "Asignacion", 0
	msg_f2     db "Llamada a f2", 0
	__auxfloat dd 0.0
	__auxint dd 0.0
; SET METODOS SOBREESCRIBIBLES OFFSET
; SE ESTÁ SUPONIENDO LA LINEALIZACIÓN  A B C D
; RESPECTO A MÉTODOS SOBREESCRIBIBLES CADA UNA TIENE 2 DE NOMBRES RESPECTIVAMENTE 
; (ms)A1 (ms)A2 (m2)B2 (ms)B2 (ms)C1 (ms)C2 (ms)D1 (ms)D2
	_offset_msbA dd 0
	_offset_msbB dd 4
	_offset_msbC dd 8

; SET ATRIBUTOS INSTANCIA OFFSET
; SE ESTÁ SUPONIENDO LA LINEALIZACIÓN  A B C D
; RESPECTO ATRIBUTOS DE INSTANCIA CADA UNA TIENE 2 DE NOMBRES RESPECTIVAMENTE 
; (ai)A1 (ai)A2 (ai)B2 (ai)B2 (ai)C1 (ai)C2 (ai)D1 (ai)D2
; DEBEN PRESERVAR UNA POSICIÓN (4 bytes) PARA EL PUNTERO A LA TABLA DE MÉTODOS SOBREESCRIBIBLES
	_offset_aia dd 4 ; 4+0      ; ESTO SE DEBE ESCRIBIR CUANDO SE ESCRIBA LA TABLA DE SIMBOLOS Y SE ENCUENTRE UN ATRIBUTO DE INSTANCIA
	_offset_aib dd 8 ; 4+4
	_offset_aic dd 12 ; 4+8
	
segment .bss
	__esp resd 4
; Class A
	_msA resd 2
; Class B
	_msB resd 4
; Class C
	_msC resd 6
; OBS IMPORTANTE.. AL MARGEN DE LA LINEALIZACIÓN, LAS INSTANCIAS SON DECLARADAS SÓLO COMO PUNTEROS A LOS OBJETOS.. ASÍ QUE TODOS SON resd1
; Class A a1
	_object_a1 resd 1
; Class B b1
	_object_b1 resd 1
; Class C c1
	_object_c1 resd 1
	_object_c2 resd 1
; LOS ATRIBUTOS DE CLASE
	_aca resd 1
	_acb resd 1
	_acc resd 1
segment .text
	;global main



; Es necesario malloc y free por el instanceof y el del
	extern malloc, free
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float

; -----------------------
; PROCEDIMIENTO PRINCIPAL
; -----------------------
; En Class A
; msA() { printf 2; return 2; }
_A:
	push dword 2
	call print_int
	add esp,4
	call print_endofline
	mov eax, 2
	ret
; En Class B
; msB() { printf 4; return 4; }
_B:
	push dword 4
	call print_int
	add esp,4
	call print_endofline
	mov eax, 4
	ret
; En Class C
; ms C() { printf 7; return 7; }
_C:
	push dword 7
	call print_int
	add esp,4
	call print_endofline
	mov eax, 7
	ret

; En Class B se sobreescirbe msA
; msA() { printf 5; return 5; }
_BmsA:
	push dword 5
	call print_int
	add esp,4
	call print_endofline
	mov eax, 5
	ret
; En Class C se sobreescirbe msA
; msA() { printf 9; return 9; }
_CmsA:
	push dword 9
	call print_int
	add esp,4
	call print_endofline
	mov eax, 9
	ret
; En Class C se sobreescirbe msB
; msB() { printf 8; return 8; }
_CmsB:
	push dword 8
	call print_int
	add esp,4
	call print_endofline
	mov eax, 9
	ret

_no_defined_method:
	push dword 0
	call print_int
	add esp,4
	call print_endofline
	ret
; LOS MÉTODOS NO SOBREESCRIBIBLES
_mcA:
	push dword 1
	call print_int
	add esp,4
	call print_endofline
	ret
_mcB:
	push dword 3
	call print_int
	add esp,4
	call print_endofline
	ret
_mcC:
	push dword 6
	call print_int
	add esp,4
	call print_endofline
	ret
; SET OFFSETS SE HA IMPLEMENTADO EN ESTE EJEMPLO EN data
_set_offsets:
; ESTA HECHO COMO PARTE DEL SEGMENT .data
	ret
; CREATE MS TABLE
_create_ms_table:
	mov dword [_msA], _A			
; B SOBRE ESCRIBE msA1
	mov dword [_msB], _BmsA		
	mov dword [_msB+4], _B				
; C SOBRE ESCRIBE msA1
	mov dword [_msC], _CmsA		
; C SOBRE ESCRIBE msA2
	mov dword [_msC+4], _CmsB		
; C NO HEREDA DE B
	mov dword [_msC+8], _C			
	ret
