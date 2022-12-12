#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ws_unity_intro_functions.h"


#define N 8

uint32_t breakPointHere = 0;

int main(void) {
    uint32_t myID = 5328; //1234;   // The last 4 digit of your ERAU ID
    uint32_t  array1[N], array2[N];
    srand(myID);            // Seed the random number generator
    for (int i = 0; i < N; i++) {
        array1[i] = 2*rand();
        array2[i] = array1[i];
    }
    
    printf("Random array:\n");
    for (int i = 0; i < N; i++) {
        printf(" 0x%08X,", array1[i]);
    }
    printf("\n");
    
    // rank descending in c
    printf("Results after rank_descending_c:\n");
    breakPointHere++;
    rank_descending_c(array1, N);
    breakPointHere++;
    for (int i = 0; i < N; i++) {
        printf(" 0x%08X,", array1[i]);
    }
    printf("\n");

    
    while(1);
}
