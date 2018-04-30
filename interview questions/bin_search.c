#include <stdio.h>
#include <stdlib.h>

int binary_search(int* sorted_arr, int item, int start, int end);
int first_occur(int* sorted_arr, int item, int start, int end);
int last_occur(int* sorted_arr, int item, int start, int end);
int num_occur(int* sorted_arr, int item, int start, int end);
int num_rotate(int* array, int start, int end);
int circular_find(int* array, int item, int start, int end);

int binary_search(int* sorted_arr, int item, int start, int end) {
  int mid = (start + end)/2;
  if (start>end) {
    return -1;
  }
  if (sorted_arr[mid] == item) {
    return mid;
  } else if (item < sorted_arr[mid]) {
    return binary_search(sorted_arr, item, start, mid-1);
  } else {
    return binary_search(sorted_arr, item, mid+1, end);
  }
}

int first_occur(int* sorted_arr, int item, int start, int end) {
  int mid = (start + end)/2;
  if (start>end) {
    return -1;
  }
  if (sorted_arr[mid] == item) {
    int result;
    result = first_occur(sorted_arr, item, start, mid-1);
    // for last coourence
    // result = binary_search(sorted_arr, item, mid+1, end);
    if (result == -1) {
      return mid;
    } else {
      return result;
    }
  } else if (item < sorted_arr[mid]) {
    return first_occur(sorted_arr, item, start, mid-1);
  } else {
    return first_occur(sorted_arr, item, mid+1, end);
  }
}

int last_occur(int* sorted_arr, int item, int start, int end) {
  int mid = (start + end)/2;
  if (start>end) {
    return -1;
  }
  if (sorted_arr[mid] == item) {
    int result;
    result = last_occur(sorted_arr, item, mid+1, end);
    if (result == -1) {
      return mid;
    } else {
      return result;
    }
  } else if (item < sorted_arr[mid]) {
    return last_occur(sorted_arr, item, start, mid-1);
  } else {
    return last_occur(sorted_arr, item, mid+1, end);
  }
}

int num_occur(int* sorted_arr, int item, int start, int end) {
  static int occurence = 0;
  // int first, last;
  // last = last_occur(sorted_arr, item, start, end);
  // first = first_occur(sorted_arr, item, start, end);
  // if (first != -1) {
  //   occurence = last - first + 1;
  // }
  // return occurence;
  int mid = (start + end)/2;
  if (start>end) {
    return occurence;
  }
  if (sorted_arr[mid] == item) {
    occurence++;
    num_occur(sorted_arr, item, start, mid-1);
    num_occur(sorted_arr, item, mid+1, end);
    return occurence;
  } else if (item < sorted_arr[mid]) {
    return num_occur(sorted_arr, item, start, mid-1);
  } else {
    return num_occur(sorted_arr, item, mid+1, end);
  }
}

int num_rotate(int* array, int start, int end) {
  int mid = start + (end - start)/2;
  if (start > end) {
    return -1;
  }
  if (array[start] < array[end]) {
    return start;
  }
  else if ((array[mid]<=array[mid-1]) && (array[mid]<=array[mid+1])) {
    return mid;
  } else if (array[mid]<=array[end]) {
    return num_rotate(array, start, mid-1);
  } else {
    return num_rotate(array, mid+1, end);
  }
}

int circular_find(int* array, int item, int start, int end) {
  int mid = start + (end - start)/2;
  int result = 0;
  if (start > end) {
    return -1;
  }
  if (item == array[mid] ) {
    return mid;
  }
  if (array[mid]<=array[end]) {
    if (item > array[mid] && item <= array[end]) {
      result = circular_find(array, item, mid+1, end);
    }
    else {
      result = circular_find(array, item, start, mid-1);
    }
    return result;
  } else {
    if (item < array[mid] && item >= array[start]) {
      result = circular_find(array, item, start, mid-1);
    }
    else {
      result = circular_find(array, item, mid+1, end);
    }
    return result;
  }
}


int main(void) {
  int sorted_arr[] = {7,9,15,16,17,0,1,1,1,1,1,5,6};
  int length = sizeof(sorted_arr)/sizeof(sorted_arr[0]);
  int index = 0;
  printf("%d\n", length);
  int item = 0;
  printf("Enter item to search:");
  scanf("%d", &item);
  // index =  binary_search(sorted_arr, item, 0, length-1);
  // index =  num_occur(sorted_arr, item, 0, length-1);
  // index =  num_rotate(sorted_arr, 0, length-1);
  index = circular_find(sorted_arr, item, 0, length-1);
  printf("Index of value:%d\n", index);
  return 0;
}
