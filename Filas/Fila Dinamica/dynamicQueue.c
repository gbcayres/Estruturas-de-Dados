#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct dynamicQueue {
    Node *head;
    Node *tail;
    int size;
} DynamicQueue;

DynamicQueue* createQueue() {
    DynamicQueue *queue = (DynamicQueue*)malloc(sizeof(DynamicQueue));

    if (queue == NULL) {
        fprintf(stderr, "ERROR in 'createQueue()': memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

void destroyQueue(DynamicQueue **queuePointerRef) {
    DynamicQueue *queue = *queuePointerRef;

    Node *current = queue->head;

    while (current != NULL) {
      Node *aux = current;
      current = current->next;
      free(aux);
    }

    free(queue);

    *queuePointerRef = NULL;
}

Node* createNode(int value) {
  Node *newNode = (Node*)malloc(sizeof(Node));

  if (newNode == NULL) {
    fprintf(stderr, "ERROR in 'createNode()':\n error allocating node memory.\n");
    exit(EXIT_FAILURE);
  }

  newNode->data = value;
  newNode->next = NULL;

  return newNode;
}

bool isEmpty(const DynamicQueue *queue) {
    return queue->size == 0;
}

void enqueue(DynamicQueue *queue, int value) {
  if (queue == NULL) {
    fprintf(stderr, "ERROR in 'enqueue()':\n null pointer passed as argument.\n");
    exit(EXIT_FAILURE);
  }

  Node *newNode = createNode(value);

  if (isEmpty(queue)) {
    queue->head = newNode;
  }
  else {
    queue->tail->next = newNode;
  }

  queue->tail = newNode;
  queue->size++;
}

int dequeue(DynamicQueue *queue) {
    if (isEmpty(queue)) {
      fprintf(stderr, "ERROR in 'dequeue()':\n the queue is empty.\n");
      exit(EXIT_FAILURE);
    }

    Node *aux = queue->head;
    int value = aux->data;

    queue->head = queue->head->next;

    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    free(aux);
    queue->size--;

    return value;
}

int peek(const DynamicQueue *queue) {
  if (isEmpty(queue)) {
    fprintf(stderr, "ERROR in 'peek()': queue is empty.\n");
    exit(EXIT_FAILURE);
  }

  return queue->head->data;
}

int size(const DynamicQueue *queue) {
  return queue->size;
}

void printQueue(const DynamicQueue *queue) {
  Node *current = queue->head;

  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
}