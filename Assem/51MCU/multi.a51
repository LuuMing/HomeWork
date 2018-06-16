org 0000H
sjmp start
org 0030h
start:
mov 30H,#34H
mov 31H,#12H
mov 32H,#56H
mov A,30H
mov B,32H
mul AB
mov r4,A
mov R3,B
mov A,31H
mov B,32H
mul AB
add A,r3
mov r3,A
mov A,B
addc A,R2
mov R2,A
ss:sjmp ss
end