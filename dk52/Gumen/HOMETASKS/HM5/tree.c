//
//  tree.c
//  demoTree
//
//  Created by Slava Gubar on 5/18/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include "tree.h"
#include <stdlib.h>
#include <string.h>

static void freeNode(NodePtr aNode);
static NodePtr getSuccessor(TreePtr aTree, NodePtr aDelNode);

TreePtr createTree()
{
	TreePtr theTree = (TreePtr)malloc(sizeof(Tree));

	if (NULL != theTree) //!<- check correctness of memmory allocatoin
	{
		theTree->root = NULL; //!<- by default the root is NULL - the tree is empty
	}

	return theTree;
}

void deleteTree(TreePtr aTree,NodePtr aNode)
{
	if (aNode ==NULL)
		return;

	deleteTree(aTree,aNode->leftChild);
	deleteTree(aTree, aNode->rightChild);
	printf("Deleting node '%s'...\n",aNode->note->name);
	removeLeafNode(aTree, aNode->note->name);//start deleting from the minimum node
	printf("Delete successful...\n");
}

void removeLeafNode(TreePtr aTree, const char *aName)
{
	NodePtr theCurrent = aTree->root;
	NodePtr theParent = aTree->root;

	int isLeftChild = 1;
	int theCompare = 0;

	while (0 != (theCompare = strcmp(aName, theCurrent->note->name)))
	{
		theParent = theCurrent;
		if (theCompare < 0)
		{
			isLeftChild = 1; //<!- go to the left
			theCurrent = theCurrent->leftChild;
		}
		else
		{
			isLeftChild = 0; //<!- right node
			theCurrent = theCurrent->rightChild;
		}

		if (NULL == theCurrent)
		{
			// the node is node found
			return;
		}
	}

	//the node does not have children so just remove it
	if (NULL == theCurrent->leftChild && NULL == theCurrent->rightChild)
	{
		if (aTree->root == theCurrent)
		{
			aTree->root = NULL;
		}
		else if (isLeftChild)
		{
			theParent->leftChild = NULL;
		}
		else
		{
			theParent->rightChild = NULL;
		}
	}

	if (theCurrent = NULL)
		return;

	freeNode(theCurrent);
	return;
}

NodePtr findNode(TreePtr aTree, const char *aName)
{
	NodePtr theCurrentNode = aTree->root; //<! - start from root
	int theComparisionResult = 0;

	while (0 != (theComparisionResult = strcmp(aName, theCurrentNode->note->name))) //<! - walk through the tree
	{
		theCurrentNode = (theComparisionResult < 0)
			? theCurrentNode->leftChild
			: theCurrentNode->rightChild;

		if (NULL == theCurrentNode)
		{
			break;
		}
	}

	return theCurrentNode;
}


void insertNode(TreePtr aTree, char *aName, char *aPhoneNumber)
{
	// prepare new Node
	// 1. create new node
	NodePtr theNewNode = (NodePtr)malloc(sizeof(Node));
	memset(theNewNode, 0,sizeof(Node));

	// 2. create new note
	PhoneNotePtr theNote = (PhoneNotePtr)malloc(sizeof(PhoneNote));
	theNote->name = aName;
	theNote->number = aPhoneNumber;

	//3. fill node
	theNewNode->note = theNote;

	if (NULL == aTree->root) //<! - tree is empty, so the root is our node
	{
		aTree->root = theNewNode;
	}
	else
	{
		// start to search appropriate place to insert the new node
		NodePtr theCurrent = aTree->root;
		NodePtr theParent = NULL;

		while (1)
		{
			theParent = theCurrent;
			int theCompare = strcmp(aName, theCurrent->note->name);

			if (theCompare < 0)
			{
				theCurrent = theCurrent->leftChild;
				if (NULL == theCurrent) //<!- the our place: path is finished
				{
					theParent->leftChild = theNewNode;
					break;
				}
			}
			else
			{
				theCurrent = theCurrent->rightChild;
				if (NULL == theCurrent)
				{
					theParent->rightChild = theNewNode;
					break;
				}
			}
		}
	}
}

