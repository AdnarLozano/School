#|
  Adnar Lozano
  CSE-320
  Lab 3
  10/5/17
|#
#lang racket

(define-syntax (swap stx)
  (syntax-case stx ()
    [(swap x y)
      (if (and (identifier? #'x)
              (identifier? #'y))
         #'(let ([tmp x])
             (set! x y)
             (set! y tmp))
         (raise-syntax-error #f
                             "not an identifier"
                             stx(if (identifier? #'x)
                                 #'y
                                 #'x)))]))

;define x and y, print them, swap them, and print swapped results.
(let ([x 1] [y 10])
  (printf "\nOriginal input\nx: ~a\ny: ~a\n" x y)
  (swap x y)
  (printf "After swapping\nx: ~a\ny: ~a" x y) )

;for-loop macro
(printf "\nImplementing my for-loop macro\n")

(define-syntax (for-loop stx)
  (syntax-case stx ()
    [(for-loop (i x y) body)
     (if (identifier? #'i)
         #'(if (and (number? x)
                    (number? y)
                    (<= x y))
           (for ([i (in-range x y)]) body)
           (error "not a number"))
         (raise-syntax-error #f
                             "not an identifier"
                             stx
                             ))]))

(for-loop (i 2 9) (printf "~a  " i))
