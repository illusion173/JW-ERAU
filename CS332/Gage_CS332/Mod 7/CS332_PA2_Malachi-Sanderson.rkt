#lang racket
;----------------------------------------------------------------------------------
;Malachi Gage Sanderson...
;CS332 Mod 7 Programming Assignment 2...
;PROBLEM: Intersecting Rectangles Problem: Given a rectangle, R, and a list of
;rectangles, L, return the list containing the elements in L that intersect with R.
;-----------------------------------------------------------------------------------


;---------------------------------------------------------------------------------------------------------------------
;MY ASSUMPTIONS AND STUFF...
;1.) Assume rectangles are on a normal positive 2D cartesian plane with 0,0 being the bottom left-most location
;2.) No negative positions.
;3.) Assume all rectangles must have a minimum height and width of 1 (no lines or points).
;4.) Assume the list must have a minimum of 1 rectangle inside of it.
;5.) Assume all rectangles are actually just rectangles with 4 corners represented by two points (4 total positive numbers)
;----------------------------------------------------------------------------------------------------------------------

;basic premise of how we check if rectangles overlap can be translated to this standard if statement...
;**R#.p# = rectangle #.list element #...**
                ;if(R0.XU >= Ri.XL  || Ri.XU >= R0.XL ) --> return false; ;checks if one rectangle is to left of other.
                ;else if( R0.YL >= Ri.YU || Ri.YL >= R0.YU) --> return false;  ;checks if one rectangle is above the other.
                ;else return true;


;NOTE: when calling this method but doing it for the Y part, need to invert the order so instead of upper lower its lower upper...
;Because the function above is repetitive in that it just does the if( A || B) statement twice just replacing X with Y
;this will just serve as a more generic form where you input if you wanna check X or Y as a param.
(define genericChecker (lambda (R0 Ri Upper Lower whatDoIfFail whatDoIfPass) ;upper = XU or YU   ;lower = XL or YL...for following comments assume selected X methods...
       (if (>= (Upper R0) (Lower Ri))  ;check R0.XU >= Ri.XL
            whatDoIfFail ;if true, you know it failed and this Ri doesn't overlap. 
            (if (>= (Upper Ri) (Lower R0));if false, check if Ri.XU >= R0.XL
                 whatDoIfFail ;if true, you know it failed and this Ri doesn't overlap.
                 whatDoIfPass ;it made it through (R0.XU >= Ri.XL  || Ri.XU >= R0.XL )...
            ) 
        )
))


;Following methods are used on a single Rect which will be segmented as defined in definitions section at bottom...

(define XU (lambda  (rect)  (car rect) ))
(define YU (lambda  (rect)  (car (cdr rect)) ))
(define XL (lambda  (rect)  (car (cdr (cdr rect))) ))
(define YL (lambda  (rect)  (car (cdr (cdr (cdr rect)))) ))



;fully checks if a rectangle (nuRect) overlaps with the another primary given rectangle (RectMain). If it does, it returns that successful overlapping rectangle...
(define runFullRectCheck (lambda (RectMain rList)
      (
           genericChecker RectMain (car rList) XU XL
                          null ;"Failed to detect overlap on X's" ;(list 0 0 0 0) ;fail to find overlap on X's
                          (
                             genericChecker RectMain (car rList) YL YU
                              null;"Failed to detect overlap on Y's" ;(list 0 0 0 0);fail to find overlap on Y's
                              (car rList)   ;find and confirms overlap by returning it to be added to OList...
                          )
      ))
)
;example test for above method: (define boy (list (runFullRectCheck Rect rectList)(runFullRectCheck Rect (cdr rectList)) (runFullRectCheck Rect (cdr (cdr rectList)))  (runFullRectCheck Rect (cdr (cdr (cdr rectList))))  (runFullRectCheck Rect (cdr (cdr (cdr( cdr rectList)))))   ))


;THIS IS PRIMARY FUNCTION THAT ACTUALLY DOES EVERYTHING!!!!
;Want this to basically just loop through each element in a list and compare it to the main rectangle...
(define compareAll (lambda (rList rectMain)
   (cond
        ((null? rList)
         null)
        ((list? (car rList))
         (remove rList (cons (runFullRectCheck rectMain  rList) (compareAll (cdr rList) rectMain)))
          )
        (else
          "ERROR" )
       )
))




;-------------------------------------------------------------------------------------------------
;PROVIDED EXAMPLE TEST SCENARIO A....

