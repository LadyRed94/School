/*
 * pointer_arith.c
 * static or dynamic array
 * what does this code do?
 */
#include<stdio.h>
#include<stdlib.h>
void dynamic_arr(int);
void print_array(int *array, int size) {
  for (int i=0; i<size; i++) {
    printf("array[%d] = %d\n", i, array[i]);
  }
  //used for error checking
  //printf("Done\n");
}
void pointer_arith(int n) {
  int arr[] = {1,2,3};
  int *arr_ptr;
  printf("arr is at %p\n", arr);
  //We believe the error is on this line, used 4 on len 3
  print_array(arr, 3 );
  // initialize the arrays
  for (int i=0; i < 2 * n; i++) {
    arr[i] = i;
  }
  dynamic_arr(3);
}
void dynamic_arr(int n) {
  int *darry;
  darry = malloc(sizeof(int) * n);
  printf("darry  %p\n", darry);
  //overstepped allocated memory
  for (int i=0; i<n; i++) {
    darry[i] = i;
  }
}
int main() {
  pointer_arith(3);
  return 0;
}
