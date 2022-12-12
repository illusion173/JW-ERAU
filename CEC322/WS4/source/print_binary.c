#include "print_binary.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void convert_uint16_number_to_binary_str(uint16_t num, char *cPtr) {
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
void print_str_compact(uint16_t num, char *cPtr) {
	//compact no need _
	convert_uint16_number_to_binary_str(num, cPtr);
	printf("%s", cPtr);

}
void print_str_verbose(uint16_t num, char *cPtr_c, char *cPtr_v) {
	//Verbose needs _
	
	  int numCharacters = 0;
    int i = 0;
    uint16_t temp = num;
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