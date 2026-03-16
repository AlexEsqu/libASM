section .data

section .text
global main

addTwo:
		PUSH ebp		; store base pointer as delimiter of set aside stack for function
		MOV ebp, esp
		MOV eax,[ebp+8] ; move into eax argument one
		MOV ebx,[ebp+12]; more into ebx argument two
		ADD eax,ebx
		POP ebp			; pop original base pointer
		RET				; pop off stack pointer address to jump to it

main:
		MOV eax,4
		MOV ebx,1
		CALL addTwo
		MOV ebx,eax
		MOV eax,1
		INT 80h
