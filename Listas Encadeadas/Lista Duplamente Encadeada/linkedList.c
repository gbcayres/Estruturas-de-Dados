#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *prev;
  struct node *next;
} Node;

typedef struct linkedList {
  Node *head;
  Node *tail;
  int size;
} LinkedList;

LinkedList* createLinkedList() {
  LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));

  if (list == NULL) {
    fprintf(stderr, "ERROR in createLinkedList():\n Error allocating linked list memory.\n");
    exit(EXIT_FAILURE);
  }

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return list;
}

void destroyLinkedList(LinkedList **list_ref) {
  if (list_ref == NULL) {
    fprintf(stderr, "ERROR in 'destroyLinkedList()':\n null pointer passed as argument.");
    exit(EXIT_FAILURE);
  }

  LinkedList *list = *list_ref;

  Node *current = list->head;
  Node *aux = NULL;

  while (current != NULL) {
    aux = current;

    current = current->next;

    free(aux);
  }

  free(list);

  *list_ref = NULL;
}

Node* createNode(int value) {
  Node *node = (Node*)malloc(sizeof(Node));

  if (node == NULL) {
    fprintf(stderr, "ERROR in createNode():\n Error allocating node memory.\n");
    exit(EXIT_FAILURE);
  }

  node->data = value;
  node->next = NULL;
  node->prev = NULL;
  
  return node;
}

bool isEmpty(LinkedList *list) {
  return list->size == 0; 
}

void insertAtBegin(LinkedList *list, int value) {
  if (list == NULL) {
    fprintf(stderr, "ERROR in 'insertAtBegin()':\n null pointer passed as argument.\n");
    exit(EXIT_FAILURE);
  }

  Node *newNode = createNode(value);

  newNode->next = list->head;

  if (isEmpty(list)) {
    list->tail = newNode;
  }
  else {
    list->head->prev = newNode;
  }
  
  list->head = newNode;

  list->size++;
}

void insertAtEnd(LinkedList *list, int value) {
  if (list == NULL) {
    fprintf(stderr, "ERROR in 'insertAtEnd()':\n null pointer passed as argument.\n");
    exit(EXIT_FAILURE);
  }

  Node *newNode = createNode(value);

  if (isEmpty(list)) {
    list->head = newNode;
  }
  else {
    list->tail->next = newNode; 
    newNode->prev = list->tail;
  }

  list->tail = newNode;
  list->size++;
}


void insertAtPosition(LinkedList *list, int position, int value) {
  if (list == NULL) {
    fprintf(stderr, "ERROR in 'insertAtPosition()': null pointer passed as argument.\n");
    exit(EXIT_FAILURE);
  }

  if (position < 0 || position > list->size) { 
    fprintf(stderr, "ERROR in 'insertAtPosition()': invalid position %d.\n", position);
    exit(EXIT_FAILURE);
  }

  if (position == 0) {
    insertAtBegin(list, value);
    return;
  }

  if (position == list->size) {
    insertAtEnd(list, value);
    return;
  }

  Node *newNode = createNode(value);
  Node *current = list->head;
    
  for (int i = 0; i < position - 1; i++) {
    current = current->next;
  }

  newNode->next = current->next;
  newNode->prev = current;

  if (current->next != NULL) {
    current->next->prev = newNode;
  }

  current->next = newNode;

  list->size++;
}


void removeAtBegin(LinkedList *list) {
  if (list == NULL) {
    fprintf(stderr, "ERROR in 'removeAtBegin': Null pointer passed as argument.\n");
    return;
  }

  
  if (isEmpty(list)) {
    fprintf(stderr, "ERROR in 'removeAtBegin()':\n the list is empty.\n");
    exit(EXIT_FAILURE);
  }

  Node *temp = list->head;

  if (list->head == list->tail) {
    list->head = NULL;
    list->tail = NULL;
  }
  else {
    list->head = list->head->next;
    list->head->prev = NULL;
  }

  free(temp);
  
  list->size--;
}

void removeAtPosition(LinkedList *list, int position) {
  if (list == NULL) {
    fprintf(stderr, "ERROR in 'removeAtPosition': Null pointer passed as argument.\n");
    return;
  }

  if (position < 0 || position >= list->size) {
    fprintf(stderr, "ERROR in 'removeAtPosition': Position %d is out of bounds.\n", position);
    return;
  }   

  if (isEmpty(list)) {
    fprintf(stderr, "ERROR in 'removeAtPosition': Cannot remove from an empty list.\n");
     return;
  }

  if (position == 0) {
    removeAtBegin(list);
    return;
  }

  Node *current = list->head;
  int index = 0;

  while (current != NULL && index < position) {
    current = current->next;
    index++;
  }

  if (current == NULL) {
    fprintf(stderr, "ERROR in 'removeAtPosition': Position %d out of bounds.\n", position);
    return;
  }

  current->prev->next = current->next;

  if (current->next != NULL) {
    current->next->prev = current->prev;
  }

  if (current == list->tail) {
    list->tail = current->prev;
  }

  free(current);

  list->size--;
}

void removeAtEnd(LinkedList *list) {
  if (list == NULL) {
    fprintf(stderr, "ERROR in 'removeAtPosition()':\n null pointer passed as argument.\n");
    exit(EXIT_FAILURE);
  }

  if (isEmpty(list)) {
    fprintf(stderr, "ERROR in 'removeAtBegin()':\n the list is empty.\n");
    exit(EXIT_FAILURE);
  }

  Node *aux = list->tail;
  
  if (list->head == list->tail) {
    list->head = NULL;
    list->tail = NULL;
  }
  else {
    list->tail = list->tail->prev;
    list->tail->next = NULL;
  }

  free(aux);

  list->size--;
}

bool isPresent(LinkedList *list, int value) {
  if (list == NULL) {
    fprintf(stderr, "ERROR in 'isPresent()':\n null pointer passed as argument.\n");
    exit(EXIT_FAILURE);
  }

  Node *current = list->head;

  while (current != NULL) {
    if (current->data == value) return true;
    current = current->next;
  }

  return false;
}

void printList(LinkedList *list) {
  if (isEmpty(list)) {
    printf("the list is empty.");
    return;
  }

  Node *current = list->head;
  int i = 0;

  while(current != NULL) {
    printf("list[%d]: %d\n", i, current->data);
    current = current->next;
    i++;
  }
}

void printReversedList(LinkedList *list) {
  if (isEmpty(list)) {
    printf("the list is empty.");
    return;
  }

  Node *current = list->tail;
  int i = list->size - 1;

  while (current != NULL) {
    printf("list[%d]: %d\n", i, current->data);
    current = current->prev;
    i--;
  }
}

int getSize(LinkedList *list) {
  return list->size;
}