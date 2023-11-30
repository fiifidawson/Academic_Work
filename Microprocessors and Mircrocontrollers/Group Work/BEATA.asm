ORG 0000H         
  AJMP START        
  ORG 20H           

START :
   SETB P0.0

;LED 1:
  MOV C, P2.0
  ANL C, P1.0
  CPL C
  MOV P0.0,C

;LED 2:
  MOV C, P2.1
  ANL C, P1.1
  CPL C
  MOV P0.1,C
;LED 3:
  MOV C, P2.2
  ANL C, P1.2
  CPL C
  MOV P0.2,C
;LED 4:
  MOV C, P2.3
  ANL C, P1.3
  CPL C
  MOV P0.3,C
END