/* 
 *  swap the values of x and y
 *  fill in the missing code
 *  compile and run the program to verify that it works
 */

#include <stdio.h>

int main() {
  int x, y, tmp;

  printf("Enter two integer values: ");
  scanf("%d%d", &x, &y);

  printf("before: x = %d, y = %d\n", x, y);

  // fix this code
  tmp = x;
  x = y;
  y = tmp;

  printf("after: x = %d, y = %d\n", x, y);

  
  return 0;
}