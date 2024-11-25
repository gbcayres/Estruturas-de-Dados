#include "staticStack.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct staticStack {
  int *data;
  int capacity;
  int top;
} StaticStack;

StaticStack* createStaticStack(int capacity) {
  StaticStack *stack = (StaticStack*)malloc(sizeof(StaticStack));
  if (stack == NULL) {
    perror("ERROR in 'createStaticStack()'");
    perror("Failed to allocate memory for static stack.");
    exit(EXIT_FAILURE);
  }

  stack->capacity = capacity;
  stack->top = -1;
  stack->data = (int*)malloc(capacity * sizeof(int));

  return stack;
}

void destroyStaticStack(StaticStack **stackPointerRef) {
  StaticStack *stack = *stackPointerRef;
  free(stack->data);
  free(stack);

  *stackPointerRef = NULL;
}

bool isEmpty(const StaticStack *stack) {
  if (stack == NULL) {
    perror("ERROR in 'isFull()'");
    perror("Invalid stack.");
    exit(EXIT_FAILURE);
  }

  return (stack->top == -1);
}

bool isFull(const StaticStack *stack) {
  if (stack == NULL) {
    perror("ERROR in 'isFull()'");
    perror("Invalid stack.");
    exit(EXIT_FAILURE);
  }

  return stack->top == stack->capacity - 1;
}

void push(StaticStack *stack, int value) {
  if (isFull(stack)) {
    perror("ERROR in 'push()'");
    perror("The stack is full!");
    exit(EXIT_FAILURE);
  }

  stack->top++;
  stack->data[stack->top] = value;
}

int pop(StaticStack *stack) {
  if (isEmpty(stack)) {
    perror("ERROR in 'pop()'");
    perror("The stack is empty!");
    exit(EXIT_FAILURE);
  }

  int aux = stack->data[stack->top];
  stack->top--;

  return aux;
}

int peek(const StaticStack *stack) {
  if (isEmpty(stack)) {
    perror("ERROR in 'peek()'");
    perror("The stack is empty!");
    exit(EXIT_FAILURE);
  }

  return stack->data[stack->top];
}

void printStack(const StaticStack *stack) {
  printf("\ncapacity: %d\n", stack->capacity);
  printf("top: %d\n", stack->top);

  if (isEmpty(stack)) {
    printf("the stack is empty.\n");
    return;
  }

  printf("elements:\n");
  for (int i = 0; i <= stack->top; i++) {
    printf("stack[%d]: %d\n", i, stack->data[i]);
  }
}