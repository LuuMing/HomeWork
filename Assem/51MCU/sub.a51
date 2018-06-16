org  0000h
Ljmp  start
org  0050h
start:
	MOV R0,#93H
	MOV R1,#79H
	MOV R2,#25H
	MOV R3,#0A4H
	clr a
	mov A,R1
	subb A,R3
	mov r5,A
	clr a
	mov A,r0
	subb A,R2
	mov R4,A
//	 P = 1, ov = 1, ac = 1, cy = 0
ss:
	jmp  ss 
end
