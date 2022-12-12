#include "lab02_c_functions.h"
#include <stdio.h>
// Count the number of binary 1's using Algorithm 1
uint32_t C_number_of_1s_alg1(uint32_t x) {
    uint32_t n_of_1 = 0;            // number of 1s of the input
    while (x) {
        n_of_1 += x >> 31;
        x = x << 1;
    }
    return n_of_1;
}


// Count the number of binary 1's using Algorithm 2
uint32_t C_number_of_1s_alg2(uint32_t x) {
    uint32_t y, z;
    uint32_t n_of_1 = x >> 31;      // number of 1s of the input
    while (x) {
        y = x << 2;
        z = y >> 31;
        if (x<<1 > y)
            n_of_1 += z + 1;
        else
            n_of_1 += z;
        x = y;
    }
    return n_of_1;
}


// Count the number of binary 1's using Algorithm 3
uint32_t C_number_of_1s_alg3(uint32_t x) {
    uint32_t n_of_1 = 0;            // number of 1s of the input
    while (x) {
        x = x & (x-1);
        n_of_1++;
    }
    return n_of_1;
}

void C_number_of_0_to_9s(uint32_t x, uint32_t result_arr[]) {
		for(uint32_t i = 0;  i < 10; i++){
			result_arr[i] = 0;
		}	
		if(x == 0){
		result_arr[0] = 1;
	}
	else{
			while (x != 0){
			uint32_t digit = x % 10;
			result_arr[digit]++;
			x = x / 10; 
			}
			}	

		for(uint32_t i = 0;  i < 10; i++){
			printf("#%d : %d, ", i, result_arr[i]);
		}	
		printf("\n");
}