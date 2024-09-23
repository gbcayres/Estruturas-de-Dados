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
  if (capacity <= 0 ) {
    perror("ERROR in 'createStaticQueue()'\n");
    perror("Invalid capacity.");
    exit(EXIT_FAILURE);
  }

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
  if (queue == NULL) {
    perror("ERROR in 'isEmpty()'");
    perror("Invalid queue.");
    exit(EXIT_FAILURE);
  }

  return queue->size == 0;
}

bool isFull(StaticQueue *queue) {
  if (queue == NULL) {
    perror("ERROR in 'isFull()'");
    perror("Invalid queue.");
    exit(EXIT_FAILURE);
  }

  return queue->size == queue->capacity;
}

int size(StaticQueue *queue) {
  if (queue == NULL) {
    perror("ERROR in 'size()'");
    perror("Invalid queue.");
    exit(EXIT_FAILURE);
  }

  return  queue->size;
}

int peek(StaticQueue *queue) {
  if (isEmpty(queue)) {
    perror("ERROR in 'peek()'");
    perror("The queue is empty.");
    exit(EXIT_FAILURE);
  }

  return queue->data[queue->front];
}

void enqueue(StaticQueue *queue, int value) {
  if (isFull(queue)) {
    perror("ERROR in enqueue()");
    perror("The queue is full.");
    exit(EXIT_FAILURE);
  }

  queue->data[queue->rear++] = value;
  queue->size++;
}

int dequeue(StaticQueue *queue) {
  if (isEmpty(queue)) {
    perror("ERROR in dequeue()");
    perror("The queue is empty.");
    exit(EXIT_FAILURE);
  }

  int removed = queue->data[queue->front++];
  queue->size--;
  return removed;
}

void printQueue(StaticQueue *queue) {
  printf("\ncapacity: %d\n", queue->capacity);
  printf("size: %d\n", queue->size);
  printf("front: %d\n", queue->front);
  printf("rear: %d\n", queue->rear);

  if (isEmpty(queue)) {
    printf("the queue is empty.\n");
    return;
  }

  printf("elements:\n");
  for (int i = queue->front; i < queue->rear; i++) {
    printf("queue[%d]: %d\n", i, queue->data[i]);
  }
}