int deleteNode(TreePtr aTree, const char *aName)
 {
	int theResult = 1;

	//1. Find assumed node to delete
	NodePtr theCurrent = aTree->root;
	NodePtr theParent = aTree->root;

	int isLeftChild = 1;
	int theCompare = 0;
	
	while (0 != (theCompare = strcmp(aName, theCurrent->note->name)))
	{
		theParent = theCurrent;
		if (theCompare < 0)
		{
			isLeftChild = 1; //<!- go to the left
			theCurrent = theCurrent->leftChild;
		}
		else
		{
			isLeftChild = 0; //<!- right node
			theCurrent = theCurrent->rightChild;
		}

		if (NULL == theCurrent)
		{
			// the node is node found
			return theCurrent;
		}
	}

	//if the node does not have children then just remove it
	if (NULL == theCurrent->leftChild && NULL == theCurrent->rightChild)
	{
		if (aTree->root == theCurrent)
		{
			aTree->root = NULL;
		}
		else if (isLeftChild)
		{
			theParent->leftChild = NULL;
		}
		else
		{
			theParent->rightChild = NULL;
		}
	}

	if (theCurrent = NULL)
		return theCurrent;
	else if (NULL == theCurrent->rightChild)//Node has a left child
	{
		if (aTree->root == theCurrent)
		{
			aTree->root = theCurrent->leftChild;
		}
		else if (isLeftChild)
		{
			theParent->leftChild = theCurrent->leftChild;
		}
		else
		{
			theParent->rightChild = theCurrent->leftChild;
		}
	}
	else if (NULL == theCurrent->leftChild)//node has a right child
	{
		if (aTree->root == theCurrent)
		{
			aTree->root = theCurrent->rightChild;
		}
		else if (isLeftChild)
		{
			theParent->leftChild = theCurrent->rightChild;
		}
		else
		{
			theParent->rightChild = theCurrent->rightChild;
		}
	}
	else
	{
		NodePtr theSuccessor = getSuccessor(aTree, theCurrent);
		if (aTree->root == theSuccessor)
		{
			aTree->root = NULL;
		}
		else if (isLeftChild)
		{
			theParent->leftChild = theSuccessor;
		}
		else
		{
			theParent->rightChild = theSuccessor;
		}

	}



	freeNode(theCurrent);
	theResult = 1;

	return aTree->root;
}

#pragma mark -
void freeNode(NodePtr aNode)
{
	if (NULL != aNode)
	{
		if (NULL != aNode->note)
		{
			free(aNode->note);
		}

		free(aNode);
	}
	}

NodePtr getSuccessor(TreePtr aTree, NodePtr aDelNode)
{
	NodePtr theSuccessParent = aDelNode;
	NodePtr theSuccessor = aDelNode;
	NodePtr theCurrent = aDelNode->rightChild; //<! - at first go to right child while left children are present

	while (NULL != theCurrent)
	{
		theSuccessParent = theSuccessor;
		theSuccessor = theCurrent;
		theCurrent = theCurrent->leftChild;
	}

	if (theSuccessor != aDelNode->rightChild)
	{
		theSuccessParent->leftChild = theSuccessor->rightChild;
		theSuccessor->rightChild = aDelNode->rightChild;
	}

	return theSuccessor;
}

		

int countTree(NodePtr aNode)
{
	int count = 0;
	if (aNode != NULL)//if the node isn't empty...
	{
		count++;
		//printf("%s\n", aNode->note->name);
		count = count + countTree(aNode->leftChild);
		count = count + countTree(aNode->rightChild);
	}
	else
	{
		return 0;
	}

	return count;
}


void displayTree(NodePtr aNode)
{
	if (aNode == NULL)
		return;
	printf("%s\n", aNode->note->name);
	displayTree(aNode->leftChild);

	displayTree(aNode->rightChild);
}

/*int AddToArray(NodePtr aNode, char *anArray[], int i)
{
	if (aNode == NULL)
		return i;


	anArray[i] = aNode->note->name;
	i++;
	if (aNode->leftChild != NULL)
		i = AddToArray(aNode->leftChild, anArray, i);
	if (aNode->rightChild != NULL)
		i = AddToArray(aNode->rightChild, anArray, i);
	
	for (int k = 0; k <= 10; k++)
	{
		printf("%s\n", anArray[k]);
	}
	return i;
}*/

/*void printTree(NodePtr aNode)
{
	printf("again");
	int index = 0;
	int index1 = 0;
	int index2 = 0;
	int MaxNumNodes = 1;//maximum number of nodes on the level of the tree
	int i = 0;
	int j = 0;
	char *anArray[1000];
	while (countTree(aNode) >= MaxNumNodes)
	{
		MaxNumNodes = MaxNumNodes + i * 2;
		i++;
	}
	printf("%d", MaxNumNodes);

	
		anArray[index] = aNode->note->name;
		index1 = 2 * index + 1;
		anArray[index1] = aNode->leftChild->note->name;
		index2 = index * 2 + 2; 
		anArray[index2] = aNode->rightChild->note->name;
		aNode = aNode->leftChild;
		index++;
	

	for (int k=0; k <= 3;k++)
	{
		printf("%s\n", anArray[k]);
	}

	
}*/
