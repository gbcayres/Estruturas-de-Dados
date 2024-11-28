#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#include <stdbool.h>

typedef struct dynamicQueue DynamicQueue;

DynamicQueue* createQueue();
void destroyQueue(DynamicQueue **queuePointerRef);

bool isEmpty(const DynamicQueue *queue);
int peek(const DynamicQueue *queue);
int size(const DynamicQueue *queue);

void enqueue(DynamicQueue *queue, int value);
int dequeue(DynamicQueue *queue);

void printQueue(const DynamicQueue *queue);

#endif