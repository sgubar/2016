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
#include <time.h>
#include <graphics.h>

void launchGraphics();

static void freeNode(NodePtr aNode);
static NodePtr getSuccessor(TreePtr aTree, NodePtr aDelNode);
static void displayBranch(NodePtr inputNode, int x, int y);
void drawNode(NodePtr inputNode, int x, int y);
static int countBranch(NodePtr inputNode, int currentCount);
static void deleteBranch(NodePtr inputNode);

TreePtr createTree()
{
	TreePtr theTree = (TreePtr) malloc(sizeof(Tree));

	if (NULL != theTree) //!<- check correctness of memmory allocatoin
	{
		theTree->root = NULL; //!<- by default the root is NULL - the tree is empty
	}

	return theTree;
}

void deleteTree(TreePtr aTree){
    if(NULL != aTree){
        if(NULL != aTree->root->leftChild) deleteBranch(aTree->root->leftChild);
        if(NULL != aTree->root->rightChild) deleteBranch(aTree->root->rightChild);
    }
    free(aTree);
}

static void deleteBranch(NodePtr inputNode){
    if(NULL != inputNode->leftChild) deleteBranch(inputNode->leftChild);
    if(NULL != inputNode->rightChild) deleteBranch(inputNode->rightChild);
    free(inputNode->note);
    free(inputNode);
}

int countTree(TreePtr aTree){
    int resultLeft = 0;
    int resultRight = 0;
    if(aTree != NULL){
        if(NULL != aTree->root->leftChild){
            resultLeft = countBranch(aTree->root->leftChild, 0);
        }
        if(NULL != aTree->root->rightChild){
            resultRight = countBranch(aTree->root->rightChild, 0);
        }
    }
    return resultLeft+resultRight+1;
}

static int countBranch(NodePtr inputNode, int currentCount){
    int curCoutL = 0;
    int curCoutR = 0;
    if(NULL != inputNode->leftChild){
        curCoutL = countBranch(inputNode->leftChild, currentCount);
    }
    if(NULL != inputNode->rightChild){
        curCoutR = countBranch(inputNode->rightChild, currentCount);
    }
    //printf("Leaving, currentCount: %d, currentNode: %s\n", currentCount, inputNode->note->name);
    return currentCount + curCoutL + curCoutR + 1;
}

void displayTree(TreePtr aTree){
    if(aTree != NULL){
        NodePtr currentNode = aTree->root;
        drawNode(currentNode, getmaxx()/2, 0);
        if(NULL != aTree->root->leftChild){
            displayBranch(aTree->root->leftChild, getmaxx()/2-100, 50);
            line(getmaxx()/2, 0, getmaxx()/2-100, 50);
        }
        if(NULL != aTree->root->rightChild){
            displayBranch(aTree->root->rightChild, getmaxx()/2+100, 50);
            line(getmaxx()/2, 0, getmaxx()/2+100, 50);
        }
    }else{
        printf("Invalid tree!\n");
    }
    system("pause");
    closegraph();
}

static void displayBranch(NodePtr inputNode, int x, int y){
    drawNode(inputNode, x, y);
    if(NULL != inputNode->leftChild){
        displayBranch(inputNode->leftChild, x-100, y+50);
        line(x, y, x-100, y+50);
    }
    if(NULL != inputNode->rightChild){
        displayBranch(inputNode->rightChild, x+100, y+50);
        line(x, y, x+100, y+50);
    }
}

void drawNode(NodePtr inputNode, int x, int y){
    txTextOut(x, y, inputNode->note->name);
    txTextOut(x, y+10, inputNode->note->number);
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
	memset(theNewNode, 0, sizeof(Node));
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

void launchGraphics(){
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "");
    setviewport(0, 0, getmaxx(), getmaxy(), 0);
    setlinestyle(0, 0, 1);
    settextstyle(0, 0, 1);
}

