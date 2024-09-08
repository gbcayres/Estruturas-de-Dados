#include "intList.h"

int main(void) {
  intList list = create(10);
  print(list);
  destroy(&list);

  return 0;
}