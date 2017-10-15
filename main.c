#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

struct node {
  char key[20];
  struct node *left;
  struct node *right;
};

// Returns a new node with name as key
struct node *newNode(char name[]) {
  struct node *temp = (struct node *) malloc(sizeof(struct node));
  strcpy(temp->key, name);
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

// Print tree contents using inorder traversal
void printTree(struct node *root) {
  if (root != NULL) {
    printTree(root->left);
    printf("%s\n", root->key);
    printTree(root->right);
  }
}

// Insert name into tree while preserving its structure
struct node *insert(struct node *node, char keyToInsert[]) {
  // Nowhere to go, return a new node
  if (node == NULL)
    return newNode(keyToInsert);
  // Search for proper place
  int result = strcmp(keyToInsert, node->key); // Compare the strings
  if (result < 0)                              // keyToInsert < node->k
    node->left = insert(node->left, keyToInsert);
  else if (result > 0)                         // keyToInsert > node->key
    node->right = insert(node->right, keyToInsert);
  return node;
}

void testInsertion() {
  struct node *root = NULL;
  root = insert(root, "Carmon");
  insert(root, "Mark");
  insert(root, "John");
  insert(root, "Alex");
  insert(root, "Dan");
  insert(root, "Ben");
  insert(root, "Zach");
  printTree(root);
}

int main() {
  testInsertion();
  return 0;
}
