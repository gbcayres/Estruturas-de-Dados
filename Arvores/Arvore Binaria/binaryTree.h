#include <stdbool.h>
#include <stdlib.h>

typedef struct BinaryTree BinaryTree;

BinaryTree* createBinaryTree();
void destroyBinaryTree(BinaryTree *tree);
 
void insertNode(BinaryTree *tree, int data);
void searchNode(BinaryTree *tree, int data);

void preorderTransversal(BinaryTree *tree);
void inorderTransversal(BinaryTree *tree);
void postorderTransversal(BinaryTree *tree);