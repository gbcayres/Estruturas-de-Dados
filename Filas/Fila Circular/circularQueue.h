#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H
#include <stdbool.h>

typedef struct circularQueue CircularQueue;

CircularQueue* createCircularQueue(int capacity);
void destroyCircularQueue(CircularQueue **queuePointerRef);

bool isEmpty(CircularQueue *queue);
bool isFull(CircularQueue *queue);
int size(CircularQueue *queue);
int peek(CircularQueue *queue);

void enqueue(CircularQueue *queue, int value);
int dequeue(CircularQueue *queue);

void printQueue(CircularQueue *queue);

#endif