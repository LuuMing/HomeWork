delay proc delay
;in pram:bx
;
;
	push cx
delay_0:
	mov cx,0000H
delay_1:
	loop delay_1
 	dec bx
	jnz delay_0
	pop cx
	ret
delay endp
