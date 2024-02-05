; Please insert your code here.
    ORG 000H
    AJMP START
    ORG 20H
START:  
    SETB P0.0
    SETB P0.1
    SETB P0.2
    SETB P0.3
    ACALL DELAY
PAT: 
  MOV C, P1.0
    JNC PO
    JC PORTONE
PO:
    CLR P0.0
    SETB P0.1
    AJMP PAT
PORTONE:
    CLR P0.1
    SETB P0.0
    AJMP PAT
P1:
    CLR 
P2:
P3:
    

DELAY:
    MOV R0, #10H
TAP1:   MOV R1, #00H
TAP:    MOV R2, #00H
HERE:   DJNZ R2, HERE
  DJNZ R1, TAP
  DJNZ R0, TAP1
  RET
END