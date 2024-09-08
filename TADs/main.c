#include <stdio.h>
#include "intList.h"

int main(void) {
  puts("Creating intList of size 10.");
  intList list = create(10);

  puts("\nAppending 10, 5, 20, 50, 2");
  append(list, 10);
  append(list, 5);
  append(list, 20);
  append(list, 50);
  append(list, 2);
  print(list);

  puts("\nSetting list[4] to 640.");
  set(list, 4, 640);
  print(list);

  printf("\nList size: %d\n", size(list));
  printf("\nList capacity: %d\n", capacity(list));
  printf("\nlist[%d]: %d\n", 5, get(list, 5));

  puts("\nRemoving element at index 3.");
  removeAt(list, 3);
  print(list);

  destroy(&list);

  return 0;
}