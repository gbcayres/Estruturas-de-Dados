#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main(void) {
  printf("creating Linked List... \n");
  LinkedList *list = createLinkedList();

  printf("\ninserting 2, 15, 7 at the beginning of the list.\n");
  insertAtBegin(list, 2);
  insertAtBegin(list, 15);
  insertAtBegin(list, 7);

  printf("\n");
  printList(list);

  printf("\nlist size: %d\n", getSize(list));

  printf("\ninserting 46 and 8 and the end of the list.\n");
  insertAtEnd(list, 46);
  insertAtEnd(list, 8);

  printf("\n");
  printList(list);

  printf("\nlist size: %d\n", getSize(list));

  printf("\ninserting 100 at position 5.\n");
  insertAtPosition(list, 3, 100);

  printf("\n");
  printList(list);

  printf("\nlist size: %d\n", getSize(list));

  printf("\nremoving at beginning.\n");
  removeAtBegin(list);

  printf("\n");
  printList(list);

  printf("\nis 100 present in the list? %d\n", isPresent(list, 100));

  printf("\nlist size: %d\n", getSize(list));

  printf("\nremoving at index 2.\n");
  removeAtPosition(list, 2);

  printf("\n");
  printList(list);

  printf("\nis 100 present in the list? %d\n", isPresent(list, 100)); 

  printf("\nlist size: %d\n", getSize(list));

  printf("\ndestroying linked list...\n");
  destroyLinkedList(&list);

  system("pause");
}