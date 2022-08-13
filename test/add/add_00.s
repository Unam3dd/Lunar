;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-48-08 18:48:19
;; Filename	: add_00
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public _start

section '.text' executable

_start:
	sub rsp, 0x8

add_00:
	mov rax, 0x5
	mov bl, 0x2
	mov byte [rsp], 0x30
	add byte [rsp], al 		; when use rsp scale is required so add instruction
							; have <add> <MODRM> <SIB> if rsp is used
	add bl, bl
	add rsp, 0x8
	ret
