code segment
assume cs:code
	start:
	mov dx,0303H
	mov al,10000011B
	out dx,al
	mov dx,0302H
test_:
	in al,dx
	test al,04H
	jnz test_
	mov dx,0300H
	mov al,10000000B
	mov cx,800     ;Loop 800 times
loop_:
	out dx,al
	rol al,1
	call delay
	loop loop_
	mov ah,4ch
	int 21H

delay proc near
	push cx
	mov bx,00ffH
delay_0:
	mov cx,0000H
delay_1:
	loop delay_1
 	dec bx
	jnz delay_0
	pop cx
	ret
delay endp
code ends
end start