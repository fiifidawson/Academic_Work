	ORG 0000H
	LJMP START
	ORG 30H
START:	MOV TMOD, #02H ;TIMER 0 MODE 1
REPEAT: MOV TL0, #0FFH
	MOV TH0, #83H
	CPL P2.0
	SETB TR0
HERE:	JNB TF0, HERE
	CLR TR0
	CLR TF0
	AJMP REPEAT
	END