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
  
  puts("---------");

  for (int i = 0; i < list->size; i++) {
    printf("[%d]: %d\n", i, list->data[i]);
  }
  puts("****************************");
}

void append(intList list, int value) {
  if (list->size < list->capacity) {
  list->data[list->size++] = value;
  } else {
    fprintf(stderr, "ERROR in 'append'\n");
    fprintf(stderr, "The list is full.");
    exit(-1);
  }
}

int size(intList list) {
  return list->size;
}

int capacity(intList list) {
  return list->capacity;
}

int get(intList list, int index) {
  if (index >= 0 && index < list->capacity) {
    return list->data[index];
  } else {
    fprintf(stderr, "ERROR in 'get'\n");
    fprintf(stderr, "Index out of bounds.");
    exit(-1);
  }
}

void set(intList list, int index, int value) {
  if (index >= 0 && index < list->capacity) {
    list->data[index] = value;
  } else {
    fprintf(stderr, "ERROR in 'set'\n");
    fprintf(stderr, "Index out of bounds.");
    exit(-1);
  }
}


// void remove(intList list, int index) {
//   if (index < 0 || index > list->capacity) {
//     fprintf(stderr, "ERROR in 'remove'\n");
//     fprintf(stderr, "Index out of bounds.");
//     exit(-1);
//   } 

//   for (int i = index; i < list->size - 1; i++) {
//     list->data[i] = list->data[i + 1];
//   }
//   list->data[list->size - 1] = 0;

//   list->size--;
// }