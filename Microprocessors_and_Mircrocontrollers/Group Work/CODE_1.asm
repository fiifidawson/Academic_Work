ORG 000H
AJMP Start
ORG 30H

Start:	Setb P0.0
pat:	MOV C, P1.1
	JC Start
	CLR P0.0
	AJMP pat
	END