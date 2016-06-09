//
//  tree.c
//  demoTree
//
//  Created by Slava Gubar on 5/18/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include "tree.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

static void freeNode(NodePtr aNode);
static NodePtr getSuccessor(TreePtr aTree, NodePtr aDelNode);

TreePtr createTree()
{
	TreePtr theTree = (TreePtr) malloc(sizeof(Tree));
	
	if (NULL != theTree) //!<- check correctness of memmory allocatoin
	{
		theTree->root = NULL; //!<- by default the root is NULL - the tree is empty
	}

	return theTree;
}

void deleteTree(TreePtr inTree)
{
	if (NULL != inTree->root)
	{
		if (NULL != inTree->root->leftChild)
		{
			deleteBranch(inTree->root->leftChild);
		}
		if (NULL != inTree->root->rightChild)
		{
			deleteBranch(inTree->root->rightChild);
		}
		freeNode(inTree->root);
	}
	free(inTree);
}

void deleteBranch(NodePtr aTmpNode)
{
	if (NULL != aTmpNode->leftChild)
	{
		deleteBranch(aTmpNode->leftChild);
		freeNode(aTmpNode->leftChild);
		free(aTmpNode->note);
		free(aTmpNode);
	}
	if (NULL != aTmpNode->rightChild)
	{
		deleteBranch(aTmpNode->rightChild);
		freeNode(aTmpNode->rightChild);
		free(aTmpNode->note);
		free(aTmpNode);
	}
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
	//bzero(theNewNode, sizeof(Node));
	
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
			return 0;
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
	else if (NULL == theCurrent->rightChild)
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
	else if (NULL == theCurrent->leftChild)
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
	
	return theResult;
}

#pragma mark -
void freeNode(NodePtr aNode)
{
	if (NULL != aNode)
	{
		if (NULL != aNode->note)
		{
			free (aNode->note);
		}
	
		free (aNode);
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

int countTree(TreePtr aTree)
{
	int result = 0;
	NodePtr theCurrentNode = aTree->root;
	if (NULL != aTree->root)
	{
		result = 1;
		if (theCurrentNode->leftChild != NULL)
		{
			result++;
			result += RCountTree(theCurrentNode->leftChild);
		}
		if (theCurrentNode->rightChild != NULL)
		{
			result++;
			result += RCountTree(theCurrentNode->rightChild);
		}
	}
	return result;
}

int RCountTree(NodePtr aTmpNode)
{
	int theResult = 0;
	if (aTmpNode->leftChild != NULL)
	{
		theResult++;
		theResult += RCountTree(aTmpNode->leftChild);
	}
	if (aTmpNode->rightChild != NULL)
	{
		theResult++;
	    theResult += RCountTree(aTmpNode->rightChild);
	}
	return theResult;
}

void displayTree(TreePtr aTree)
{
	NodePtr aTmpNode = aTree->root;
	if (NULL != aTree->root)
	{
		printf("%s - %s", aTmpNode->note->name, aTmpNode->note->number);
		if (NULL != aTmpNode->leftChild)
			{
				printf("%s - %s\n", aTmpNode->leftChild->note->name, aTmpNode->leftChild->note->number);
			}
		if (NULL != aTmpNode->rightChild)
			{
				printf("%s-%s\n", aTmpNode->rightChild->note->name, aTmpNode->rightChild->note->number);
			}
		printf("Left Branch\n");
		PrintBranchleft(aTmpNode->leftChild);
		printf("Right Branch\n");
		PrintBranchright(aTmpNode->rightChild);
	}
}

void PrintBranchleft(NodePtr aTmpNode)
{
	if (NULL != aTmpNode->leftChild)
	{
		printf("%s-%s\n", aTmpNode->leftChild->note->name, aTmpNode->leftChild->note->number);
		PrintBranchleft(aTmpNode->leftChild);
	}
}

void PrintBranchright(NodePtr aTmpNode)
{
	if (NULL != aTmpNode->rightChild)
	{
		printf("%s-%s\n", aTmpNode->rightChild->note->name, aTmpNode->rightChild->note->number);
		PrintBranchright(aTmpNode->rightChild);
	}
}