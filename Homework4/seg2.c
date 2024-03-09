/*
 * Program with a segfault
 * Copyright (c) 2019, "Dive into Systems"  by Suzanne Mathews, Tia Newhall, Ke
vin Webb (https://diveintosystems.cs.swarthmore.edu).
modified by R Weiss 2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int init_arr(int *array, int len) {
  int i;
  for (i=0; i < len; i++) {
    array[i] = i;
  }
  return 0;
}
int find_max(int *array1, int len, int *max) {
  int i;
  *max = (int)array1[0];
  for (i=0; i < len; i++) {
    if (*max < array1[i]) {
      *max = (int)array1[i];
    }
  }
  return 0;
}
void print_arr(int *array1, int len) {
  int i;
  for(i=0; i<len; i++) {
    printf("%d, ", array1[i]);
  }
  printf("\n");
}
int main(int argc, char *argv[]) {
  int *arr = NULL;
  arr = (int *)malloc(sizeof(int) * 10);
  int max_a = 6;
  int *maxa = &max_a;
  int *brr = NULL;
  brr = (int *)malloc(sizeof(int) * 10);
  int max_b = 6;
  int *maxb = &max_b;
  if (init_arr(brr, 10) != 0 ) {
    printf("init error\n");
    exit(1);
  }
  if (init_arr(arr, 10) != 0 ) {
    printf("init error\n");
    exit(1);
  }
  if ( find_max(arr, 10, maxa) != 0 ) {
    printf("func error\n");
    exit(1);
  }
  if ( find_max(brr, 10, maxb) != 0 ) {
    printf("func error\n");
    exit(1);
  }
  print_arr(arr, 10);
  print_arr(brr, 10);
  printf("max value in the array arr is %d\n", max_a);
  printf("max value in the array brr is %d\n", max_b);
  exit(0);
}
