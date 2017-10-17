#include <stdio.h>
#include <memory.h>
#include <malloc.h>
#include "bst.h"

#define MAX_LEN 32

struct node {
  char key[MAX_LEN];
  struct node *left;
  struct node *right;
};

/* Returns a new node with name as key */
struct node *newNode(char name[]) {
  struct node *temp = (struct node *) malloc(sizeof(struct node));
  strcpy(temp->key, name);
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

/* Print tree contents using inorder traversal */
void printTree(struct node *root) {
  if (root != NULL) {
    printTree(root->left);
    printf("%s\n", root->key);
    printTree(root->right);
  }
}

/* Insert name into tree while preserving its structure */
struct node *insert(struct node *root, char keyToInsert[]) {
  /* Base case - tree is empty, return a new node */
  if (root == NULL)
    return newNode(keyToInsert);
  /* Recursive case - search left or right subtree */
  int result = strcmp(keyToInsert, root->key);           /* Compare keyToInsert with node->key */
  if (result < 0)                                        /* keyToInsert < node->key */
    root->left = insert(root->left, keyToInsert);
  else if (result > 0)                                   /* keyToInsert > node->key */
    root->right = insert(root->right, keyToInsert);
  return root;
}

/* Search for a name and remove it from the tree if found */
struct node *deleteKey(struct node *root, char *keyToRemove) {
  /* Base case - tree is empty */
  if (root == NULL)
    return root;
  /* Recursive case - search left or right subtree */
  int result = strcmp(keyToRemove, root->key);
  if (result < 0)                                        /* keyToFind < root->key, search left subtree */
    root->left = deleteKey(root->left, keyToRemove);
  else if (result > 0)                                   /* keyToFind > root->key, search right subtree */
    root->right = deleteKey(root->right, keyToRemove);
  else {                                                 /* keyToFind == root->key, key found */
    if (root->left == NULL) {                          /* root->left is empty, return right subtree */
      struct node *temp = root->right;
      return temp;
    } else if (root->right == NULL) {                  /* root->right is empty, return left subtree */
      struct node *temp = root->left;
      return temp;
    }
    /* Left and right subtree are not empty */
    struct node *temp = root->right;                   /* Find smallest node in right subtree */
    while (temp->left != NULL)
      temp = temp->left;
    strcpy(root->key, temp->key);
    root->right = deleteKey(root->right, temp->key);   /* Remove the node after swapping names */
  }
  return root;
}
