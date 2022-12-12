#ifndef __PRINT_BINARY_H
#define __PRINT_BINARY_H
#ifdef __cplusplus
extern "C" {
#endif
////////////////////////////////////////////////
#include <stdint.h>
void convert_uint16_number_to_binary_str(uint16_t num, char *cPtr);
void print_str_compact(uint16_t num, char *cPtr);
void print_str_verbose(uint16_t num, char *cPtr_c, char *cPtr_v);
////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif
#endif /* __PRINT_BINARY_H */

