#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <stdbool.h>

typedef struct staticStack StaticStack;

StaticStack* createStaticStack(int capacity);
void destroyStaticStack(StaticStack **stackPointerRef);

bool isEmpty(const StaticStack *stack);
bool isFull(const StaticStack *stack);
int peek(const StaticStack *stack);

void push(StaticStack *stack, int value);
int pop(StaticStack *stack);

void printStack(const StaticStack *stack);

#endif