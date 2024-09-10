#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "intList.h"

struct intList {
  int capacity;
  int size;
  int *data;
};

intList create(int capacity) {
  intList list = (intList)malloc(sizeof(struct intList));
  if (list == NULL) {
    fprintf(stderr, "Failed to create list");
    exit(EXIT_FAILURE);
  }

  list->capacity = capacity;
  list->size = 0;

  list->data = (int*)calloc(capacity, sizeof(int));
  if (list->data == NULL) {
    fprintf(stderr, "Failed to allocate data array");
    exit(EXIT_FAILURE);
  }

  return list;
}

bool indexInBounds(int index, int size) {
  return (index >= 0 && index < size);
}

void destroy(intList *listPtr) {
  if (*listPtr != NULL) {
    free((*listPtr)->data);
    free(*listPtr);
    *listPtr = NULL;
  }
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
    fprintf(stderr, "ERROR in 'append': ");
    fprintf(stderr, "The list is full.");
    exit(EXIT_FAILURE);
  }
}

int size(intList list) {
  return list->size;
}

int capacity(intList list) {
  return list->capacity;
}

int get(intList list, int index) {
  if (indexInBounds(index, size(list))) {
    return list->data[index];
  } else {
    fprintf(stderr, "ERROR in 'get': ");
    fprintf(stderr, "Index out of bounds.");
    exit(EXIT_FAILURE);
  }
}

void set(intList list, int index, int value) {
  if (indexInBounds(index, size(list))) {
    list->data[index] = value;
  } else {
    fprintf(stderr, "ERROR in 'set': ");
    fprintf(stderr, "Index out of bounds.");
    exit(EXIT_FAILURE);
  }
}

void removeAt(intList list, int index) {
  if (!indexInBounds(index, size(list))) {
    fprintf(stderr, "ERROR in 'remove': ");
    fprintf(stderr, "Index out of bounds.");
    exit(EXIT_FAILURE);
  } else if (index >= list->size) {
    fprintf(stderr, "ERROR in 'remove': ");
    fprintf(stderr, "No element at index %d", index);
    exit(EXIT_FAILURE);
  }

  for (int i = index; i < list->size - 1; i++) {
    list->data[i] = list->data[i + 1];
  }
  list->data[list->size - 1] = 0;

  list->size--;
}