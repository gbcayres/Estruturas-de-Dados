#include <stdio.h>
#include <stdlib.h>
#include "dynamicQueue.h"

int main(void) {
    printf("creating dynamic queue...\n");
    DynamicQueue *queue = createQueue();

    printf("\nthe queue is empty? %d\n", isEmpty(queue));

    printf("\nenqueuing elements 5, 3, and 9...\n");
    enqueue(queue, 5);
    enqueue(queue, 3);
    enqueue(queue, 9);

    printQueue(queue);
    printf("\n");

    printf("\nfront: %d\n", peek(queue)); 

    printf("\nsize: %d\n", size(queue));

    printf("\ndequeuing one element...\n");
    dequeue(queue);

    printQueue(queue);
    printf("\n");

    printf("\nsize: %d\n", size(queue));

    destroyQueue(&queue);

    system("pause");
}