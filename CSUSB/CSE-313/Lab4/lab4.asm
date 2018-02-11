;Class: CSE 313 Machine Organization Lab
;Section: 04
;Instructor: Thakshak Gudimetla
;Term: Spring 2017
;Name(s): Adnar Lozano Leon
;Lab#4: Fibonacci Numbers
	.ORIG X3000
	LDI R1, n
	AND R2, R2, #0		; initializes R2
	ADD R2, R2, #1		; R2 = 1
	ADD R2, R2, #-3		; R2 = 1 + -3 = -2
	ADD R2, R1, R2		; checks if its pos
	BRp POS
	AND R4, R4, #0		; initializes R4
	ADD R4, R4, #1		; F = 1 if it is neg
	STI R2, Fn		; store R2 result in Fn 
	BR skip
POS	AND R2, R2, #0		; clears R2
	ADD R2, R2, #1		; R2 = 1 , a=1
	AND R3, R3, #0		; initializes R3
	ADD R3, R3, #1		; R3 = 1  , b=1
	ADD R5, R1, #-2
FAB	ADD R4, R2, R3		; F = b + a
	ADD R2, R3, #0		; a = b
	ADD R3, R4, #0		; b = F
	ADD R5, R5, #-1	
	BRp FAB
	STI R4, Fn		; store R4 result in Fn
	AND R2, R2, #0		; clears R2
	ADD R2, R2, #1		; R2 = 1  , a
	AND R3, R3, #0		; clears R3
	ADD R3, R3, #1		; R3 = 1  , b
	AND R5, R5, #0
	ADD R5, R5, #2
FAB2	ADD R4, R2, R3		; F = b + a
	BRn NEG
	ADD R2, R3, #0		; a = b
	ADD R3, R4, #0		; b = F
	ADD R5, R5, #1		; i=i+1
	BRp FAB2
NEG	AND R6, R6, #0
	ADD R6, R5, #0		; N=i
	STI R6, N		; stores R6 in N
	STI R3, FN		; stores R3 result in FN
skip	
	HALT
n	.FILL X3100
Fn	.FILL x3101
N	.FILL x3102
FN	.FILL x3103
	.END