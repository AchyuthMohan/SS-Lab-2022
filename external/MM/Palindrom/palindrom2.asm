DATA SEGMENT
       BLOCK1 db "mala"
       MSG1 db "Palindrom$"
       MSG2 db "Not palindrom$"
DATA ENDS

PRINT MACRO MSG
    MOV AH,09H
LEA DX,MSG
INT 21H
INT 3H
ENDM

EXTRA SEGMENT
    BLOCK2 db 09 dup(?)
EXTRA ENDS 

CODE SEGMENT 
    ASSUME DS:DATA, CS:CODE,ES:EXTRA
    START:
    MOV AX,DATA
    MOV DS,AX
    MOV AX,EXTRA 
    MOV ES,AX 
    LEA SI,BLOCK1
    LEA DI,BLOCK2+8
    MOV CX,0009H
    
    back: CLD 
    LODSB 
    STD
    STOSB
    LOOP back       
    LEA SI,BLOCK1
    LEA DI,BLOCK2  
    MOV CX,0009H
    CLD 
    REPZ CMPSB
    JNZ skip
    PRINT MSG1
    skip:PRINT MSG2  
    

CODE ENDS 
END START
    
    
