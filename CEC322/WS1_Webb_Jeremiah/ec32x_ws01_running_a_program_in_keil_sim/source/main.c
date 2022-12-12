//Made/modified by Jeremiah Webb Student ID: 2545328
//#include <stm32l476xx.h>  // Comment out this file while using simulator
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint16_t ID1;
    uint32_t ID2;
} MyType;

bool need_to_print = true;
MyType myid;
MyType *p_id = &myid;
  
int main(void) {
    myid.ID1 = 5328;
    myid.ID2 = myid.ID1 + (myid.ID1 << 16);
    if (need_to_print) {
        printf("The values of my_ids in hexadecimal are %04x and %08x, respectively.\n", p_id->ID1, p_id->ID2);
    }
		printf("These are the addresses of ID1 and ID2: %p and %p,\n", &p_id->ID1, &p_id->ID2);
		
		printf("I certify that I, Jeremiah Webb, finished \n");
		printf("this work independently.\n");
    while (1);
}
