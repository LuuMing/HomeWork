org 0000H
jmp start
org 0030H
start:
	MOV A,#0FEH
	MOV P0,A
loop:
	Acall Delay
	RR A
	mov P0,A
jmp loop

Delay:
	mov r2,#05H
	L3:
		mov R3,#64H
		L2:
			Mov r4,#0c8H
			L1:
				NOP	
				NOP
				NoP
			Djnz r4,L1
		Djnz R3,L2
	Djnz r2,L3
ret
END