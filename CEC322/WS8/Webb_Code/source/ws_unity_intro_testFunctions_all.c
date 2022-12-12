#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "ws_unity_intro_functions.h"
#include "C:\pjct_arm\_lib\unity\unity.h"

void swap_c_1(uint32_t *x, uint32_t *y);
void setUp(void) {
}

void tearDown(void) {
}

void test_swap_c_1(void) {
    uint32_t a1[] = {0xFFFFFFFE, 3};
    uint32_t a2[] = {3, 0xFFFFFFFE};
    swap_c_1(&a2[0], &a2[1]);
    TEST_ASSERT_EQUAL_UINT32_ARRAY(a1, a2, 2);
    uint32_t a3[] = {0xFFFFFFF0, 3};
    uint32_t a4[] = {3, 0xFFFFFFF0};
    swap_c_1(&a4[0], &a4[1]);
    TEST_ASSERT_EQUAL_UINT32_ARRAY(a3, a4, 2);
		//Task 2
		uint32_t x = 16;
		uint32_t b = 16;
		swap_c_1(&x, &b);
		TEST_ASSERT_EQUAL_UINT16(x, b);
		x = -16;
		b = 16;
		swap_c_1(&x, &b);
		TEST_ASSERT_EQUAL_UINT16(x, b);

}

void test_rank_ascending_c(void) {
    uint32_t arr1[] = {0xDDDDDDDD, 0x12345678, 0, 0xFFFFFFFF, 0x88888888};
    uint32_t arr1asc[] = {0, 0x12345678, 0x88888888, 0xDDDDDDDD, 0xFFFFFFFF};
    rank_ascending_c(arr1, 5);
    TEST_ASSERT_EQUAL_UINT32_ARRAY(arr1asc, arr1, 5);
		
		uint32_t arr2[] = {1, 3, 5, 7, 2, 4, 6, 8};
		uint32_t arr3[] = {-1, 3, -5, 7, -2, 4, -6, 8};
		rank_ascending_c(arr2, 8);
		TEST_ASSERT_EQUAL_UINT32_ARRAY(arr3, arr2, 8);
		
		
}

void test_rank_desending_c(void) {
    uint32_t arr1[] = {0xDDDDDDDD, 0x12345678, 0, 0xFFFFFFFF, 0x88888888};
    uint32_t arr1des[] = {0xFFFFFFFF, 0xDDDDDDDD, 0x88888888, 0x12345678, 0};
    rank_descending_c(arr1, 5);
    TEST_ASSERT_EQUAL_UINT32_ARRAY(arr1des, arr1, 5);
		
		uint32_t arr2[] = {1, 3, 5, 7, 2, 4, 6, 8};
		uint32_t arr3[] = {-1, 3, -5, 7, -2, 4, -6, 8};
		rank_descending_c(arr2, 8);
		TEST_ASSERT_EQUAL_UINT32_ARRAY(arr3, arr2, 8);
		
}

void test_swap_c_1_fail(void){
	  uint32_t a1[] = {1, 3};
    uint32_t a2[] = {3, 2};
    swap_c_1(&a2[0], &a2[1]);
    TEST_ASSERT_EQUAL_UINT32_ARRAY(a1, a2, 2);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_swap_c_1);
    RUN_TEST(test_rank_ascending_c);
    RUN_TEST(test_rank_desending_c);
		RUN_TEST(test_swap_c_1_fail);
    UNITY_END();

    while(1);
}

