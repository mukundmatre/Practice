#include<stdio.h>
int *fun()
{
  static int count = 0;
  count++;
  int *ptr = &count;
  return ptr;
}

int main()
{
  printf("%d ", *fun());
  printf("%d \n", *fun());
  return 0;
}
