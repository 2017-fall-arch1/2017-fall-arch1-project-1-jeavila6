#ifndef BST_H
#define BST_H

struct node;

struct node *newNode(char name[]);

void printTree(struct node *root);

struct node *insert(struct node *root, char keyToInsert[]);

struct node *deleteKey(struct node *root, char *keyToRemove);

#endif
