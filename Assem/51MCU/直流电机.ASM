org 0000H
Ljmp start

org 0030H
start:
	mov p1,#01H
	Acall Delay
	mov p1,#02H
	Acall Delay
jmp start 

Delay:
	mov r2,#05H
	L3:
		mov R3,#64H
		L2:
			Mov r4,#0c8H
			L1:NOP	
				NOP
				NoP
			Djnz r4,L1
		Djnz R3,L2
	Djnz r2,L3
ret
ENd