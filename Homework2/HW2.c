#include <stdio.h>
#include <string.h>
int main(void){
      char aString[]  = "I<3Cprogramming"
      int start = 3;
      int end  = sizeof(aString)/3;
      int i;
      for (i = start; i < end; i+=2) {
         printf("%c", aString[i]);
      }
      printf("\n");
      return 0;
}