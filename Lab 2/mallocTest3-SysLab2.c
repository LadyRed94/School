#include <stdio.h>
#include <stdlib.h>

int main() {

   int *arr, *p;

   // allocate an array of 20 ints on the heap:
   arr = malloc(sizeof(int) * 20);
   p = malloc(sizeof(int));
   printf(" %p\n %p\n", arr, p);

}