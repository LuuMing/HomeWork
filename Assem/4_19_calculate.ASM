
DATA SEGMENT                         ;定义数据段
	X DB 26H		     	;定义 X为字节类型，初始值为26H
	Y DB 54H		     	;定义 Y为字节类型，初始值为54H
	Z DW ?			     	;定义 Z为字节类型，用来保存结果。
DATA ENDS			     ;数据段结束

CODE SEGMENT			     ;定义代码段
	ASSUME CS:CODE, DS: DATA     	;将段与段寄存器关联起来
	
START:				     
	MOV AX , DATA		     
	MOV DS, AX		     ;设置数据段
	MOV AH, 00H		     
	MOV AL, X		     ;将X给AX    		   AX = 0026
	MOV BX, AX		     ;AX的值赋给BX		   BX = 0026		
	SHL AX, 1		     ;AX左移一位,相当于2X   	   AX = 004C 
	SHL AX, 1		     ;AX左移一位,相当于4X	   AX = 0098
	ADD BX ,AX		     ;AX加BX,相当于5X,保存在BX中   BX = 00BE		   
	MOV AH ,00h		     
	MOV AL, Y		     ;将Y给AX			   AX = 0054
	MOV CX, AX		     ;AX的值赋给CX                 CX = 0054
	SHL AX, 1		     ;AX左移一位,(2Y)    	   AX = 00AB
	SHL AX ,1		     ;AX再左移一位,(4Y)  	   AX = 0150
	SHL AX ,1		     ;AX再左移一位，(8Y)	   AX = 02A0
	SUB AX, CX		     ;AX-CX并保存在AX中(7Y)        AX = 024C
	ADD AX, BX		     ;5X+7Y保存在AX		   AX = 030A              
	SHR AX, 1		     ;AX右移一位(5X+7Y)/2          AX = 0185
	MOV Z, AX	             ;Z保存结果			   Z = 0185
	MOV AH, 4CH
	INT 21H
CODE ENDS
END START
HLT