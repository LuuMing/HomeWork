ORG 0000H

LJMP MAIN

ORG 0030H

MAIN:

MOV A,R5

LCALL L1

MOV B,#64H

MUL AB

MOV R6,A

XCH A,B

MOV R5,A

MOV A,R4

LCALL L1

ADD A,R6

MOV R4,A

MOV A,R5

ADDC A,#00H

MOV R5,A

SS:JMP SS

L1:

MOV R2,A

ANL A,#0F0H

SWAP A

MOV B,#0AH

MUL AB

MOV R3,A

MOV A,R2

ANL A,#0FH

ADD A,R3

RET

END
