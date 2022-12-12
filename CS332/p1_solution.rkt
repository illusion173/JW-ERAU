#lang racket
(define l1 (list 2 4 10 8 6))
(define l2 (list 3 12 42 54))
(define l3 (list 60 40 -10 5))
(define l4 (list 5 6))
(define l5 (list 0 ))

( define MinMax (lambda ( op list )  (if (eq? (length list) 1)
                                        (car list)
                                        (if (op (car list) (MinMax op (cdr list)))
                                            (car list)
                                            (MinMax op (cdr list)))
                                     )  )
   )

(define GreatestDiff (lambda ( list1 list2 ) (if ( or (null? list1) (null? list2) )
                                                 "An empty list was input - results invalid."
                                                 (- (MinMax >  list1) (MinMax < list2) )  ) )
  )

; Test Cases
(GreatestDiff l1 l1)
(GreatestDiff l2 l3)
(GreatestDiff l3 l2)
(GreatestDiff l4 l5)
(GreatestDiff l5 l4)
