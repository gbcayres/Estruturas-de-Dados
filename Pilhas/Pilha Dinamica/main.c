#include <stdio.h>
#include <stdlib.h>
#include "dynamicStack.h"

int main(void) {
  printf("creating dynamic stack...\n");
  DynamicStack *stack = createStack();

  printf("\nthe stack is empty? %d\n", isEmpty(stack));

  printf("\npushing elements 5, 3 and 9...\n");
  push(stack, 5);
  push(stack, 3);
  push(stack, 9);

  printStack(stack);

  printf("\ntop: %d\n", peek(stack));

  printf("\nthe stack is empty? %d\n", isEmpty(stack));

  printf("\npopping 1 element...\n");
  pop(stack);

  printStack(stack);

  printf("\nsize: %d\n", size(stack));

  printf("\ntop: %d\n", peek(stack));

  destroyStack(&stack);
  
  system("pause");
}