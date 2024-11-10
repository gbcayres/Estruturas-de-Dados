#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H
#include <stdbool.h>

typedef struct staticQueue StaticQueue;

StaticQueue* createStaticQueue(int capacity);
void destroyStaticQueue(StaticQueue **queuePointerRef);

bool isEmpty(StaticQueue *queue);
bool isFull(StaticQueue *queue);
int size(StaticQueue *queue);
int peek(StaticQueue *queue);

void enqueue(StaticQueue *queue, int value);
int dequeue(StaticQueue *queue);

void printQueue(StaticQueue *queue);

#endif