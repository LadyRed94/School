#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p, *i, size;
    size = sizeof(int)*20;

    p = malloc(size);  // allocate heap memory for storing an int
    i = malloc(sizeof(int));  // allocate heap memory for storing an int
    //s = malloc(sizeof(int));  // allocate heap memory for storing an int
    printf(" %p\n %p\n", p, i);

    if (p != NULL) {
        *p = 6;   // the heap memory p points to gets the value 6
    }
    if (i != NULL) {
        *i = 6;   // the heap memory p points to gets the value 6
    }
}