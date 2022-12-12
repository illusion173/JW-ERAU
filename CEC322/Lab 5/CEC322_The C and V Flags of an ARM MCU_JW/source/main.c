#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
void convert_uint8_number_to_binary_str(uint8_t num, char *cPtr);
void print_str_verbose(uint8_t num, char *cPtr_c, char *cPtr_v);
uint8_t sub_uint8(uint8_t x0, uint8_t x1, bool *c_flg);
int8_t sub_int8(int8_t x0, int8_t x1, bool *v_flg);

#define P 8 // the number of pairs of data to be operated on
#define N 8 // number of bits of the computer
#define MIN_UN 0 // min value of unsigned N-bit num
#define MAX_UN ((1 << N) - 1) // max value of unsigned N-bit num
#define MIN_IN (-(1 << (N-1)) ) // min value of signed N-bit num
#define MAX_IN ((1 << (N-1)) - 1) // max value of signed N-bit num

char str_c[30], str_v[30];
int8_t x[P][2];
uint8_t ru[P];
int8_t ri[P];
bool c[P], v[P];

//Convert Binary Code:
void convert_uint8_number_to_binary_str(uint8_t num, char *cPtr) {
	int numCharacters = 0;
	int i = 0;
	int temp = num;
	while(temp > 0){
		temp /= 2;
		numCharacters++;
	}
	while(num > 0) {
		if(num % 2 == 0)
		{
			cPtr[numCharacters -i -1] = '0';
		}
		else{
				cPtr[numCharacters -i - 1] = '1';
			}
		// cPtr++;
		i++;
		num /= 2;
	}

	 cPtr[numCharacters] = '\0';
}

void print_str_compact(uint8_t num, char *cPtr) {
	//compact no need _
	convert_uint8_number_to_binary_str(num, cPtr);
	printf("%s", cPtr);
}

void print_str_verbose(uint8_t num, char *cPtr_c, char *cPtr_v) {
	//Verbose needs _
	
	  int numCharacters = 0;
    int i = 0;
    uint8_t temp = num;
    while(temp > 0){
        temp >>= 1;
        numCharacters++;
    }
    numCharacters += (numCharacters - 1) / 4;
    
    while(num > 0) {
        if ((i + 1) % 5 == 0) {
            cPtr_v[numCharacters -i -1] = '_';
        } else {
            cPtr_v[numCharacters -i -1] = '0' + (num & 0b1);
            num >>= 1;
        }
        i++;
    }

    cPtr_v[numCharacters] = '\0';
	
	printf("ob%s", cPtr_v);
	
}

// return x0 - x1
uint8_t sub_uint8(uint8_t x0, uint8_t x1, bool *c_flg){
	if(x0 > x1)
	{
		*c_flg = 1;
	}
	else{
		*c_flg = 0;
	}
return((x0 - x1));
}

// return x0 - x1
int8_t sub_int8(int8_t x0, int8_t x1, bool *v_flg){
//Range [-2^n-1, 2^n-1 -1] [-128, 127]
	int result = x0 - x1;
	int limitbot = -128;
	int limittop = 127;
		
	if(result < limitbot || result > limittop){
		*v_flg = 1;
	}
	else{
		*v_flg = 0;
	}
	return((x0 - x1));
}

int main(void) {
	
	for (int i = 0; i < P; i++) {
		x[i][0] = rand() % MAX_UN + MIN_IN;
		x[i][1] = rand() % MAX_UN + MIN_IN;
		printf("x[%d] = %d, %d \n", i, x[i][0], x[i][1]);
		
		ru[i] = sub_uint8(x[i][0], x[i][1], &c[i]);
		printf("result_u = %d, C flag = %d\n", ru[i], c[i]);
		print_str_verbose(ru[i], str_c, str_v), printf("\n");
		
		ri[i] = sub_int8(x[i][0], x[i][1], &v[i]);
		printf("result_i = %d, V flag = %d\n", ri[i], v[i]);
		print_str_verbose(ri[i], str_c, str_v), printf("\n");
		
		int temp0 = (x[i][0] << (32-N));
		int temp1 = (x[i][1] << (32-N));
		int temp2 = temp0 - temp1;
		int temp = temp2 >> (32-N);
		
		printf("ARM result = %d\n", temp);
	}
while (1);
}