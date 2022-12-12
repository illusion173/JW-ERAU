#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Integer Argument expected!\n");
    return 1;
  }
  char *addr_string = argv[1];
  uint32_t address = strtol(addr_string, NULL, 10);
  printf("The address %u contains:\n", address);
  uint32_t page_size = 512;
  uint32_t page = address / page_size;
  printf("page number = %u\n", page);
  uint32_t offset = address % page_size;
  printf("offset = %u\n", offset);
}
