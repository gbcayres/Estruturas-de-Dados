#include <stdlib.h>
#include <stdio.h>
#include "staticQueue.h"

typedef struct staticQueue {
  int capacity;
  int size;
  int front;
  int rear;
  int *data;
} StaticQueue;

StaticQueue* createStaticQueue(int capacity) {
  StaticQueue *queue = (StaticQueue*)malloc(sizeof(StaticQueue)); 
  queue->capacity = capacity;
  queue->size = 0;
  queue->front = 0;
  queue->rear = 0;
  queue->data = (int*)malloc(capacity * sizeof(int));

  return queue;
}

void destroyStaticQueue(StaticQueue **queuePointerRef) {
  free((*queuePointerRef)->data);
  free(*queuePointerRef);

  *queuePointerRef = NULL;
}

bool isEmpty(StaticQueue *queue) { 
  return queue->size == 0;
}

bool isFull(StaticQueue *queue) {
  return queue->size == queue->capacity;
}

int size(StaticQueue *queue) {
  return  queue->size;
}

void printQueue(StaticQueue *queue) {
  for (int i = 0; i < queue->size; i++) {
    printf("queue[%d]: %d\n", i, queue->data[i]);
  }
}