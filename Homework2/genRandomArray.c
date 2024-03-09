#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *genRandomArray(int n){

   int *arr;
   int i;
   srand(time(NULL));
   arr = malloc(n*sizeof(int));
   
   for (i=0; i < n; i++) {
      arr[i] = rand()%100;
      }
      
   return arr;
}

void showArray(int *arr, int n){
   
   int i;
   
   for (i=0; i < n; i++) {
      printf("%d\n",arr[i]);
      }
}

int main() {

    int i;
    
    printf("How long do you want the Array?: ");
    scanf("%d", &i);
    
    //check for positive value
    if(i<1){
      printf("Array must be longer than 1\n");
      return 0;
      }
      
    int *arr = genRandomArray(i);
    showArray(arr, i);
    
}