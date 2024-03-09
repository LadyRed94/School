/*
  fill in set_next so that it makes n1 point to n2
  when set_next is called with &n1 and &n2
  Then, call set_next in main
 */
#include <stdio.h>
#include <stdlib.h>
/* structure for a node */
struct Node {
  int data;
  struct Node *next; // notice that this is self-referential
} ;
typedef struct Node node_t;
void set_next(node_t *node1, node_t *node2) {
  /* as the header is written, can this function modify the argument
  that is passed in for n1? We don't believe it was possble to modify n1 without using a pointer
  so we changed them to pointers
  */
  node1 -> next = node2;
}
int main(void) {
  struct Node n1, n2, *p1, *p2;
  n1.data = 10 ;
  n2.data = 20 ;
  n1.next = NULL;
  n2.next = NULL;
  p1 = &n1;
  p2 = &n2;
  // call set_next
  set_next(p1, p2);
  printf("&n1 = %p  n1.data = %d  n1.next = %p\n", &n1, n1.data, n1.next) ;
  printf("&n2 = %p  n2.data = %d  n2.next = %p\n", &n2, n2.data, n2.next) ;
  return 0 ;
}