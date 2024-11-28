#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include <stdbool.h>

typedef struct dynamicStack DynamicStack;

DynamicStack* createStack();
void destroyStack(DynamicStack **stackPointerRef);

bool isEmpty(const DynamicStack *stack);
int peek(const DynamicStack *stack);
int size(const DynamicStack *stack);

void push(DynamicStack *stack, int value);
int pop(DynamicStack *stack);

void printStack(const DynamicStack *stack);

#endif