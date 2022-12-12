		AREA myfunctions, CODE
		EXPORT determine_data_order
		EXPORT add_uint64_s
		EXPORT sub_uint64_s
		EXPORT tc_uint64_to_int64_s
		ALIGN
determine_data_order PROC
		BX lr
		ENDP
add_uint64_s PROC
		ADDS R0, R2
		ADC R1, R3
		BX lr
		ENDP
sub_uint64_s PROC
		SUBS R0, R2
		SBC R1, R3
		BX lr
		ENDP
tc_uint64_to_int64_s PROC
		MVN R0, R0
		MVN R1, R1
		ADDS R0, #1
		ADC R1, #0
		BX lr
		ENDP
		END			