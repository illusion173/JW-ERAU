; Student: Jeremiah Webb
; Assignment: P1
; Class: CS332

#lang racket

; Define required test cases
(define l1 (list 2 4 10 8 6))
(define l2 (list 3 12 42 54))
(define l3 (list 60 40 -10 5))
(define l4 (list 5 6))
(define l5 (list 0 ))

; Define some new lists I chose fibonacci and some randoms for testing
(define l6 (list 1 1 2 3 5 8 13 21 34))
(define l7 (list -1 1 -2 3 -5 -13 21 -34))
(define l8 (list 3 6 9 12 15 18))
(define l9 (list 7 6 5 4 3 2 1))
(define l10 (list 1 2 3 4 5 6 7))


; Begin functions

( define min_max (lambda ( op list ) (if (eq? (length list ) 1)
									   (car list)
									   (if (op (car list) (min_max op (cdr list)))
										 (car list)
										 (min_max op (cdr list))
										 )
									   ) ) )

(define greatest_diff (lambda ( list1 list2 )(if ( or (null? list1) (null? list2))
												 "Empty list inputted!!! ERROR: Results invalid"
									 (- (min_max > list1) (min_max < list2)))))
(greatest_diff l1 l1)
(greatest_diff l2 l3)
(greatest_diff l3 l2)
(greatest_diff l4 l5)
(greatest_diff l5 l4)
(greatest_diff l6 l6)
(greatest_diff l6 l7)
(greatest_diff l7 l6)
(greatest_diff l8 l9)
(greatest_diff l9 l10)
