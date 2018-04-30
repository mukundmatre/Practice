#include <stdio.h>

void reverse(int *array, size_t n);

void reverse(int *array, size_t n) {
  int temp = 0;
  if (n&1) {
    for (size_t i = 0; i < n/2; i++) {
      temp = array[i];
      array[i] = array[n-i-1];
      array[n-i-1] = temp;
    }
  }
}

int main(void) {
  int array[] = {0,1,2,3,4,5,6,7,8};
  //int *arr_ptr = array;
  size_t n = sizeof(array)/sizeof(array[0]);
  reverse(array, n);
  for (size_t i = 0; i < n; i++) {
    printf("%d\n", array[i]);
  }
  return 0;
}
