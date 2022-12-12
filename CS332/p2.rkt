#lang racket
(define clist1 (list (list 0 0 1)))
(define plist1 (list (list 5 5) (list 10 10) (list 15 15)))
(define clist2 (list (list 10 10 10) (list 20 20 20)))
(define plist2 (list (list 5 5) (list 1 10)  (list 10 15) (list 10 19) (list 19 10) (list 18 18)))
(define clist3 (list (list 5 10 5) (list 20 20 5)))
(define plist3 (list (list 7 8) (list 15 5) (list 18 18) (list 22 23)))

(define (distanceBtwn circle point) (sqrt (+ (expt (- (car point) (car circle)) 2) (expt(- (car (cdr point)) (car (cdr circle))) 2 ))))

(define (insideCircle? circle distance) (if (< distance (car (cdr (cdr circle))))
                                           #t
                                           #f))
(define (insideplist circle plist)
  (if (or (null? plist) (empty? circle))
     '()
     (if(insideCircle? circle (distanceBtwn circle (car plist)))
        (append (list (car plist)) (insideplist circle (cdr plist)))
        (insideplist circle (cdr plist))
        )
     )
  )

(define (findCircle biggest circ plist) (if (or (null? circ) (null? (cdr circ)))
                                               (list biggest (insideplist biggest plist))
                                               (if (< (length (insideplist biggest plist)) (length (insideplist (car(cdr circ)) plist)))
                                                   (findCircle (car (cdr circ)) (cdr circ) plist)
                                                   (findCircle biggest (cdr circ) plist)
                                                   )
                                               )
 )

    

(findCircle (car clist1) clist1 plist1)

(findCircle (car clist2) clist2 plist2)

(findCircle (car clist3) clist3 plist3)


