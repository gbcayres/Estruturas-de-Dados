#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>

typedef struct node Node;
typedef struct linkedList LinkedList;

LinkedList* createLinkedList();
void destroyLinkedList(LinkedList **list_ref);
void insertAtBegin(LinkedList *list, int value);
void insertAtEnd(LinkedList *list, int value);
void insertAtPosition(LinkedList *list, int position, int value);
void removeAtBegin(LinkedList *list);
void removeAtEnd(LinkedList *list);
void removeAtPosition(LinkedList *list, int position);
bool isPresent(LinkedList *list, int value);
bool isEmpty(LinkedList *list);
int getSize(LinkedList *list);
void printList(LinkedList *list);
void printReversedList(LinkedList *list);

#endif