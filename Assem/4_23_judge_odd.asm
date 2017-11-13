DATA SEGMENT
	NUM1 DB 45H
	NUM2 DB 0AEH
	DATA1 DB 0
	DATA2 DB 0
DATA ENDS

CODE SEGMENT
	ASSUME CS:CODE,DS:DATA

BEGIN:
	MOV AX, DATA
	MOV DS, AX
	MOV AL, NUM1
	MOV AH, NUM2
	TEST AL, 01H       ;45H与01H相与,结果不全为0(奇数),使ZF = 0
	JNZ NEXT1          ;若AL为奇数跳转至NEXT1
	TEST AH, 01H       ;AE与01相与
	JNZ NEXT2          ;若为奇数,跳转至NEXT2
	INC AL             ;若AL,AH同为偶数,AL+1
	INC AH             ;AH+1
	JMP ENDO           ;跳转至ENDO
	
NEXT2:
	XCHG AL,AH         ;交换两数
	JMP ENDO
NEXT1:
	TEST AH,01H        ;若AH为偶数,AF的值与01相与,ZF = 1
	JZ ENDO            ;若AH为偶数跳转至endo
	DEC AL             ;否则AL -1, AH-1
	DEC AH
ENDO:                  
    MOV DATA1,AL       ;结果送给data1    DS:0002 = 45      
    MOV DATA2,AH       ;结果送给data2    DS:0003 = AE
    
    MOV AH,4CH         ;返回DOS
    INT 21H
CODE ENDS
    END BEGIN
