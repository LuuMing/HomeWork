data segment
music dw 1518,1805,1805,1704,2027,2027,2275,2027,1805,1704,1518,1518,1518
count equ ($-music)/2
data ends

code segment
	assume cs:code,ds:data
	mov ax,data
	mov ds,ax
start:
	mov cx,count
	lea si,music
loop_:
	mov dx,0303H
	mov al,00001100B       ;PC6置零
	out dx,al
	mov al,00000000B       ;PC0置零
	out dx,al             
			      ;8255初始化
	
	mov dx,0307H
	mov al,10110110B       ;10--计数器2  11--先读/写低字节 011--方式3 0--二进制数
	out dx,al
	                      ;8253初始化
	mov ax,[si]
	mov dx,0306H
	out dx,al
	mov al,ah
	out dx,al       
			      ;发声
	mov dx,0303H
	mov al,00001101B       ;PC6置1
	out dx,al
	mov al,00000001B
	out dx,al	      ;PC1置1
	
	call delay            ;延迟
	inc si
	loop loop_
	
	mov ah,4ch
	int 21h

delay proc delay
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
	