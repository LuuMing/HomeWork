code segment
    assume cs:code     
start:
    mov AX, -1234H
    cmp ax, 0		    ;比较ax与0的大小		
    jge next            ;若ax>0,跳转next
    neg ax              ;若ax<0,对求补
next:
    mov bx, ax          ;将结果保存在bx        BX = 1234
next1:
    mov ah, 4ch		;返回dos
    int 21h
code ends
end start