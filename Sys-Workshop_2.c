#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[20];
    int i;
    srand(time(NULL));

    for (i=0; i < 20; i++) {
      arr[i] = rand()%6;
      printf("%d\n",arr[i]);
   }
}