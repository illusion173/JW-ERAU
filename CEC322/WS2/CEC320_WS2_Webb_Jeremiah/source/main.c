//#include <stm32l476xx.h>  // Comment out this file while using simulator
#include <stdio.h>
#include <stdint.h>

uint16_t a[8] = {0xFFFF};
uint16_t b[8] = {0x0000};
uint16_t mask = 0b1111111111100111;
uint16_t value = 0b0000000000010000;

int main() {

// Task 1 
a[0] = (a[0] & mask) | value;
b[0] = (b[0] & mask) | value;
 
printf("Value of a[0] is 0x%04X and b[0] is 0x%04X.\n", a[0], b[0]);

// Task 2
a[1] = a[0] | b[0];
b[1] = a[0] & b[0];

printf("Value of a[1] is 0x%04X and b[1] is 0x%04X.\n", a[1], b[1]);

// Task 3

a[2] = ~a[1];
b[2] = a[1] ^ b[1];

printf("Value of a[2] is 0x%04X and b[2] is 0x%04X.\n", a[2], b[2]);
// Task 4
a[3] = a[0] || b[0];
b[3] = a[0] && b[0];

printf("Value of a[3] is 0x%04X and b[3] is 0x%04X.\n", a[3], b[3]);

// Task 5

printf("The addresses of a and b are 0x%p and 0x%p, respectively.\n", &a, &b);

}