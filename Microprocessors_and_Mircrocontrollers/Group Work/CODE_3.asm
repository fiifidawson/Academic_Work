ORG 000H
AJMP Start
ORG 30H

Start:	Setb P0.0
	Setb P0.1
	Setb P0.2
	Setb P0.3
	Setb P0.4
pat:	MOV C, P1.1
	JC Start
	CLR P0.0
	AJMP pat1
pat1:	MOV C, P1.1
	JC Start
	CLR P0.1
	AJMP pat2
pat2:	MOV C, P1.1
	JC Start
	CLR P0.0
	AJMP pat3
pat3:	MOV C, P1.1
	JC Start
	CLR P0.0
	AJMP pat
	END
	