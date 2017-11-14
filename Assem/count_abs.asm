data segment
dat db 1,-2,3,-4,5,-6,7,-8,9,-10
count equ $-dat
result db 0
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
     inc si
     loop loop_
     mov result,al
     
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