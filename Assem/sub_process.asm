data segment
ARY dw 10,1,2,3,4,5,6,7,8,9,10
sum dw 0
data ends
code segment
	assume ds:data,cs:code
start:
	mov ax,data
	mov ds,ax
	call sum_ 
	mov sum,ax
	mov ah,4ch
	int 21h
	hlt
sum_ proc near          ;求和子程序
	push cx        ;入口 ARY
	push si        ;出口 AX
	mov cx,ARY
	lea si,ARY 
	mov ax,0000H
	
loop_:  
	add si,2
	add ax,[si]
	loop loop_ 
	pop si
	pop cx 
	ret 
code ends
end start