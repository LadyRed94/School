/*
 * pass a pointer by pointer
 */
#include <stdio.h>
#include <stdlib.h>
void swap(int **x, int **y) {
  int *tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}
int main() {
  int x = 6;
  int y = 3;
  int *x_ptr = &x;
  int *y_ptr = &y;
  swap(&x_ptr, &y_ptr);
  printf("%d   %d\n", *x_ptr, *y_ptr);  //this should print 3  6
}