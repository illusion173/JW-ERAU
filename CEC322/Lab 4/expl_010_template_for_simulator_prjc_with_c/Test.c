#include <stdio.h>
#include <stdint.h>
#include <math.h>

float f1 = 3.1415;
float f2 = -10.5;
float f_sum, f_sub, f_mul;

int16_t A1, A2, A_sum, A_sub, A_mul;
// We use Qm.n format here:
int m = 7;
int n = 8;

int16_t toFixedPoint(float);
float fromFixedPoint(int16_t fixed, float real, float* error);

int16_t fixedPointSum(int16_t, int16_t);
int16_t fixedPointSub(int16_t, int16_t);
int16_t fixedPointMul(int16_t, int16_t);

int main(void) {
	A1 = toFixedPoint(f1);
	A2 = toFixedPoint(f2);
	printf("Troy Neubauer #2543523");
	printf("A1: 0x%x (%d) ~= %f\n", A1, A1, f1);
	printf("A2: 0x%x (%d) ~= %f\n", A2, A2, f2);
	
	f_sum = f1 + f2;
	f_sub = f1 - f2;
	f_mul = f1 * f2;
	
	A_sum = fixedPointSum(A1, A2);
	A_sub = fixedPointSub(A1, A2);
	A_mul = fixedPointMul(A1, A2);
	
	float error;
	printf("\n");
	printf("sum: float: %f, fixed: %f +-%f\n", f_sum, fromFixedPoint(A_sum, f_sum, &error), error);
	printf("sub: float: %f, fixed: %f +-%f\n", f_sub, fromFixedPoint(A_sub, f_sub, &error), error);
	printf("mul: float: %f, fixed: %f +-%f\n", f_mul, fromFixedPoint(A_mul, f_mul, &error), error);
}

int16_t toFixedPoint(float f) {
	//For a Q7.8 format we mutiply by to 2^8 so that we don't loose any bits when rounding to an uint16_t
	float coeffecent = powf(2.0f, n);
	
	return roundf(f * coeffecent);
}

#define ABS(a) ((a < 0) ? -(a) : (a))

float fromFixedPoint(int16_t i, float realResult, float* error) {
	//Convert to a float first so that we will be able to divide and get the result out without
	//having integer division loose our bits!
	float f = i;
	float coeffecent = 1.0f / powf(2.0f, n);
	
	float result = f * coeffecent;
	if (error) {
		//Calculate the error if the user want it
		*error = ABS(result - realResult);
	}
	return result;
}

//Abstract all the fixed point math functions so that
int16_t fixedPointSum(int16_t a, int16_t b) {
	return a + b;
}

int16_t fixedPointSub(int16_t a, int16_t b) {
	return a - b;
}

int16_t fixedPointMul(int16_t a, int16_t b) {
	int32_t mul = (int32_t) a * (int32_t) b;
	return mul >> n;
}