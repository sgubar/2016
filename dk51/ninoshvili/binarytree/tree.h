/*															 /
/  tree.h													 /
/  Binary tree												 /
/															 /
/  Created by Sergey Ninoshvili on 06/25/16.				 /
/  Copyright © 2016 Sergey Ninoshvili. All rights reserved.  /
/															*/

#ifndef tree_h
#define tree_h

#include <stdio.h>

typedef struct
{
	char *name; //!<- key
	char *number;
}phoneNote;

typedef struct
{
	phoneNote *note;
	struct node *leftChild;
	struct node *rightChild;
}node;

typedef struct
{
	node *root;
}Tree;

Tree *createTree();
void deleteTree(node *root, Tree *tree);

int *countTree(node *root, int *count);
int *displayTree(node *root, int *order);

node *findNode(node *root, const char *name);
node *createNode(char *name, char *phoneNumber);
Tree *insertNode(Tree *tree, char *name, char *phoneNumber);
Tree *deleteNode(Tree *tree, const char *name);
node *takeMin(node *parent, node *child);
void freeNode(node *item);

#endif /* tree_h */