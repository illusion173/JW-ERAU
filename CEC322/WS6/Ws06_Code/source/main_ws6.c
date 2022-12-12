#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include "ws6_add_sub_tc_asm_funcs.h"
uint64_t A[] = {0x87777777FFFFFFFF, 0x9876543200000000};
uint64_t B[] = {0x0000000300000002, 0x1111111122222222, 0x0000000100000000};
uint64_t sum_A;
uint64_t sum_C;
uint64_t sub_A;
uint64_t sub_C;
int64_t tc_A;
int64_t tc_C;
int main(void) {
	determine_data_order(A[0], B[0]);
	sum_C = A[0] + B[0];
	printf("uint64 addition by C: 0x%" PRIX64 "\n", sum_C);
	sum_A = add_uint64_s(A[0], B[0]);
	printf("\nAddress of A and B respecively, %p AND %p \n", &A[0], &B[0]);
	printf("uint64 addition by asm: 0x%" PRIx64 "\n", sum_A);
	sub_C = A[1] - B[1];
	printf("\nAddress of A and B respecively, %p AND %p \n", &A[1], &B[1]);
	printf("uint64 subtraction by C: 0x%" PRIX64 "\n", sub_C);
	sub_A = sub_uint64_s(A[1], B[1]);
	printf("\nAddress of A and B respecively, %p AND %p \n", &A[1], &B[1]);
	printf("uint64 subtraction by asm: 0x%" PRIx64 "\n", sub_A);
	tc_C = - (int64_t) B[2];
	printf("\nAddress of A and B respecively, %p\n", &B[2]);
	printf("TC of B[2] by C: 0x%" PRIX64 "\n", tc_C);
	tc_A = tc_uint64_to_int64_s(B[2]);
	printf("\nAddress of A and B respecively, %p AND %p \n", &B[2]);
	printf("TC of B[2] by asm: 0x%" PRIx64 "\n", tc_A);
while (1);
}