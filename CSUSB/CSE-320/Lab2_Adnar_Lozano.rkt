#|
  Adnar Lozano
  CSE-320
  Lab 2
  09/28/17
|#

#lang racket

;Write 5 examples of anonymous functions.
((lambda (x) (/ x 1)) 5)                          ; example # 1
((lambda (y) (+ y 2)) 8)                          ; example # 2
((lambda (z) (* z 3)) 7)                          ; example # 3
((lambda (u v) (+ u v)) 6 5)                      ; example # 4
((lambda (k l) (* k l)) 4 3)                      ; example # 5

;Write 5 examples of closures.
(define (adds x) (lambda (y) (+ x y)))            ; example # 1
(let ([plusOne (adds 1)])
     (print (plusOne 2))
     (newline))

(define (subtract x) (lambda (y) (- y x)))        ; example # 2 
(let ([minTwo (subtract 2)])
     (print (minTwo 3))
     (newline))

(define (multiply x) (lambda (y) (* x y)))        ; example # 3 
(let ([timesTwo (multiply 2)])
     (print (timesTwo 4))
     (newline))

(define (divide x) (lambda (y) (/ y x)))          ; example # 4
(let ([byThree (divide 3)])
     (print (byThree 9))
     (newline))

(define (times x) (lambda (y) (* x y)))           ; example # 5
(let ([again (times 5)])
     (print (again 5))
     (newline))

;Write 5 examples of currying.
(define (sum x y) (+ x y))                        ; example # 1
((curry sum) 1)
(((curry sum) 1) 2)

(define (del a b) (- a b))                        ; example # 2
((curry del) 10)
(((curry del) 10) 5)

(define (mul c d) (* c d))                        ; example # 3
((curry mul) 3)
(((curry mul) 3) 3)

(define (div e f) (/ e f))                        ; example # 4
((curry div) 20)
(((curry div) 20) 2)

(define (combine g h i) (+ g h i))                ; example # 5
((curry combine) 6)
(((curry combine) 6) 7)
((((curry combine) 6) 7) 8)

;Write 5 examples of partial application.
(define (summa x y) (+ x y))                      ; example # 1
(define curried_summa (curry summa))
((curried_summa) 1)
(((curried_summa) 1) 9)

(define (rest x y) (- x y))                       ; example # 2
(define curried_rest (curry rest))
((curried_rest) 3)
(((curried_rest) 3) 1)

(define (comb x y) (+ x y))                       ; example # 3
(define curried_comb (curry comb))
((curried_comb) 4)
(((curried_comb) 4) 5)

(define (multi x y) (* x y))                      ; example # 4
(define curried_multi (curry multi))
((curried_multi) 6)
(((curried_multi) 6) 7)

(define (divi x y) (/ x y))                       ; example # 5
(define curried_divi (curry divi))
(curried_summa)
((curried_divi) 20)
(((curried_divi) 20) 2)

;Write 5 functions taking functions as parameters.
(define (doOnce f x) (f x))                       ; example # 1
(define (divByTwo n) (/ n 2))
(doOnce divByTwo 10)

(define (doTwice f x) (f (f x)))                  ; example # 2
(define (multByFive n) (* n 5))
(doTwice multByFive 7)

(define (double f x) (f (f x)))                   ; example # 3
(define (add n) (+ n n))
(double add 50)

(define (triple f x) (f (f (f x))))               ; example # 4
(define (sqr n) (* n n))
(triple sqr 2)

(define (quad f x) (f (f (f (f x)))))             ; example # 5
(define (addFour n) (+ n 4))
(quad addFour 4)

;Write 5 functions returning functions.
(define (addFunc x) (lambda (y) (+ x y)))          ; example # 1
(define aTwo (addFunc 2))

(define (subFunc x) (lambda (y) ( x y)))           ; example # 2
(define sThree (subFunc 3))

(define (timesFunc x) (lambda (y) (* x y)))        ; example # 3
(define tFour (timesFunc 4))

(define (divFunc x) (lambda (y) (/ x y)))          ; example # 4
(define dFive (divFunc 5))

(define (sqrFunc) (lambda (y) (* y y)))            ; example # 5
(define square (sqrFunc))

;testing example # 5 for returning functions
;the result should be 9
(print (square 3))
