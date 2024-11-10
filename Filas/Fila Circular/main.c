#include <stdio.h>
#include <stdio.h>
#include "staticQueue.h"

int main(void) {
  printf("creating Static Queue...\n");
  StaticQueue *queue = createStaticQueue(5);

  printf("\nis empty? %d\n", isEmpty(queue));
  printf("is full? %d\n", isFull(queue));

  printQueue(queue);

  printf("\n'enqueueing' 8, 10, 35, 92 and 60.\n");
  enqueue(queue, 8);
  enqueue(queue, 10);
  enqueue(queue, 35);
  enqueue(queue, 92);
  enqueue(queue, 60);

  printf("\npeek: %d\n", peek(queue));

  printQueue(queue);

  printf("\nis empty? %d\n", isEmpty(queue));
  printf("is full? %d\n", isFull(queue));

  printf("\n'dequeueing' 2 elements.\n");
  dequeue(queue);
  dequeue(queue);

  printf("\npeek: %d\n", peek(queue));

  printQueue(queue);

  printf("\nis empty? %d\n", isEmpty(queue));
  printf("is full? %d\n", isFull(queue));

  return 0;
}