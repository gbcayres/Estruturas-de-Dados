#include <stdio.h>
#include "staticStack.h"

int main(void) {
  printf("Creating Static Stack...\n");
  StaticStack *stack = createStaticStack(5);
  
  printf("\nChecking empty stack... ");
  printf("%d\n", isEmpty(stack));

  printf("\nChecking full stack... ");
  printf("%d\n", isFull(stack));

  printf("\nPushing elements 5, 3, 9, 15 and 50.\n");
  push(stack, 5);
  push(stack, 3);
  push(stack, 9);
  push(stack, 15);
  push(stack, 50);
  printStack(stack);

  printf("\nChecking empty stack... ");
  printf("%d\n", isEmpty(stack));

  printf("\nChecking full stack... ");
  printf("%d\n", isFull(stack));

  printf("\nTop element of the stack: %d\n", top(stack));

  printf("\nPopping last element...\n");
  pop(stack);
  printStack(stack);

  return 0;
}