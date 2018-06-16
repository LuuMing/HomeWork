org 0000H
Ljmp start
org 0100H
start:
	mov A,#A8H
	mov B,#100
	DIV AB
	mov 30H,a
	mov A,B
	mov B,#10
	DIV AB 
	swap A
	add A,B
	mov 31H,a
JMP $
end