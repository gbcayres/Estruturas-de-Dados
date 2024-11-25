#include <stdio.h>
#include "staticStack.h"

int main(void) {
  printf("creating Static Stack...\n");
  StaticStack *stack = createStaticStack(5);
  
  printf("\nis empty? %d\n", isEmpty(stack));
  printf("is full? %d\n", isFull(stack));

  printStack(stack);


  printf("\npushing elements 5, 3, 9, 15 and 50.\n");
  push(stack, 5);
  push(stack, 3);
  push(stack, 9);
  push(stack, 15);
  push(stack, 50);

  printf("\npeek: %d\n", peek(stack));

  printStack(stack);

  printf("\nis empty? %d\n", isEmpty(stack));
  printf("is full? %d\n", isFull(stack));

  printf("\npopping last element...");
  pop(stack);

  printStack(stack);

  printf("\npeek: %d\n", peek(stack));

  printf("\nis empty? %d\n", isEmpty(stack));
  printf("is full? %d\n", isFull(stack));

  return 0;
}