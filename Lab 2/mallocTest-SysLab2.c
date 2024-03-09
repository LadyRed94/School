#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p, *i, *s;

    p = malloc(sizeof(int));  // allocate heap memory for storing an int
    i = malloc(sizeof(int));  // allocate heap memory for storing an int
    s = malloc(sizeof(int));  // allocate heap memory for storing an int
    printf(" %p\n %p\n %p\n", p,i,s);

    if (p != NULL) {
        *p = 6;   // the heap memory p points to gets the value 6
    }
    if (i != NULL) {
        *i = 6;   // the heap memory p points to gets the value 6
    }
    if (s != NULL) {
        *s = 6;   // the heap memory p points to gets the value 6
    }
}