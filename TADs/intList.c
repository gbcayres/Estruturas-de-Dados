#include <stdlib.h>
#include <stdio.h>
#include "intList.h"

struct intList {
  int capacity;
  int size;
  int *data;
};

intList create(int capacity) {
  intList list = (intList)malloc(sizeof(struct intList));
  if (list == NULL) {
    perror("Failed to create list");
    exit(EXIT_FAILURE);
  }

  list->capacity = capacity;
  list->size = 0;

  list->data = (int*)calloc(capacity, sizeof(int));
  if (list->data == NULL) {
    perror("Failed to allocate data array");
    exit(EXIT_FAILURE);
  }

  return list;
}

void destroy(intList *listPtr) {
  free((*listPtr)->data);
  free(*listPtr);
  *listPtr = NULL;
}

void print(intList list) {
  puts("****************************");
  printf("Size: %d\n", list->size);
  printf("Capacity: %d\n", list->capacity);
  
  puts("-----");

  for (int i = 0; i < list->size; i++) {
    printf("[%d]: %d\n", i, list->data[i]);
  }
  puts("****************************");
}