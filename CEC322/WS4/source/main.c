#include <stdio.h>
#include "print_binary.h"
char str_c[30], str_v[30];
int main(void) {
	uint16_t test_num[] = {0x1234, 0x5678, 0x9ABC, 0xDEF0};
	
	int N = sizeof(test_num) / sizeof(test_num[0]);
	
	printf("Testing the printout of binary numbers:\n");
	
	
	for (int i = 0; i < N; i++) {
		printf("Compact display for 0x%04X is ", test_num[i]);
		print_str_compact(test_num[i], str_c);
		printf("\n");
		printf("Verbose display for 0x%04X is ", test_num[i]);
		print_str_verbose(test_num[i], str_c, str_v);
		printf("\n");
	}
while (1);	
}

