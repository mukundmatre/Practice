#include <stdio.h>
#include <stdlib.h>

void print_spiral(int array[4][4], int m, int n);


void print_spiral(int array[4][4] , int m, int n) {
  int top = 0;
  int bottom = m-1;
  int left = 0;
  int right = n-1;
  int dir = 0;
  while (top<=bottom && left<=right) {
    if (dir == 0) {
      for (int i = left; i <= right ; i++) {
        printf("%d ", array[top][i]);
      }
      top++;
    } else if (dir == 1) {
      for (int i = top; i <= bottom ; i++) {
        printf("%d ", array[i][right]);
      }
      right--;
    } else if (dir == 2) {
      for (int i = right; i >= left  ; i--) {
        printf("%d ", array[bottom][i]);
      }
      bottom--;
    } else {
      for (int i = bottom; i >= top  ; i--) {
        printf("%d ", array[i][left]);
      }
      left++;
    }
    printf("\n");
    dir = (dir+1)%4;
  }
}


int main(void) {
  int array[4][4] = {{1,2,3,4},
                    {5,6,7,8},
                    {9,0,1,2},
                    {3,4,5,6}};
  print_spiral(array, 4, 4);
  return 0;
}
