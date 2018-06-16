org 0000H
mov 20H,#39
mov 21H,#27
mov 22H,#13
mov 23H,#44
mov 24H,#78
mov 25H,#22
mov 26H,#6
mov 27H,#51
Ljmp start
org 0030H
start:
	call sort
	sjmp $

sort:
mov r6,#7	   ;8个数据，比较7次
s1:
	mov r0,#20H	;起始地址
	mov b,r6
	mov r7,b
	clr psw.5
s2:
	mov b,@R0	;取出前一个数
	inc r0
	mov a,@r0	;取出后一个数
	cjne a,b,s3	 ;后-前
s3:
	jnc N_JH	;大于则不用交换
	mov @r0,B   ;交换
	dec r0
	mov @r0,A
	inc r0
	setb psw.5	 ;设立交换标志位
N_JH:
	djnz r7,s2
	jnb psw.5,S_END	 ;没有交换过就结束
	djnz r6,s1
S_END:
	ret
end