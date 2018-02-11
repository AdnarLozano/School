;Class: CSE 313 Machine Organization Lab
;Section: 04
;Instructor: Thakshak Gudimetla
;Term: Spring 2017
;Name(s): Student A and Student B
;Lab#Example: Hello World (i.e. the title)
;Description: LC-3 Program that displays
; " Hello World !" to the console
; Inputs: None
; Outputs: Hello World !
; Side Effects: None
; Run:	Assemble the program
;	Open the Simulate Software
;	Load the Assembled program(.obj file)
;	Run the code and see the output on the console

.ORIG x3000
LEA R0 , NM ;load address of string
PUTS
LEA R1 , HW
PUTS ;output string to console
NM .STRINGZ "Adnar Lozano"
HW .STRINGZ "Hello World !"
HALT ;end program
.END