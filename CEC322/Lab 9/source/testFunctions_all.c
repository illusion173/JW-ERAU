#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "functions.h"
#include "functions_asm.h"
#include "C:\pjct_arm\_lib\unity\unity.h"

void test_swap_c_1(void) {
	int16_t a5[] = {16, 16};
    uint32_t a6[] = {16, 16};
    swap_c_1(&a6[0], &a6[1]);
    TEST_ASSERT_EQUAL_UINT16_ARRAY(a5, a6, 2);

	uint32_t a7[] = {16, -16};
    uint32_t a8[] = {-16, 16};
    swap_c_1(&a8[0], &a8[1]);
    TEST_ASSERT_EQUAL_UINT16_ARRAY(a7, a8, 2);
}


void test_rank_ascending_c(void) {
    uint32_t arr1[] = {1, 2, 0, 2, 1};
    int16_t arr1asc[] = {0, 1, 1, 2, 2};
    rank_ascending_c(arr1, 5);
    TEST_ASSERT_EQUAL_UINT16_ARRAY(arr1asc, arr1, 5);
	
	
	uint32_t arr2[] = {1, 3, 5, 7, 2, 4, 6, 8};
    int16_t arr2asc[] = {1, 2, 3, 4, 5, 6, 7, 8};
    rank_ascending_c(arr2, 8);
    TEST_ASSERT_EQUAL_UINT16_ARRAY(arr2asc, arr2, 8);
	
	
	uint32_t arr3[] = {-1, 3, -5, 7, -2, 4, -6, 8};
    int16_t arr3asc[] = {-6, -5, -2, -1, 3, 4, 7, 8};
    rank_ascending_c(arr3, 8);
    TEST_ASSERT_EQUAL_UINT16_ARRAY(arr3asc, arr3, 8);

}


void test_rank_desending_c(void) {
    uint32_t arr1[] = {1, 2, 0, 2, 1};
    int16_t arr1des[] = {2, 2, 1, 1, 0};
    rank_descending_c(arr1, 5);
    TEST_ASSERT_EQUAL_UINT16_ARRAY(arr1des, arr1, 5);
	
	uint32_t arr2[] = {1, 3, 5, 7, 2, 4, 6, 8};
    int16_t arr2des[] = {8, 7, 6, 5, 4, 3, 2, 1};
    rank_descending_c(arr2, 8);
    TEST_ASSERT_EQUAL_UINT16_ARRAY(arr2des, arr2, 8);
	
	
	uint32_t arr3[] = {-1, 3, -5, 7, -2, 4, -6, 8};
    int16_t arr3des[] = {8, 7, 4, 3, -1, -2, -5, -6};
    rank_descending_c(arr3, 8);
    TEST_ASSERT_EQUAL_UINT16_ARRAY(arr3des, arr3, 8);

}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_swap_c_1);
    RUN_TEST(test_rank_ascending_c);
    RUN_TEST(test_rank_desending_c);
    
    //RUN_TEST(test_rank_ascending_s);
    //RUN_TEST(test_rank_desending_s);
    
    UNITY_END();

    while(1);
}
