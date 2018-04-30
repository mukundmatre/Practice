#include <stdio.h>
#include <stdlib.h>

/* temp valiable needed, keep finding minimum in array till you reach the end*/
void selection_sort(int* A, int length);

/* temp variable needed, adjacent value comparison, maximum value bubbles up
to the end, exit loop once sorted, keep decreasing array size as larger values
accumulate towards the end*/
void bubble_sort(int* A, int length);

/* temp needed, start with first element in the left and keep on adding elements
by comparing previous element, if prev element is lesser, the array is sorted till
that point, so break from inner loop(less no. of operations, faster)*/
void insertion_sort(int* A, int length);

/* recursive, two arrays needed, copy contents to left and right arrays respectively
, call merge_sort recursively for both and then merge it into main array(take lesser
among left and right elements and finally copy all remaining elements)*/
void merge_sort(int* A, int length);
void merge(int* A, int* left, int left_len, int* right, int right_len);

/*partition:- swap adjecent elements if items greater than pivot occur, finally
there will be elements lesser than pivot(A[end]) before part_index(in no order)
quick_sort:- get part_index from partition func and call quick sort recursively until
start==end (only 1 element left)*/
void quick_sort(int* A, int start, int end);
int partition(int* A, int start, int end);

void selection_sort(int* A, int length) {
  int temp = 0;
  for (int i = 0; i < length-1; i++) {
    for (int j = i+1; j < length; j++) {
      if (A[j] < A[i]) {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
      }
    }
  }
  return;
}

void bubble_sort(int* A, int length) {
  int temp = 0;
  int sorted_flag = 1;
  for (int i = 0; i < length - 1; i++) {
    for (int j = 0; j < length - i - 1; j++) {
      if (A[j] > A[j+1]) {
        temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
        sorted_flag = 0;
      }
    }
    if (sorted_flag==1) {
      break;
    }
  }
  return;
}

void insertion_sort(int* A, int length) {
  int value_hole = 0;
  int hole = 0;
  for (int i = 1; i < length; i++) {
      hole = i;
      value_hole = A[i];
      while (hole  > 0) {
        if (A[hole] < A[hole-1]) {
          A[hole] = A[hole-1];
          A[hole-1] = value_hole;
          hole = hole - 1;
      }
      else break;
    }
  }
  return;
}


void merge(int* A, int* left, int left_len, int* right, int right_len) {

  int i, j, k = 0;
  while (i < left_len && j < right_len) {
    if (left[i] <= right[j]) {
      A[k] = left[i];
      k = k + 1;
      i = i + 1;
    }
    else {
      A[k] = right[j];
      k = k + 1;
      j = j + 1;
    }
  }
  while (i < left_len) {
    A[k] = left[i];
    i = i + 1;
    k = k + 1;
  }
  while (j < right_len) {
    A[k] = right[j];
    j = j + 1;
    k = k + 1;
  }
}


void merge_sort(int* A, int length) {
  if (length < 2) {
    return;
  }
  int n = length/2;
  int left_arr[n];
  int right_arr[length-n];
  for (int i = 0; i < n; i++) {
    left_arr[i] = A[i];
  }
  for (int i = n; i < length; i++) {
    right_arr[i-n] = A[i];
  }
  merge_sort(left_arr, n);
  merge_sort(right_arr, length - n);
  merge(A, left_arr, n, right_arr, length - n);
}

int partition(int* A, int start, int end) {
  int part_index = start;
  int pivot = A[end];
  int temp = 0;
  for (int i = start; i < end; i++) {
    if (A[i] <= pivot) {
      temp = A[i];
      A[i] = A[part_index];
      A[part_index] = temp;
      part_index++;
    }
  }
  temp = A[part_index];
  A[part_index] = A[end];
  A[end] = temp;
  return part_index;
}

void quick_sort(int* A, int start, int end) {
  if (start < end) {
    int part_index = partition(A, start, end);
    quick_sort(A, start, part_index-1);
    quick_sort(A, part_index+1, end);
  }
  return;
}

int main(void) {
  int A[10000] = {2, 4, 6, 1, 0, 7, 8, 9, 3, 5};
  int length = sizeof(A)/sizeof(A[0]);
  // selection_sort(A, length);
  // bubble_sort(A, length);
  // insertion_sort(A, length);
  // merge_sort(A, length);

  quick_sort(A, 0, length-1);

  printf("Array:\n");
  for (int i = 0; i < length; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
  return 0;
}
