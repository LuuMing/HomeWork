data segment
dat db ?,?,?,?                                             ;数码管每一位的数字,保存在数据段,方便后续扩展
count equ ($-dat)
TableDot db  40H,79H,24H,30H,19H,12H,02H,78H,00H,10H       ;共阳管带小数点0-9
Table    db  0C0H,0f9H,0a4H,0b0H,99H,92H,82H,0f8H,80H,90H  ;共阳管不带小数点0-9
Vrefp db 5                                                 ;参考电压值
data ends

stack segment
db 100 dup(0)
stack ends

code segment
assume cs:code,ds:data,ss:stack
start:
	mov ax,data
	mov ds,ax
	mov ax,stack
	mov ss,ax
	mov sp,100
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;初始化
                         ;1111111111000XX0
	mov dx,0FFC6H        ;8255地址控制口           
	mov al,10011000B     ;1-特征位  00-A方式0  1-A输入 1-CH读入 0-B方式0 0-B输出 0-CL输出   
	out DX,al            ;写入控制字      

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;启动模数转换并读入数据
again:	
	mov dx,0FFC8H        ;启动ADC0809                     1111111111001XX0          
	mov al,11111000B     ; ADDA ADDB ADDC，选择通道0      XXXXX000
	out dx,al
	
	mov dx,0FFC4H      
	mov al,11100000B
	out dx,al             ;8255C口状态重置,再从8255读C口
		
	
ready:
	in al,dx
	cmp al,11110000B 
	jnz ready            ;等待ADC0809转换结束,否则循环检测
	mov dx,0FFC8H          
	in al,dx             ;读取转换数据

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;处理数据
	lea bx,dat
	mov cx,count
	mov ah,Vrefp  	
	mul ah               ;(VrefP * 读取数据)/255
	mov dl,0FFH	
loop_:
	div dl           
	mov [bx],al          ;将得到的数据保存起来
	mov al,ah            ;得到的余数给al
	mov ah,10
	mul ah               ;余数乘10
	inc bx
loop loop_
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;个位需要带小数点,因此单独处理
	xor bx,bx
	mov bl,dat
	mov dx,0FFC2H        ;8255B口
	mov al,TableDot[bx]
	out dx,al            ;输出到B口
	mov dx,0FFC4H       
	mov al,00000001B
	out dx,al           
	call delay
	mov al,00H
	out dx,al	         ;熄灭

	mov si,1
	mov cx,count
	dec cx
	mov ah,00000010B
;;;;;;;;;;;;;;;;;;;;;;;;;;;;十分位，百分位，千分位.....循环点亮
loop__:
	xor bx,bx            ;bx清零
	mov bl,dat[si]       ;从数据段取数据
	mov dx,0FFC2H        ;8255B口
	mov al,Table[bx]     ;在共阳表中找到数码管电平数据
	out dx,al            ;输出到B口
	mov dx,0FFC4H              
	mov al,ah
	out dx,al	         ;8255C口点亮数码管
	call delay           ;延时一段时间
	mov al,00H
	out dx,al	         ;熄灭
	inc si
	shl ah,1
loop loop__
	
	jmp again
;;;;;;;;;;;;;;;;;;;;;;;;;;;;

delay proc near
	push cx
	mov cx,00FFH
	loop $
	pop cx
	ret
delay endp
code ends
end start
