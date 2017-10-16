#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX_LEN 32

struct node *root = NULL;

struct node {
  char key[MAX_LEN];
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
  // Base case: return a new node
  if (node == NULL)
    return newNode(keyToInsert);
  // Recursive case: search left or right subtree
  int result = strcmp(keyToInsert, node->key); // Compare keyToInsert with node->key
  if (result < 0)                              // keyToInsert < node->key
    node->left = insert(node->left, keyToInsert);
  else if (result > 0)                         // keyToInsert > node->key
    node->right = insert(node->right, keyToInsert);
  return node;
}

void insertName() {
  printf("Enter employee name:");
  char name[MAX_LEN];
  fgets(name, MAX_LEN, stdin);
  if (name[strlen(name)-1] == '\n') // Remove newline from input [outside source: https://goo.gl/nj2zPg]
    name[strlen(name)-1] = '\0';
  (root == NULL) ? root = insert(root, name) : insert(root, name); // If the tree is empty, insert as root
  printf("Added '%s'\n\n", name);
}

// User interface for adding, removing, or listing employee names
int main() {
  printf("0: Add a new employee name\n");
  printf("2: List all employee names\n");
  printf("9: Exit\n");
  char select[MAX_LEN];
  while (select[0] != '9') {
    printf("Enter selection:");
    fgets(select, MAX_LEN, stdin);
    switch (select[0]) {
    case '0':
      insertName();
      break;
    case '2':
      printTree(root);
      printf("\n");
      break;
    case '9':
      printf("Goodbye\n");
      break;
    default:
      printf("Invalid option\n");
      break;
    }
  }
  return 0;
}
