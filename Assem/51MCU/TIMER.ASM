ORG 0000H
ajmp start
org 001BH
jmp service
org 0030H

start:
	mov A,#01H
	mov 70H,A
	mov TL1,#0C0H
	mov TH1,#63H
	setb EA
	setb ET1
	SETB TR1
again:
	mov R0,#50
loop:
	Cjne R0,#0,loop	
	RL A
	mov p1,A
	mov 70H,A
	ajmp again

service:
	dec R0
	mov Tl1,#0C0H
	mov TH1,#63H
	SETB tr1
	reti
end
	