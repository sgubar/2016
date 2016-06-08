//
//  Main.c
//
//
//  Created by Bogdan Maximovich on 6/08/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
//

#include "tree.h"
#include <stdlib.h>
#include <string.h>

static void freeNode(NodePtr aNode);
static NodePtr getSuccessor(TreePtr aTree, NodePtr aDelNode);
void printBranch(NodePtr CurrentNode, int needlvl, int currentlvl, int lvlSpace);
int maxLevelBranch(NodePtr currentNode, int Result);

TreePtr createTree()
{
	TreePtr theTree = (TreePtr)malloc(sizeof(Tree));

	if (NULL != theTree) //!<- check correctness of memmory allocatoin
	{
		theTree->root = NULL; //!<- by default the root is NULL - the tree is empty
	}

	return theTree;
}


NodePtr findNode(TreePtr aTree, const char *aName)
{
	NodePtr theCurrentNode = aTree->root; //<! - start from root
	int theComparisionResult = 0;

	while ( (theComparisionResult = strcmp(aName, theCurrentNode->note->name))!=0) //<! - walk through the tree
	{
		theCurrentNode = (theComparisionResult < 0)
			? theCurrentNode->leftChild
			: theCurrentNode->rightChild;

		if ( theCurrentNode==NULL)
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
	memset(theNewNode,0, sizeof(Node));

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

//#pragma mark -
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

int  countTree(NodePtr theCurrentNode) {
	if (theCurrentNode == NULL)
		return 0;
	return countTree( theCurrentNode->rightChild)+ countTree(theCurrentNode->leftChild)+1;
}

void deleteTree(TreePtr aTree, NodePtr theCurrentNode) {
	if (theCurrentNode->leftChild != NULL) {
		deleteTree(aTree, theCurrentNode->leftChild);
	}
	if (theCurrentNode->rightChild != NULL) {
		deleteTree(aTree, theCurrentNode->rightChild);
	}

	deleteNode(aTree, theCurrentNode->note->name);

}


void space(int Number)
{
	for (int i = 0;i < Number;i++) printf(" ");
}

void displayTree(TreePtr aTree)
{
	NodePtr CurrentNode = aTree->root;
	space(39);
	printf("%s: %s\n", CurrentNode->note->name, CurrentNode->note->number);
	space(18);
	if (CurrentNode->leftChild != NULL) 
		printf("%s: %s", CurrentNode->leftChild->note->name, CurrentNode->leftChild->note->number);
	space(39);
	if (CurrentNode->rightChild != NULL) 
		printf("%s: %s\n", CurrentNode->rightChild->note->name, CurrentNode->rightChild->note->number);

	int maxLevel = maxLevelTree(aTree);
	for (int i = 3;i < maxLevel + 1;i++)
	{
		if (CurrentNode->leftChild != NULL)	printBranch(CurrentNode->leftChild, i, 2, 50/ (2 * i));
		if (CurrentNode->rightChild != NULL) printBranch(CurrentNode->rightChild, i, 2, 50/ (2 * i));
		printf("\n");
	}

}

int maxLevelTree(TreePtr aTree)
{
	int maxLevelLeft = 0, maxLevelRight = 0, Result = 0;
	if (aTree->root->leftChild != NULL)	maxLevelLeft = maxLevelBranch(aTree->root->leftChild, 1);
	if (aTree->root->rightChild != NULL) maxLevelRight = maxLevelBranch(aTree->root->rightChild, 1);
	if (maxLevelLeft > maxLevelRight) Result = maxLevelLeft;
	if (maxLevelLeft < maxLevelRight) Result = maxLevelRight;

	return Result;
}


int maxLevelBranch(NodePtr currentNode, int Result)
{
	int maxLevelLeft = 0, maxLevelRight = 0;
	if (currentNode->leftChild != NULL) maxLevelLeft = maxLevelBranch(currentNode->leftChild, Result);
	if (currentNode->rightChild != NULL) maxLevelRight = maxLevelBranch(currentNode->rightChild, Result);
	if (maxLevelLeft > maxLevelRight) Result = maxLevelLeft;
	if (maxLevelLeft < maxLevelRight) Result = maxLevelRight;

	return ++Result;
}

void printBranch(NodePtr CurrentNode, int needlvl, int currentlvl, int lvlSpace)
{
	if (needlvl - currentlvl == 1)
	{
		space(lvlSpace);
		if (CurrentNode->leftChild != NULL) printf("%s: %s", 
			CurrentNode->leftChild->note->name, CurrentNode->leftChild->note->number);
		space(lvlSpace);
		if (CurrentNode->rightChild != NULL) printf("%s: %s", 
			CurrentNode->rightChild->note->name, CurrentNode->rightChild->note->number);
		space(lvlSpace);
	}
	else
	{
		if (CurrentNode->leftChild != NULL)	printBranch(CurrentNode->leftChild, needlvl, ++currentlvl, lvlSpace);
		if (CurrentNode->rightChild != NULL) printBranch(CurrentNode->rightChild, needlvl, ++currentlvl, lvlSpace);
	}
}