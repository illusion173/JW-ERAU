#include "ws_unity_intro_functions.h"

void swap_c_1(uint32_t *x, uint32_t *y) {
    if (*x != *y) {
        uint32_t temp = *x;
        *x = *y;
        *y = temp;
    }
}

void rank_ascending_c(uint32_t *pArray, uint32_t n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (*(pArray + j) > *(pArray + j+1)) {
                swap_c_1((pArray + j), (pArray + j+1));
            }
        }
    }
}

void rank_descending_c(uint32_t *pArray, uint32_t n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (*(pArray + j) < *(pArray + j+1)) {
                swap_c_1((pArray + j), (pArray + j+1));
            }
        }
    }
}
