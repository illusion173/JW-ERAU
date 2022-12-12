#lang racket
;----------------------------------------------------------------------------------
;Malachi Gage Sanderson...
;CS332 Mod 7 Programming Assignment 3.2...
;PROBLEM: Encode a finite state machine in the Racket language using only the functional features
;of Racket. One of the following alphabets must be used: sigma = {0, 1}  or sigma = {a, b}.
;There is no required format for strings. Strings may be represented as strings or arrays of
;integers/characters
;
;-----------------------------------------------------------------------------------


;---------------------------------------------------------------------------------------------------------------------
;MY ASSUMPTIONS AND STUFF...
;1.) Similar to my java code, the code takes in one list:
;(this list will be known as the delta table) will just hold of a bunch of different integer pairs
;corresponding to each state...
;for example: given a machine with two states q0 and q1 where
;state 0 transitions to state 1 if given "a" and stays in state 0 if given "b"
;and for state 1 it stays in state one if given "a" or "b"... we would represent this with the list...
; deltaTable =  (list (1 0) (1 1) ); //the state numbers are assumed by the number of sub-lists in the delta list
;SO MAKE SURE TO NAME YOUR LISTS SEQUENTIALLY STARTING FROM ZERO AS JUST POSITIVE INTEGERS
;2.) It is assumed there will always be at least two states/transition pairs and that they will be inputted correctly (just one lit of pos integers and another of positive pairs of integers) 
;3.) It is assumed that any state listed will have a corresponding entry in the delta table intered in the same order
;(if you give state 0 has delta table entry (list 2 4)you must also have a entries for 2 and for 4).
;4.) We use the sigma = {a, b} alphabet exclusively.
;5.)
;----------------------------------------------------------------------------------------------------------------------

;NOTE: EXAMPLES FOR HOW TO USE THE PRIMARY METHODS ARE PROVIDED BELOW ALL OF THIS, DOWN IN THE EXAMPLES SECTION...

(define getTransitionA (lambda (deltaPair) (car deltaPair)  )  )

(define getTransitionB (lambda (deltaPair) (car (cdr deltaPair))  )  )

(define getCurrentState (lambda (currentState) (if(null? currentState) 0 currentState)))

;User gives an input string (can just be one input -- i.e. "a" or "aa" or "aba" -- or a list of diff chars) and
;a delta table, which should be a list that defines all states
;and transitions in the state machine as discussed above in assumptions section, and
;navigates to the ending state (defined by delta table) given the input string...
(define processInputs (lambda (inputList deltaList)
   (if(<= (length inputList) 0)
        0
        (cond
        ((null? inputList)
         null)
        ((list? inputList)
         (processSingleInput (car inputList) deltaList (processInputs (cdr inputList) deltaList))
          )
        (else
          "ERROR" )
       )
     ) 
))


