#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void) {
  uint32_t *ptr = (uint32_t*)malloc(sizeof(uint32_t));
  *ptr = 0x01;
  uint8_t *c = (uint8_t*) ptr;
  printf("%x\n", *c);
  return 0;
}
