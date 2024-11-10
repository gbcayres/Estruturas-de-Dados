#include <stdlib.h>
#include <stdio.h>
#include "circularQueue.h"

typedef struct circularQueue {
  int capacity;
  int size;
  int front;
  int rear;
  int *data;
} CircularQueue;

CircularQueue* createCircularQueue(int capacity) {
  if (capacity <= 0 ) {
    perror("ERROR in 'createStaticQueue()'\n");
    perror("Invalid capacity.");
    exit(EXIT_FAILURE);
  }

  CircularQueue *queue = (CircularQueue*)malloc(sizeof(CircularQueue)); 
  if (!queue) {
    perror("ERROR in 'createCircularQueue()'");
    perror("Failed to allocate memory.");
    exit(EXIT_FAILURE);
  }

  queue->capacity = capacity;
  queue->size = 0;
  queue->front = 0;
  queue->rear = 0;
  queue->data = (int*)malloc(capacity * sizeof(int));

  if (!queue->data) {
    perror("ERROR in 'createCircularQueue()'");
    perror("Failed to allocate memory.");
    exit(EXIT_FAILURE);
  }

  return queue;
}

void destroyCircularQueue(CircularQueue **queuePointerRef) {
  free((*queuePointerRef)->data);
  free(*queuePointerRef);

  *queuePointerRef = NULL;
}

bool isEmpty(CircularQueue *queue) {
  if (queue == NULL) {
    perror("ERROR in 'isEmpty()'");
    perror("Invalid queue.");
    exit(EXIT_FAILURE);
  }

  return queue->size == 0;
}

bool isFull(CircularQueue *queue) {
  if (queue == NULL) {
    perror("ERROR in 'isFull()'");
    perror("Invalid queue.");
    exit(EXIT_FAILURE);
  }

  return queue->size == queue->capacity;
}

int size(CircularQueue *queue) {
  if (queue == NULL) {
    perror("ERROR in 'size()'");
    perror("Invalid queue.");
    exit(EXIT_FAILURE);
  }

  return  queue->size;
}

int peek(CircularQueue *queue) {
  if (isEmpty(queue)) {
    perror("ERROR in 'peek()'");
    perror("The queue is empty.");
    exit(EXIT_FAILURE);
  }

  return queue->data[queue->front];
}

void enqueue(CircularQueue *queue, int value) {
  if (isFull(queue)) {
    perror("ERROR in enqueue()");
    perror("The queue is full.");
    exit(EXIT_FAILURE);
  }

  queue->data[queue->rear] = value;
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->size++;
}

int dequeue(CircularQueue *queue) {
  if (isEmpty(queue)) {
    perror("ERROR in dequeue()");
    perror("The queue is empty.");
    exit(EXIT_FAILURE);
  }

  int removed = queue->data[queue->front];

  queue->front =  (queue->front + 1) % queue->capacity;
  queue->size--;

  return removed;
}

void printQueue(CircularQueue *queue) {
  printf("\ncapacity: %d\n", queue->capacity);
  printf("size: %d\n", queue->size);
  printf("front: %d\n", queue->front);
  printf("rear: %d\n", queue->rear);

  if (isEmpty(queue)) {
    printf("the queue is empty.\n");
    return;
  }

  printf("elements:\n");
  int index = queue->front;
  for (int i = 0; i < queue->size; i++) {
    printf("queue[%d]: %d\n", index, queue->data[index]);
    index = (index + 1) % queue->capacity;
  }
}