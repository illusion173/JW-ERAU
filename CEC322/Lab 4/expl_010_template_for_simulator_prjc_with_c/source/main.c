/*
Lab 4 CEC 322
Name: Jeremiah Webb
Student ID: 2545328
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

/*
int convertToInt(float x);
*/
float f1 = 3.1415;
float f2 = -10.5;
float f3 = 0;
float f4 = 0;

float f_sum, f_sub, f_mul;
int16_t A1, A2, A_sum, A_sub, A_mul;

// We use Qm.n format here:
int m = 7;
int n = 8;

float convertToFixed(float num1, int power){
	float temp = 0;
	
	temp = ((num1) * (pow(2, power)));
	return(temp);
}

int convertToInt(float num1){
	int temp = 0;
	temp = round(num1);
	return(temp);
}

int16_t fixedPointMul(int16_t a, int16_t b) {
	int32_t mul = (int32_t) a * (int32_t) b;
	return mul >> n;
}

float fromFixedPoint(A16_t i) {
	//Convert to a float first so that we will be able to divide and get the result out without
	//having integer division loose our bits!
	float f = i;
	float coeffecent = 1.0f / powf(2.0f, n);
	
	float result = f * coeffecent;

	
	return result;
}



int main(void) {
	
	printf("\nJeremiah Webb #2545328\n");
	// Calculate f * 2^n for both numbers convert to Fixed Point
	f3 = convertToFixed(f1, n);
	f4 = convertToFixed(f2, n);
	
	//Convert to integer from float
	A1 = convertToInt(f3);
	A2 = convertToInt(f4);
	
	printf("%d", A1);
	printf("%d", A2);
	
	printf("\nTask 2: Print Hexadecimal Forms of A1 and A2\n");
	printf("A1: 0x%X\n", A1);
	printf("A2: 0x%X\n", A2);

	//Do math Task 3;
	f_sum = f1 + f2;
	f_sub = f1 - f2;
	f_mul = f1 * f2;
	printf("\nTask 3: Calculate results using floating-point numbers directly\n");
	printf("\nFloat Point Addition: %f\n",f_sum);
	printf("Float Point Subtraction: %f\n",f_sub);
	printf("Float Point Multiplication: %f\n",f_mul);
	
	//Do Math Task 4
	A_sum = A1 + A2;
	
	A_sub = A1 - A2;
	
	A_mul = fixedPointMul(A1, A2);
	printf("Task 4. Calculate results using fixed-point numbers");
	printf("\nFixed Point Addition: %f\n", fromFixedPoint(A_sum));
	printf("Fixed Point Subtraction: %f\n",fromFixedPoint(A_sub));
	printf("Fixed Point Multiplication: %f\n",fromFixedPoint(A_mul));
}