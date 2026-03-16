section .data
		list DB 1,2,3,4

section .text
global _start

_start:
		MOV eax,0
		MOV cl,0 ; numbers are small so declination fine

loop:
		MOV bl,[list + eax]
		ADD cl,block
		INC eax ; equivalent to eax++
		CMP eax,4 ; 4 being size of the array
		JE end
		JMP loop

end:
		MOV eax,1 ; argument for interrupt
		MOV ebx,1 ; argument for interrupt
		INT 80h
