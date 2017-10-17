#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "bst.h"

#define MAX_LEN 32

struct node *root = NULL;

void readFile() {
  char line[1000];
  char path[] = "input.txt";
  FILE * file = fopen(path, "r");
  if (!file) {
    printf("Not read\n");
    return;
  }
  while (fgets(line, 1000, file) != NULL) {
    if (line[strlen(line) - 1] == '\n') /* Remove newline from input [outside source: https://goo.gl/nj2zPg] */
      line[strlen(line) - 1] = '\0';
    (root == NULL) ? root = insert(root, line) : insert(root, line); /* If the tree is empty, insert as root */
  }
  printf("Read file successfully\n\n");
  fclose(file);
}

void writeFile() {
  // TODO implement
}

void insertName() {
  printf("Enter employee name:");
  char name[MAX_LEN];
  fgets(name, MAX_LEN, stdin);
  if (name[strlen(name) - 1] == '\n')
    name[strlen(name) - 1] = '\0';
  (root == NULL) ? root = insert(root, name) : insert(root, name);
  printf("Added '%s'\n\n", name);
}

void removeName() {
  printf("Enter employee name:");
  char name[MAX_LEN];
  fgets(name, MAX_LEN, stdin);
  if (name[strlen(name) - 1] == '\n')
    name[strlen(name) - 1] = '\0';
  deleteKey(root, name);
  printf("Removed '%s'\n\n", name);
}

/* User interface for adding, removing, or listing employee names */
int main() {
  printf("1: Add a new employee name\n");
  printf("2: Remove an employee name\n");
  printf("3: List all employee names\n");
  printf("4: Read file\n");
  printf("9: Exit\n");
  char select[MAX_LEN];
  while (select[0] != '9') {
    printf("Enter selection:");
    fgets(select, MAX_LEN, stdin);
    switch (select[0]) {
    case '1':
      insertName();
      break;
    case '2':
      removeName();
      break;
    case '3':
      printTree(root);
      printf("\n");
      break;
    case '4':
      readFile();
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
