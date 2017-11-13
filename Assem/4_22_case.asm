data segment
    x db -12H
    result dw  0000H
data ends

code segment
    assume cs:code, ds:data
start:
    mov ax, data
    mov ds, ax            ;设置数据段
    mov al, x             ;取x给al
    test al , 0FFH        ;al与FFH相与,改变SF标志位。(字母开头加0)
    js next               ;符号位SF为1(负数)则跳转至next
    mov bl, al            ;否则将x复制到bl
    imul bl               ;计算(x^2)保存在ax  
    add ax,1              ;计算(x^2+1) 保存在ax
    jmp next1             ;跳转至next1
next:
    mov bl, 02H           
    imul bl               ;计算(2*x)保存在ax  
    add ax, 0005H         ;计算(2*x+5)保存在ax
next1:
    mov result, ax        ;将结果送给result      DS:0001 = FFE1 
    
    mov ah,4cH            ;返回dos
    int 21H               ;
code ends

end start
