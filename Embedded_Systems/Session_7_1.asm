	ORG 0000H
	SJMP START
	ORG 20h

START:
    	CLR P2.1    

LOOP:
    	JNB P1.0, LOOP   
    	CPL P2.1    
    	SETB C    
    	SJMP LOOP  
    	END
    	
REPEAT: MOV C, P1.O
    	JC REPEAT
    	CALL SWITCH
    	CPL OOH
    	SJMP REPEAT
SWITCH: MOV C, 00H
    	MOV P2.0
    	RET
    	
DELAY: 