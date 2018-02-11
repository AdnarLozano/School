#|
  Adnar Lozano
  CSE-320
  Lab 1
  09/23/17
|#

#lang plai-typed

; define a type MisspelledAnimal with two sub classes caml and yacc
; each have a numerical constructor as argument for humps and height
(define-type MisspelledAnimal
    [caml (humps : number)]
    [yacc (height : number)])

; construct instances
(caml 2)
(yacc 1.9)
     
; create 2 instances ma1 and ma2 respectively
; the PLAI will infer types so no need to bind the instances to the name
(define ma1 (caml 2))
(define ma2 (yacc 1.9))

; define a pattern-matching boolean expression or function
; i will call it test1
(define (test1 [ma : MisspelledAnimal]) : boolean
  (type-case MisspelledAnimal ma
    [caml (humps) (>= humps 2)]
    [yacc (height) (> height 2.1)]))

; another way to write the same function as above, call it test2
(define (test2 [ma : MisspelledAnimal]) : boolean
    (type-case MisspelledAnimal ma
      [caml (h) (>= h 2)]
      [yacc (h) (> h 2.1)]))

; using selectors to extract fields without pattern-matching, call it test3
(define (test3 [ma : MisspelledAnimal]) : boolean
    (cond
      [(caml? ma) (>= (caml-humps ma) 2)]
      [(yacc? ma) (> (yacc-height ma) 2.1)]))

; test the boolean functions
(test (test1 ma1) #t)
(test (test1 ma2) #f)
(test (test2 ma1) #t)
(test (test2 ma2) #f)
(test (test3 ma1) #t)
(test (test3 ma2) #f)

; Now, i will mis-apply functions to the wrong kinds of values
; 1) let's give the caml constructor a string
; 2) let's send a number into each version of test#
(caml "Camel")
(test (test1 ma1) 3.14)
(test (test2 ma2) 2)
(test (test3 ma1) 4.64)