#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "bst.h"

#define MAX_LEN 32 /* Maximum length to read */

struct node *root = NULL;

/* Ask user for file to insert names from */
void readFile() {
  printf("Enter filename to read (use 'input.txt' for sample file):");
  char fileName[MAX_LEN];
  fgets(fileName, MAX_LEN, stdin);
  /* Remove newline from input [outside source: https://goo.gl/nj2zPg] */
  if (fileName[strlen(fileName) - 1] == '\n') fileName[strlen(fileName) - 1] = '\0';
  FILE *inputFile = fopen(fileName, "r");
  if (!inputFile) {
    printf("'%s' not found\n\n", fileName);
    return;
  }
  char line[MAX_LEN];
  while (fgets(line, 1000, inputFile) != NULL) { /* Read and insert lines until end of file */
    if (line[strlen(line) - 1] == '\n') line[strlen(line) - 1] = '\0';
    (root == NULL) ? root = insert(root, line) : insert(root, line); /* If the tree is empty, insert as root */
  }
  printf("Read '%s'\n\n", fileName);
  fclose(inputFile);
}

/* Ask user for file to write names into */
void writeFile() {
  printf("Enter filename to write (leave blank to use 'output.txt'):");
  char fileName[MAX_LEN];
  fgets(fileName, MAX_LEN, stdin);
  if (fileName[strlen(fileName) - 1] == '\n') fileName[strlen(fileName) - 1] = '\0';
  FILE *outputFile;
  if (strlen(fileName) == 0) strcpy(fileName, "output.txt");
  outputFile = fopen(fileName, "w");
  writeTree(root, outputFile);
  printf("Output '%s'\n\n", fileName);
  fclose(outputFile);
}

/* Ask user for name to insert into tree */
void insertName() {
  printf("Enter employee name:");
  char name[MAX_LEN];
  fgets(name, MAX_LEN, stdin);
  if (name[strlen(name) - 1] == '\n') name[strlen(name) - 1] = '\0';
  (root == NULL) ? root = insert(root, name) : insert(root, name);
  printf("Added '%s'\n\n", name);
}

/* Ask user for name to remove from tree */
void removeName() {
  printf("Enter employee name:");
  char name[MAX_LEN];
  fgets(name, MAX_LEN, stdin);
  if (name[strlen(name) - 1] == '\n') name[strlen(name) - 1] = '\0';
  root = deleteKey(root, name); /* Change here */
  printf("Removed '%s'\n\n", name);
}

/* User interface */
int main() {
  printf("1: Add a new employee name\n");
  printf("2: Remove an employee name\n");
  printf("3: List all employee names\n");
  printf("4: Read employee names from file\n");
  printf("5: Write employee names to file\n");
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
    case '5':
      writeFile();
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
