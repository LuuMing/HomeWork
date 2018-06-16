ORG 0000H
ajmp start
org 0030H
start:
   clr EA
   clr ET0
   mov tmod,#00H
s_call:
	acall service
loop:
   jb TF0,s_call
   ajmp loop
;子程序
service:
   mov TH0,	#0E0H	 ;计数器赋初值
   mov TL0,	#18H	 ;
   setb TR0			 ;启动计数器
   clr tf0			 ;中断标志位清零
   cpl p1.0		
   ret

end
;晶振12MHZ,机器周期=1/12M*(12)=1us
;1ms,初值=2^13-1ms/1us=7192=1110000011000
;高8位=E0H,低5位=18H