;Class: CSE 313 Machine Organization Lab
;Section: 04
;Instructor: Thakshak Gudimetla
;Term: Spring 2017
;Name(s): Adnar Lozano Leon
;Lab#6: Faster Multiplication
	.ORIG x3000
	LD R5, M1
	LDR R0, R5, #0
	LD R5, M2
	LDR R4, R5, #0
	BRnz UNCHANGED

	AND R1, R1, #0
	ADD R1, R1, #2
	NOT R1, R1
	ADD R1, R1, #1
	AND R2, R2, #0

INLOOP	ADD R2, R2, #1
	ADD R0, R0, R1
	ADD R3, R0, R1
	BRzp INLOOP

OUTLOOP	ADD R0, R2, #0
	AND R2, R2, #0
	ADD R4, R4, #-1
	BRp INLOOP

UNCHANGED LD R5, M3
	STR R0, R5, #0
	HALT
M1	.FILL x3100
M2	.FILL x3101
M3	.FILL x3102
	.END