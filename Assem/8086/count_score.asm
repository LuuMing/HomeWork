data segment
    score db 3 dup(76,54,87,65,98,100,92,80,55,56);
    count equ $-score   
    region db 0,0,0,0,0,0
data ends

code segment
    assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax
    
    mov cx,count
    lea si,score
comp:
     mov al,60    
     cmp [si],al
     jnb region_2                
     inc region
     jmp end_cmp
region_2:
     mov al,69
     cmp [si],al
     jnb region_3
     inc region+1 
     jmp end_cmp
region_3:
     mov al,79
     cmp [si],al  
     jnb region_4
     inc region+2
     jmp end_cmp
region_4:
     mov al,89     
     cmp [si],al
     jnb region_5
     inc region+3
     jmp end_cmp
region_5:
     mov al,99
     cmp [si],al
     jnb region_6
     inc region+4
     jmp end_cmp
region_6:
     inc region+5    
     
end_cmp:
     inc si
     loop comp

mov aH,4ch
int 21H 
code ends
end start
    
    