;R = (list 1 3 5 2) ;we are checking if other rectangles overlap this one... 
;r1 = (list 2 4 6 1) 
;r2 = (list 1 8 4 4)
;r3 = (list 0 5 4 0 0) ;??? MUTANT 5 POINT RECTANGLE???? Imma assume this was a Danny error.

"-------------------------------------------------"
"++++++Test Case A++++++++"
"Inputs..."
"     R = (1 3 5 2)"
"     List( (2 4 6 1)  (1 8 4 4) (0 5 4 0)"


"Expected Output..."
"     ( (2 4 6 1) (0 5 4 0) )"

"Actual Output..."
(compareAll (list (list 2 4 6 1) (list 1 8 4 4) (list 0 5 4 0) )  (list 1 3 5 2))
"---------------------------------------------------"
;------------------------------------------------------------------------------------------------




;-------------------------------------------------------------------------------------------------
;PROVIDED EXAMPLE TEST SCENARIO B....

;R = (list 2 6 4 2) ;we are checking if other rectangles overlap this one... 
;r1 = (list 2 4 6 1) 
;r2 = (list 1 8 4 4)
;r3 = (list 0 5 4 0 0) ;??? MUTANT 5 POINT RECTANGLE???? Imma assume this was a Danny error.
"---------------------------------------------------"
"++++++Test Case B++++++++"
"Inputs..."
"     R = (2 6 4 2)"
"     List( (2 4 6 1)  (1 8 4 4) (0 5 4 0)"

"Expected Output..."
"     ( (2 4 6 1) (1 8 4 4) )"

"Actual Output..."
(compareAll (list (list 2 4 6 1) (list 1 8 4 4) (list 0 5 4 0) )  (list 2 6 4 2))
"---------------------------------------------------"

;------------------------------------------------------------------------------------------------





;-------------------------------------------------------------------------------------------------
;PERSONAL EXAMPLE TEST SCENARIO....

(define Rect (list 1 13 7 5)) ;we are checking if other rectangles overlap this one... 
;(define ra (list 0 16 3 11)) ;TRUE -- does overlap...
;(define rb (list 2 10 3 8)) ;TRUE -- does overlap...
;(define rc (list 1 3 3 1)) ;FALSE -- doesn't overlap...
;(define rd (list 5 14 9 8)) ;TRUE -- does overlap...
;(define rectList (list ra rb rc rd)) ;list of rectangles which to compare with Rect
(define rectList (list (list 0 16 3 11) (list 2 10 3 8) (list 1 3 3 1) (list 5 14 9 8)  ) )

;TO TEST CODE JUST DO:
"TESTING Rect(1 13 7 5) against rectList" rectList
"Overlapping Rectangles include..."
(compareAll rectList Rect)


;------------------------------------------------------------------------------------------------
;DEFINITIONS...
;A rectangle is defined as a 4-tuple, r = ( XU, YU, XL, YL ), where (XU, YU) specifies the x-, y-coordinates
;of the upper left corner of the rectangle, and (XL, YL) specifies the x-, y-coordinates of the lower right
;corner of the rectangle. For this program, assume all rectangle edges are aligned with the X- and Y-axes.
;There are no "tilted" rectangles.


;A list of rectangles, rl = (r1, r2, r3, .... rn) = ( (xu1 yu1 xl1 yl1)  (xu2 yu2 xl2 yl2) ... (xun yun xln yln) ).


;Two rectangles, R1 and R2, intersect if and only if they share points interior to each rectangle.
;Rectangles that share points only on the edges do not intersect.






























;***********************************MOSTLY POINTLESS EXTRA WORK/CODE****************************
;My main compareAll method was inspired heavily by this code which was inspired by page at source below...
;source: [https://stackoverflow.com/questions/51812795/racket-add-a-number-to-each-element-of-nested-list]
(define doThingy (lambda (num)
         (cond
                [(number? num) (+ num 2)]
                [(list? num) (map (curry doThingy) num)]
                [else num]
         )
))

(define forAllComp (lambda (rList)
      (cond
        ((null? rList)
         null)
        ((list? (car rList))
         (cons (doThingy (car rList)) (forAllComp (cdr rList)))
          )
        (else
         (cons (+ 1 (car rList))
               (forAllComp (cdr rList))))
       )
 ))

;(forAllComp (list  (list 1 2 3)  (list 4 5 6) (list 7 8 9) ))


