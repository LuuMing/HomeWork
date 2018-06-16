org 0000H
ljmp start
I  equ 30H
J equ 40H
K equ 00H
M equ 50H
N equ 60H
org 0030H
start:
	mov I,#58H
	mov J,#97H
	mov A,I
	cjne A, J, not_equal
	mov K,#1
	sjmp continue
not_equal:
	mov  A,I
	subb A,J
	jb cy,B_greater_A
	mov M,I
	mov N,J
	sjmp continue
B_greater_A:
	mov M,J
	mov N,I
continue:
	sjmp $
end
