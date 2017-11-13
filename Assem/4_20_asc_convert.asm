data segment
    abc db 43H                                                    
    abc1 db 0
data ends
CODE segment
    assume cs:CODE, ds:data
start:
    mov ax,data
    mov ds,ax                 ;设置数据段            
    mov bx,offset abc         ;将abc的偏移量给BX          BX = 0000    
    mov al, [bx]              ;使用BX作为基地址在DS段间接寻址将abc存储在al中    AL = 43
    inc bx                    ;BX+1                       BX = 0001
    cmp al, 3ah               ;比较无符号数abc与3a的大小，判断其为数字还是字母
    jc next                   ;43<3a 因此不发生跳转  
    sub al,37h                ;43H - 37H，保存在al        AL = 0C
    jmp next1                 ;无条件转移至next1
next:
    sub al,30h
next1:
    mov [bx],al               ;将0CH以间接寻址的方式给变量abc1 DS:0001 = 0C
    mov ah,4ch                ;
    int 21h                   ;返回dos                    
    CODE ends
    end start