/* swap2.c
 *   x: one value
 *   y: the other value
 *   write a swap function that will swap the values of the arguments
 */

#include <stdio.h>

void swap(int *px, int *py) {
  int tmp;
    
  tmp = *px;
  *px = *py;
  *py = tmp;
    
  // fill in the code

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