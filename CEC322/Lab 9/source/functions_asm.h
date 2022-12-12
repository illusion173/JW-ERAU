#ifndef __FUNCTIONS_ASM_SOLN_H
#define __FUNCTIONS_ASM_SOLN_H

#ifdef __cplusplus
  extern "C" {
#endif /* __cplusplus */

#include <stdint.h>

// Functions defined in the .s file
void rank_ascending_s(int32_t *pArray, int32_t n);
void rank_descending_s(int32_t *pArray, int32_t n);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __FUNCTIONS_ASM_SOLN_H */
