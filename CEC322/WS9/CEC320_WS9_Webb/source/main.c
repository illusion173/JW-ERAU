#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

extern void func_if_then_impl_1(int32_t *ptr1, int32_t *ptr2);
extern void func_if_then_impl_2(int32_t *ptr1, int32_t *ptr2);
extern void func_if_then_or_impl_1(int32_t *ptr1, int32_t var2);
extern void func_if_then_or_impl_2(int32_t *ptr1, int32_t var2);
extern void func_if_then_else_impl_1(int32_t var1, int32_t *ptr2);
extern void func_if_then_else_impl_2(int32_t var1, int32_t *ptr2);
extern int32_t func_for_loop(int32_t);
extern int32_t func_while_loop(int32_t);
extern int32_t func_dowhile_loop(int32_t);

#define INITIALIZE_vals \
                a = -4;\
                x = 1;

int32_t a, x, total_sum;
int32_t a1 = -4;
int32_t x1 = 1;

int main(void) {
// Simple if-then statement:
    INITIALIZE_vals;
    if (a < 0) {
        a = 0 - a;
    }
    x += 1;
    printf("From c: a = %d; x = %d. \n", a, x);
    
    INITIALIZE_vals;
    func_if_then_impl_1(&a, &x);
    printf("From asm1: a = %d; x = %d. \n", a, x);
    INITIALIZE_vals;
    func_if_then_impl_2(&a, &x);
    printf("From asm2: a = %d; x = %d. \n", a, x);
    
// Simple if-then statement with compound logic OR expression:
    INITIALIZE_vals;
    if (x <= 20 || x >= 25) {
        a = 1;
    }
    printf("From c: a = %d; x = %d. \n", a, x);
    
    INITIALIZE_vals;
    func_if_then_or_impl_1(&a, x);
    printf("From asm1: a = %d; x = %d. \n", a, x);
    INITIALIZE_vals;
    func_if_then_or_impl_2(&a, x);
    printf("From asm2: a = %d; x = %d. \n", a, x);


// Simple if-then-else statement:
    INITIALIZE_vals;
    if (a == 1) {
        x = 3;
    } else {
        x = 4;
    }
    printf("From c: a = %d; x = %d. \n", a, x);

    INITIALIZE_vals;
    func_if_then_else_impl_1(a, &x);
    printf("From asm1: a = %d; x = %d. \n", a, x);
    INITIALIZE_vals;
    func_if_then_else_impl_2(a, &x);
    printf("From asm2: a = %d; x = %d. \n", a, x);
    
// The for loop---a simple example
    total_sum = 0;
    for (int i = 0; i < 10; i++) {
        total_sum += i;
    }
    printf("From C for loop: total_sum = %d. \n", total_sum);
   
    total_sum = 0;
    total_sum = func_for_loop(10);
    printf("From asm for loop: total_sum = %d. \n", total_sum);
    
// The while loop---a simple example
    total_sum = 0;
    int i = 9;
    while (i > 0) {
        total_sum += i;
        i--;
    }
    printf("From C while loop: total_sum = %d. \n", total_sum);
    
    total_sum = 0;
    total_sum = func_while_loop(9);
    printf("From asm while loop: total_sum = %d. \n", total_sum);
    
// The do-while loop---a simple example
    total_sum = 0;
    i = 9;
    do {
        total_sum += i;
        i--;
    } while (i > 0);
    
    printf("From C do-while loop: total_sum = %d. \n", total_sum);
    
    total_sum = 0;
    total_sum = func_dowhile_loop(9);
    printf("From asm do-while loop: total_sum = %d. \n", total_sum);
    
    while (1);
}
