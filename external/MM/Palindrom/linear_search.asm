DATA SEGMENT
    ARRAY DB 11H,22H,33H,44H,55H
    SE DB 33H 
    MSG1 DB "Found$"
    MSG2 DB "Not Found$"   
    
DATA ENDS    

PRINT MACRO MSG
    MOV AH,09H
    LEA DX,MSG
    INT 21H
    INT 3H
ENDM

CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
    START:
    MOV AX,DATA
    MOV DS,AX
    LEA SI,ARRAY
    MOV CX,05H 
   BACK: MOV BL,[SI]
    
    CMP SE,BL
    JZ  FO
    INC SI
    LOOP BACK
    PRINT MSG2
 
 
 FO: PRINT MSG1
CODE ENDS

END START
    
    
                    
                    