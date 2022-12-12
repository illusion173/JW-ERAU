#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(void) {
uint16_t A[4] = {0x5555, 0x6666, 0x9999, 0xAAAA};
uint16_t B[4] = {0x6666, 0x7777, 0xAAAA, 0xBBBB};
uint16_t C[20];
uint16_t Mask = 7; // a mask for 3 bits
uint16_t NUM_of_bits_to_shift = 4;
uint16_t VALUE_to_assign = 5;
uint16_t *pInt;

//printf("The address of array C: %x\n", C);
printf("Please determine the values in Hexadecimal of C:\n");
pInt = &A[1];
C[0] = A[0] & B[0];
C[1] = A[1] | B[1];
C[2] = A[2] && B[2];
C[3] = A[3] ^ B[3];
C[4] = 15 % 4;
/*
C[5] = Mask << NUM_of_bits_to_shift;
*/
C[6] = ~(Mask << NUM_of_bits_to_shift);
C[7] = A[0] & ~(Mask << NUM_of_bits_to_shift);
C[8] = (VALUE_to_assign << NUM_of_bits_to_shift);
C[9] = A[1] | (VALUE_to_assign << NUM_of_bits_to_shift);
C[10] = *(pInt + 2);
C[11] = *pInt++;
C[12] = (*pInt)++;
C[13] = (*pInt);

printf("\n Answers in unsigned integer "u" \n");
for(uint16_t i=0;i<14;i++)
{
	printf("\nNumber [%d], Answer: %d \n", i, C[i]);
}

printf("\n Answer in hex x \n");
for(uint16_t i=0;i<14;i++)
{
	printf("\nNumber [%d], Answer: 0x%x	\n", i, C[i]);
}


}
