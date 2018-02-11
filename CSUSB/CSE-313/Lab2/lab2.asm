;Class: CSE 313 Machine Organization Lab
;Section: 04
;Instructor: Thakshak Gudimetla
;Term: Spring 2017
;Name(s): Adnar Lozano Leon
;Lab#2: ARITHMETIC FUNCTIONS
.ORIG x3000
LDI R1, X		; load x into r1
LDI R2, Y		; load y into r2
NOT R4, R2		; negate r2 put into r4
ADD R4, R4, #1		; add +1 into r4 (-r2)
ADD R3, R1, R4		; add r1 and r4 into r3
STI R3, XMY 		; store r3 into XmY
ADD R4, R1, #0
BRzp ZPX
NOT R4, R4
ADD R4, R4, #1
ZPX
STI R4, ABSX
ADD R5, R2, #0
BRzp ZPY
NOT R5, R5
ADD R5, R5, #1
ZPY
STI R5, ABSY
NOT R7, R5
ADD R7, R7, #1
ADD R6, R4, R7
BRp POS
BRz ZERO
BRn NEG
POS
AND R6, R6, x0
ADD R6, R6, #1
STI R6, Z
HALT
ZERO
AND R6, R6, x0
STI R6, Z
HALT
NEG
AND R6, R6, x0
ADD R6, R6, #2
STI R6, Z
HALT
X .FILL x3120
Y .FILL x3121
XMY .FILL x3122
ABSX .FILL x3123
ABSY .FILL x3124
Z .FILL x3125
.END
