#include <stdio.h>
#include <stdio.h>
#include "staticQueue.h"

int main(void) {
  printf("Creating Static Queue...\n");
  StaticQueue *queue = createStaticQueue(5);

  printf("Checking if the queue is empty... %d", isEmpty(queue));

  return 0;
}