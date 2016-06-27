/*															 /
/  tree.c													 /
/  Binary tree												 /
/															 /
/  Created by Sergey Ninoshvili on 06/25/16.				 /
/  Copyright © 2016 Sergey Ninoshvili. All rights reserved.  /
/															*/
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


Tree *createTree()
{
	Tree *tree = (Tree*)malloc(sizeof(Tree));
	
	if(tree != NULL) //check for allocated memory
		tree->root = NULL;//empty tree

	return tree;
}
void deleteTree(node *root, Tree *tree)
{
	if (root == NULL)
		return;

	node *leftSub_tree = root->leftChild;
	node *rightSub_tree = root->rightChild;


	deleteTree(leftSub_tree, tree);
	deleteTree(rightSub_tree, tree);

//  check for leaf left sub-tree
	if (leftSub_tree != NULL)
			root->leftChild = NULL;
	
// check for leaf right sub-tree
	if (rightSub_tree != NULL)
			root->rightChild = NULL;
// leaf node
	if (root->leftChild == NULL && root->rightChild == NULL)
	{
		if (root == tree->root)
			tree->root = NULL;
		freeNode(root);
		root = NULL;
	}
}

int *countTree(node *root, int *count)
{
	if (root == NULL)
		return *count;
	
	countTree(root->leftChild, count);
	++(*count);
	countTree(root->rightChild, count);
}
int *displayTree(node *root, int *order)
{
	if (root == NULL)
		return *order;

	displayTree(root->leftChild, order);
	++(*order);
	printf("\n%3d:\tname:%s \tphone:%s\n", *order, root->note->name, root->note->number);
	displayTree(root->rightChild, order);
}

node *findNode(node *root, const char *name)
{
	if (root == NULL)
		return NULL;
	if (root->note->name == name)
		return root;

	else
	{
		int compare = strcmp(root->note->name, name);

		root = (compare > 0) ? root->leftChild : root->rightChild;
//		choose branch after compare to left^   or   right^ way
		return findNode(root, name);
//                       ^root of left or righ sub-tree
	}
}
Tree *insertNode(Tree *tree, char *name, char *phoneNumber)
{
	if (tree == NULL)
		return NULL;

	node *item = (node*)malloc(sizeof(node));

	if(item != NULL)
		item->note = (phoneNote*)malloc(sizeof(phoneNote));
	
	if (item != NULL)
	{
		item->leftChild = item->rightChild = NULL;

		item->note->name = name;
		item->note->number = phoneNumber;
//      check for empty tree
		if (tree->root == NULL)
			tree->root = item;
		else
		{
			node *parent = tree->root;
			node *current = NULL;

			while (1)
			{
				int compare = strcmp(parent->note->name, item->note->name);
//														 ^this node we want to insert
				if (compare > 0 || compare == 0)
				{
//					parent node bigger then insertion node
					current = parent->leftChild;
					if (current == NULL)
					{
						parent->leftChild = item;
						return tree;
					}
					
					parent = current;
				}
				if (compare < 0)
				{
//					parent node lesser then insertion node
					current = parent->rightChild;
					if (current == NULL)
					{
						parent->rightChild = item;
						return tree;
					}
//					go to another node of this branch
					parent = current;
				}
			}
		}
	}
}

node *takeMin(node *parent, node *child)
{
	if (child != NULL && parent != NULL)
	{
		if (child->leftChild == NULL)
		{
			parent->rightChild = child->rightChild;
			return child;
		}

		while (child->leftChild != NULL)
		{
			parent = child;
			child = child->leftChild;

			if (child->leftChild == NULL)
				parent->leftChild = child->rightChild;
		}
		return child;
	}
}
void freeNode(node *item)
{
	if (NULL != item)
	{
		if (NULL != item->note)
		{
			free(item->note);
		}

		free(item);
	}
	item->note = NULL;
	item = NULL;
}
Tree *deleteNode(Tree *tree, const char *name)
{
	node *current = tree->root;
	node *parent = tree->root;

	int compare = strcmp(current->note->name, name);
//  user want to delete root 
	if (compare == 0)
	{
//      find successor for deleting node
		node *item = takeMin(tree->root, tree->root->rightChild);

//		in what sub-tree we deleting node...
		if (tree->root->rightChild != item)
			item->rightChild = tree->root->rightChild;

		item->leftChild = tree->root->leftChild;

		printf("\nfound note with name %s,\nand phone %s,\ndestroing...\n", tree->root->note->name, tree->root->note->number);
		freeNode(current);
		printf("done\n");

		tree->root = item;

		return tree;
	}

	while (compare != 0)
	{
//      node with this key must be on the left branch
		if (compare > 0)
		{
			parent = current;
			current = current->leftChild;
		}
//      node with this key must be on the right branch
		if (compare < 0)
		{
			parent = current;
			current = current->rightChild;
		}

		if( current != NULL)
			compare = strcmp(current->note->name, name);
		else return NULL;
	}
//  deleting leaf node
	if (current->rightChild == NULL && current->leftChild == NULL)
	{
		if (parent->rightChild == current)
			parent->rightChild = NULL;
		else parent->leftChild = NULL;
		printf("\nfound note with name %s,\nand phone %s,\ndestroing...\n", current->note->name, current->note->number);
		freeNode(current);
		printf("done!\n");
	}
//  deleting node with one child
	else if (current->leftChild != NULL && current->rightChild == NULL)
	{
		if(parent->leftChild == current)
			parent->leftChild = current->leftChild;
		else parent->rightChild = current->leftChild;
		printf("\nfound note with name %s,\nand phone %s,\ndestroing...\n", current->note->name, current->note->number);
		freeNode(current);
		printf("done\n");
	}
	else if (current->rightChild != NULL && current->leftChild == NULL)
	{
		if(parent->rightChild == current)
			parent->rightChild = current->rightChild;
		else parent->leftChild = current->rightChild;
		printf("\nfound note with name %s,\nand phone %s,\ndestroing...\n", current->note->name, current->note->number);
		freeNode(current);
		printf("done\n");
	}
//  deleting node with two children
	else
	{
//      find successor for deleting node
		node *item = takeMin(current, current->rightChild);

//		in what sub-tree we deleting node...
		if(parent->rightChild == current)
			parent->rightChild = item;
		else parent->leftChild = item;

		if(current->rightChild != item)
			item->rightChild = current->rightChild;

		item->leftChild = current->leftChild;
		printf("\nfound note with name %s,\nand phone %s,\ndestroing...\n", current->note->name, current->note->number);
		freeNode(current);
		printf("done\n");
	}
	return tree;
}
