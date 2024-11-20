#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
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
  }

  LinkedList *list = *list_ref;

  Node *aux = NULL;
  Node *current = list->head;

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
  
  return node;
}

bool isEmpty(LinkedList *list) {
  return list->head == NULL && list->tail == NULL;
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
    list->tail = newNode;
  } else {
    list->tail->next = newNode;
    list->tail = newNode;
  }

  list->size++;
}


void insertAtPosition(LinkedList *list, int position, int value) {
  if (list == NULL) {
    fprintf(stderr, "ERROR in 'insertAtPosition()':\n null pointer passed as argument.\n");
    exit(EXIT_FAILURE);
  }

  if (position < 0) {
    fprintf(stderr, "ERROR in 'insertAtPosition()':\n invalid index.\n");
    exit(EXIT_FAILURE);
  }

  if (isEmpty(list) || position == 0) {
    insertAtBegin(list, value);
    return;
  }

  Node *current = list->head;
  int i = 0;

  while (current != NULL && i < position - 1) {
    current = current->next;
    i++;
  }

  if (current == NULL) {
    fprintf(stderr, "ERROR in 'insertAtPosition()':\n index out of bounds.\n");
    exit(EXIT_FAILURE);
  }

  Node *newNode = createNode(value);

  newNode->next = current->next;
  current->next = newNode;

  list->size++;
}

void removeAtBegin(LinkedList *list) {
  if (isEmpty(list)) {
    fprintf(stderr, "ERROR in 'removeAtBegin()':\n the list is empty.\n");
    exit(EXIT_FAILURE);
  }

  Node *temp = list->head;

  list->head = list->head->next;

  free(temp);

  list->size--;
}

void removeAtPosition(LinkedList *list, int position) {
  if (list == NULL) {
    fprintf(stderr, "ERROR in 'removeAtPosition()':\n null pointer passed as argument.\n");
    exit(EXIT_FAILURE);
  }

  if (position < 0) {
    fprintf(stderr, "ERROR in 'removeAtPosition()':\n invalid index.\n");
    exit(EXIT_FAILURE);
  }

  if (isEmpty(list) || position == 0) {
    removeAtBegin(list);
    return;
  }

  Node *current = list->head;
  int i = 0;

  while (current != NULL && i < position - 1) {
    current = current->next;
    i++;
  }

  if (current == NULL || current->next == NULL) {
    fprintf(stderr, "ERROR in 'removeAtPosition()':\n index out of bounds.\n");
    exit(EXIT_FAILURE);
  }

  Node *temp = current->next;

  current->next = current->next->next;

  free(temp);

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

int getSize(LinkedList *list) {
  return list->size;
}