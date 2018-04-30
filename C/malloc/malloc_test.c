#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char const *argv[]) {
  uint8_t *ptr = (uint8_t*) malloc(4*sizeof(uint8_t));
  *ptr = 1;
  *(ptr+1) = 2;
  *(ptr+2) = 3;
  *(ptr+3) = 4;
  *(ptr+4) = 5;
  printf("Values: %d %d %d %d %d\n", *ptr, *(ptr+1), *(ptr+2), *(ptr+3), *(ptr+4));
  return 0;
}
