#include <stdio.h>
#include <stdlib.h>

void arg_modfier(int x, int *x_ptr) {
      *x_ptr = x;
      printf("%d/n, *x_ptr);
      }

int main() {
   int x =7;
   arg_modfier(x, &x);
}