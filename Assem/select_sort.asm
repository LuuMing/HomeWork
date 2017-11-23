data segment
    BUF db 26,20,23,21,12,45,62,4,2,5,6,12
    count equ $-BUF
data ends     
code segment
    assume ds:data,cs:code
start:
    mov ax,data
    mov ds,ax
    mov cx,count
    lea si,buf
  
loop1:
    push cx
    push si
    mov al,[si]                    

loop2: 
    cmp al,[si]
    jb notchange
    mov al,[si]
    mov bx,si                      ;al保存当前值
notchange:                         ;bx保存比当前值最小的偏移地址
    inc si
    loop loop2

    pop si
    xchg al,[si]                   ;使用si,al,bx分别保存 当前值,最小值,最小值位置
    xchg al,[bx]                   ;完成交换
                                   ;恢复cx,si    
    pop cx                                         
    inc si
    loop loop1

    mov ah,4ch
    int 21h
code ends
end start