section .data

section .text
global _start

_start:
		MOV eax,3
		MOV ebx,2
		CMP eax,ebx ; subtract register from each other,
					; set sign, overflow, carry flags registers
					; see if bigger/smaller/equal
					; then discard result

		JL lesser ; jump less than
		; automatically falls to following instruction if higher / equal

		JMP end ; jump always

lesser:
		MOV ecx,1
		; flows to end

end:
		INT 80h
