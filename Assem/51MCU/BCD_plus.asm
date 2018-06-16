org 0000H
ljmp start
org 0030H
start:
	mov r5,#98H
	mov r4,#76H
	mov r3,#54H
	mov r2,#32H

	mov A,r4
	ADD A,R2
	da a
	mov R4,A
	mov A,r5
	addc A,r3
	da a
	mov r5,A
	mov A,#0H
	addc A,#0H
	da a
	mov r6,A
end
