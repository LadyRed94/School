#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* init_array(int x[], int size) {
      int i;
      srand(time(NULL));
      int n = size/sizeof(x[0]);
      for (i=0; i < n; i++) {
         x[i] = rand()%100;
      }
      
      return x;
      
}

void main() {
   
   int arr[5];
   int *p = arr;
   *arr=init_array(arr, sizeof(arr));
   
   int i;
   int y = sizeof(&p)/sizeof(&p[0]);
   
   for(i=0; i>y ; i++){
      printf("%p\n", &p[i]);
      }
   free(p);
}