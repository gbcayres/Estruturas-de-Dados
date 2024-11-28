#include <stdlib.h>
#include <stdio.h>
#include "dynamicStack.h"

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct dynamicStack {
  Node *top;
  int size;
} DynamicStack;

DynamicStack* createStack() {
  DynamicStack *stack = (DynamicStack*)malloc(sizeof(DynamicStack));

  if (stack == NULL) {
    fprintf(stderr, "ERROR in 'createStack()':\n error allocating stack memory.\n");
    exit(EXIT_FAILURE);
  }

  stack->top = NULL;
  stack->size = 0;
  
  return stack;
}

void destroyStack(DynamicStack **stackPointerRef) {
  DynamicStack *stack = *stackPointerRef;

  Node *current = stack->top;

  while(current != NULL) {
    Node *aux = current;
    current = current->next;
    free(aux);
  }

  free(stack);

  *stackPointerRef = NULL;
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

bool isEmpty(const DynamicStack *stack) {
  if (stack == NULL) {
    fprintf(stderr, "ERROR in 'isEmpty()':\n null pointer passed as argument.\n");
    exit(EXIT_FAILURE);
  }

  return stack->top == NULL;
}

int peek(const DynamicStack *stack) {
  if (stack == NULL) {
    fprintf(stderr, "ERROR in 'peek()':\n null pointer passed as argument.\n");
    exit(EXIT_FAILURE);
  }

  if (isEmpty(stack)) {
    fprintf(stderr, "the stack is empty");
    return -1;
  }

  return stack->top->data;
}

void push(DynamicStack *stack, int value) {
  if (stack == NULL) {
    fprintf(stderr, "ERROR in 'push()':\n null pointer passed as argument.\n");
    exit(EXIT_FAILURE);
  }

  Node *newNode = createNode(value);

  newNode->next = stack->top;

  stack->top = newNode;
}

int pop(DynamicStack *stack) {
  if (stack == NULL) {
    fprintf(stderr, "ERROR in 'pop()':\n null pointer passed as argument.\n");
    exit(EXIT_FAILURE);
  }

  if (isEmpty(stack)) {
    fprintf(stderr, "ERROR in 'pop()':\n the stack is empty.\n");
    exit(EXIT_FAILURE);
  }

  Node *aux = stack->top;
  int value = aux->data;

  stack->top = stack->top->next;
  free(aux);

  stack->size--;
  return value;
}

void printStack(const DynamicStack *stack) {
  Node *current = stack->top;

  while (current != NULL) {
    printf("%d\n", current->data);
    current = current->next;
  }
}