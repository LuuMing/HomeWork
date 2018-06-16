data segment
dat db 100,-100,-100,100
count equ $-dat
result dw 0
data ends
code segment
     assume cs:code,ds:data
start:  
     mov ax,data
     mov ds,ax
     mov cx,count
     lea si,dat
     mov ax,0000H
loop_:
     mov bl,[si]
     call abs_of_bl
     add al,bl
     adc ah,00H
     inc si
     loop loop_
     mov result,ax
     
     mov ah,4ch
     int 21H

abs_of_bl proc near   
     cmp bl,0
     jnl end_abs
     neg bl    
end_abs:
     ret
code ends
end start