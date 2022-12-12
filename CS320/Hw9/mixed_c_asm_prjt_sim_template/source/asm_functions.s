			AREA my_fancy_asm_code, CODE, READONLY ; Define the program area
			; Export functions defined in this file.
			; in the file calling them.
			EXPORT func_if_then_impl_1
			EXPORT func_if_then_impl_2
			EXPORT func_if_then_or_impl_1
			EXPORT func_if_then_or_impl_2
			EXPORT func_if_then_else_impl_1
			EXPORT func_if_then_else_impl_2
			EXPORT func_for_loop
			EXPORT func_while_loop
			ALIGN ; Align the data in the boundary of 4 bytes.
	myMC	PROC
			MACRO ; start macro definition
			initialize_r1_r2
			MOV r1, #-4 ; variable a in the C code
			MOV r2, #1 ; variable x in the assembly code
			MEND ; end macro definition
			ENDP
			; Simple if-then statements:
			; a. Implementation 1:
func_if_then_impl_1 PROC
			initialize_r1_r2
			; Put your code here. Note that you have to use BX lr to return to the caller.
			
			CMP r1, #0
			BGE endif
then 		RSB r1, r1, #0		
endif		ADD r2, r2, #1
			BX   lr
			ENDP
				
			; b. Implementation 2:
func_if_then_impl_2 PROC
			initialize_r1_r2
			; Put your code here. Note that you have to use BX lr to return  to the caller.
			CMP r1, #0
			RSBLT r1
			
			BX   lr
			ENDP
				
				
			; Simple if-then statement with compound logic OR expression:
			; a. Implementation 1:
func_if_then_or_impl_1 PROC
			initialize_r1_r2
			; Put your code here. Note that you have to use BX lr to return to the caller.
			BX   lr
			ENDP
				
			; b. Implementation 2:
func_if_then_or_impl_2 PROC
			initialize_r1_r2
			; Put your code here. Note that you have to use BX lr to return to the caller.
			BX   lr
			ENDP
				
			; Simple if-then-else statement:
			; a. Implementation 1:
func_if_then_else_impl_1 PROC
			initialize_r1_r2
			; Put your code here. Note that you have to use BX lr to return to the caller.
			BX   lr
			ENDP
				
			; b. Implementation 2
func_if_then_else_impl_2 PROC
			initialize_r1_r2
			; Put your code here. Note that you have to use BX lr to return to the caller.
			BX   lr
			ENDP
				
			; The for loop---a simple example
func_for_loop PROC
			; Put your code here. Note that you have to use BX lr to return to the caller.
			BX   lr
			ENDP
				
			; The while loop---a simple example
func_while_loop PROC
			; Put your code here. Note that you have to use BX lr to return to the caller.
			BX   lr
			ENDP
				
				
			END ; End of the entire file