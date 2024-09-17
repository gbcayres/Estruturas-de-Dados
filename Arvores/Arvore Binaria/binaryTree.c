#include "binaryTree.h"

typedef struct Node {
  int data;
  struct Node* leftNode;
  struct Node* rightNode;
} Node;

struct BinaryTree{
  Node* root; 
};

BinaryTree* createBinaryTree() {
  BinaryTree *tree = (BinaryTree*)malloc(sizeof(BinaryTree));
  if (tree == NULL) {
    perror("Failed to allocate memory for binary tree.");
    exit(EXIT_FAILURE);
  }

  tree->root = NULL;
  return tree;
}

void destroyNode(Node* node) {
  if (node == NULL) {
    return;
  }

  destroyNode(node->leftNode);
  destroyNode(node->rightNode);
  free(node);
}

void destroyBinaryTree(BinaryTree* tree) {
  if (tree == NULL) {
    return;
  }

  destroyNode(tree->root);
  free(tree);
}
