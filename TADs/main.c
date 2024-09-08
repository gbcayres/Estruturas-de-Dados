#include <stdio.h>
#include "intList.h"

int main(void) {
  intList list = create(10);

  append(list, 10);
  append(list, 5);
  append(list, 20);
  append(list, 50);
  append(list, 2);
  print(list);

  set(list, 4, 640);
  print(list);

  printf("\nList size: %d\n", size(list));
  printf("\nList capacity: %d\n", capacity(list));
  printf("\nlist[%d]: %d\n", 5, get(list, 5));

  // remove(list, 5);
  // print(list);

  destroy(&list);

  return 0;
}