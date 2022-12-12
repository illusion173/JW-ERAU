#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
extern void func_if_then_impl_1(void);
extern void func_if_then_impl_2(void);
extern void func_if_then_or_impl_1(void);
extern void func_if_then_or_impl_2(void);
extern void func_if_then_else_impl_1(void);
extern void func_if_then_else_impl_2(void);
extern void func_for_loop(void);
extern void func_while_loop(void);
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
func_if_then_impl_1();
func_if_then_impl_2();
// Simple if-then statement with compound logic OR expression:
INITIALIZE_vals;
if (x <= 20 || x >= 25) {
a = 1;
}
func_if_then_or_impl_1();
func_if_then_or_impl_2();
// Simple if-then-else statement:
INITIALIZE_vals;
if (a == 1) {
x = 3;
} else {
x = 4;
}
func_if_then_else_impl_1();
func_if_then_else_impl_2();
// The for loop---a simple example
total_sum = 0;
for (int i = 0; i < 10; i++) {
total_sum += i;
}
func_for_loop();
// The while loop---a simple example
	total_sum = 0;
	int i = 15;
while (i > 0) {
	total_sum += i;
	i--;
}
func_while_loop();
while (1);
}