;This just returns the nth element in a list...
(define (nth lst counter)
  (cond ((null? lst) (error 'nth "index out of bounds"))
        ((= counter 0) (first lst))
        (else (nth (cdr lst) (- counter 1)))))


;This one should never fail as it just reads directly from the delta table. There may be a situation where the processInputs method fails though.
(define processSingleInput (lambda (input deltaTable currentState)
   (if(null? input)
      (getCurrentState currentState)
      (if(char=? input #\b)
         (getTransitionB (nth deltaTable (getCurrentState currentState)));if input "b" means I want currState input B transition
          (if(char=? input #\a)
           (getTransitionA (nth deltaTable (getCurrentState currentState)));if input "a" means I want currState input A transition
           (printf "\nERROR INPUT A VALUE NOT IN ALPHABET (SIGMA = {a,b})!!!\n")
           )
        )
     )
))  



;-------------------------------------------------------------------------------------------------
;TEST SCENARIO A....
; L = ab*a + ba*b
;
;q0 = (list 0 2 4) 
;q1 = (list 1 1 1)
;q2 = (list 2 3 2)
;q3 = (list 3 1 1) 
;q4 = (list 4 4 5)
;q5 = (list 5 1 1)
;(define deltaTableList (list (list 0 2 4) (list 1 1 1) (list 2 3 2) (list 3 1 1) (list 4 4 5) (list 5 1 1)  )   )
;From q0 we wanna test what state we would be if we inputted: input = a
"-------------------------------------------------"
"++++++Test Case A++++++++"
"Language: L = ab*a + ba*b"
"     inputString = a"
"     List( (q0: A -->2 B-->4)  (q1: A -->1 B-->1) (q2: A -->3 B-->2) (q3: A -->1 B-->1) (q4: A -->4 B-->5) (q5: A -->1 B-->1)  )"
"    Start state = 2"


"Expected Output..."
" 3 "

"Actual Output..."
(processSingleInput  #\a (list '(2 4) '(1 1) '(3 2) '(1 1) '(4 5)  '(1 1) ) 2 ) ;returns 3
"---------------------------------------------------"

;------------------------------------------------------------------------------------------------



;-------------------------------------------------------------------------------------------------
;TEST SCENARIO B....
; L = ab*a + ba*b
;
;q0 = (list 2 4) 
;q1 = (list 1 1)
;q2 = (list 3 2)
;q3 = (list 1 1) 
;q4 = (list 4 5)
;q5 = (list 1 1)
;(define deltaTableList (list (list 2 4) (list 1 1) (list 3 2) (list 1 1) (list 4 5) (list 1 1)  )   )
;From q0 we wanna test what state we would be if we inputted: input = baab
"-------------------------------------------------"
"++++++Test Case B++++++++"
"Language: L = ab*a + ba*b "
"     inputString = baab"
"     List( (q0: A -->2 B-->4)  (q1: A -->1 B-->1) (q2: A -->3 B-->2) (q3: A -->1 B-->1) (q4: A -->4 B-->5) (q5: A -->1 B-->1)  )"
"     Start state is assumed q0  "


"Expected Output..."
" 5 "

"Actual Output..."
(processInputs (list #\b #\a #\a #\b ) (list '(2 4) '(1 1) '(3 2) '(1 1) '(4 5)  '(1 1))) ;should return 5 
"---------------------------------------------------"
;------------------------------------------------------------------------------------------------


;-------------------------------------------------------------------------------------------------
;TEST SCENARIO C....
; L = (aba)* + (bab)*
;
;q0 = '(1 5) 
;q1 = '(2 3)
;q2 = '(2 2)
;q3 = '(4 2) 
;q4 = '(1 2)
;q5 = '(6 2)
;q6 = '(2 7)
;q7 = '(2 5)
;From q0 we wanna test what state we would be if we inputted: input = aba
"-------------------------------------------------"
"++++++Test Case C++++++++"
"Language: L = (aba)* + (bab)* "
"     inputString = aba"
"     List( (q0: A -->1 B-->5)  (q1: A -->2 B-->3) (q2: A -->2 B-->2) (q3: A -->4 B-->2) (q4: A -->1 B-->2) (q5: A -->6 B-->2) (q6: A -->2 B-->7) (q7: A -->2 B-->5) )"
"     Start state is assumed q0  "


"Expected Output..."
" 4 "

"Actual Output..."
(processInputs (list #\a #\b #\a ) (list '(1 5) '(2 3) '(2 2) '(4 2) '(1 2) '(6 2) '(2 7) '(2 5) )) ;should return 4
"---------------------------------------------------"
;------------------------------------------------------------------------------------------------



;-------------------------------------------------------------------------------------------------
;TEST SCENARIO D....
; L = (aba)* + (bab)*
;
;q0 = '(1 5) 
;q1 = '(2 3)
;q2 = '(2 2)
;q3 = '(4 2) 
;q4 = '(1 2)
;q5 = '(6 2)
;q6 = '(2 7)
;q7 = '(2 5)
;From q0 we wanna test what state we would be if we inputted: input = baab
"-------------------------------------------------"
"++++++Test Case D++++++++"
"Language: L = (aba)* + (bab)* "
"     inputString = baab"
"     List( (q0: A -->1 B-->5)  (q1: A -->2 B-->3) (q2: A -->2 B-->2) (q3: A -->4 B-->2) (q4: A -->1 B-->2) (q5: A -->6 B-->2) (q6: A -->2 B-->7) (q7: A -->2 B-->5) )"
"     Start state is assumed q0  "


"Expected Output..."
" 2 "

"Actual Output..."
(processInputs (list #\b #\a #\a #\b  ) (list '(1 5) '(2 3) '(2 2) '(4 2) '(1 2) '(6 2) '(2 7) '(2 5) )) ;should return 2
"---------------------------------------------------"
;------------------------------------------------------------------------------------------------












