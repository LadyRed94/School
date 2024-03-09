#include <stdio.h>
#include <stdlib.h>

//arr = malloc(sizeof(int)*3);

void swap (int *px, int *py){
 int *arr;
 arr = malloc(sizeof(int)*3);
 return;
 }
 
 int main() {
  int x, y, tmp;

  printf("Enter two integer values: ");
  scanf("%d%d", &x, &y);
  printf("before: x = %d, y = %d\n", x, y);
  

  swap(&x, &y);
  printf("after: x = %d, y = %d\n", x, y);

  return 0;
}