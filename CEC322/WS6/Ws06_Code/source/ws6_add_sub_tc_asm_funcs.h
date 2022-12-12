#ifndef __WS6_ADD_SUB_TC_ASM_FUNCS_H
#define __WS6_ADD_SUB_TC_ASM_FUNCS_H
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#include <stdint.h>
extern uint64_t determine_data_order(uint64_t x, uint64_t y);
extern uint64_t add_uint64_s(uint64_t x, uint64_t y);
extern uint64_t sub_uint64_s(uint64_t x, uint64_t y);
extern int64_t tc_uint64_to_int64_s(uint64_t x);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __WS6_ADD_SUB_TC_ASM_FUNCS_H */