ORG 0000H
ljmp start
org 0003H
LJMP service

org 0030H
start:
	clr IT0
	SETB EA
	SETB EX0
	mov A,#0FEH
	MOV p1,A
	loop:
	mov p1,#00H
	jmp loop

ORG 0100H
service:
	RL A
	mov p1,A
	call delay
	reti	
Delay:
	mov r2,#10H
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
