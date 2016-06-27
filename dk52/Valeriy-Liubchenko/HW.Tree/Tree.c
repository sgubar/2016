//
// tree.c
// demoTree
//
// Created by Slava Gubar on 5/18/16.
// Copyright © 2016 Slava Gubar. All rights reserved.
//

#include "tree.h"
#include <stdlib.h>
#include <string.h>

static void freeNode(NodePtr aNode);
static NodePtr getSuccessor(TreePtr aTree, NodePtr aDelNode);
void deleteBranch(NodePtr CurrentNode);

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
NodePtr theNewNode = (NodePtr)calloc(1, sizeof(Node));

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
if (NULL !=
aNode->note)
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

int countTree(TreePtr aTree)
{
int result = NULL;
if (aTree != NULL)
{
result = 1;
if (NULL != aTree->root->leftChild){
result = countBr(aTree->root->leftChild, 0);
}
if (NULL != aTree->root->rightChild){
result = countBr(aTree->root->rightChild, 0);
}
}
return result;
}

int countBr(NodePtr currentNode, int current)
{
printf("inputNode: %s\n", currentNode->note->name);
if (NULL != currentNode->leftChild)
current += countBr(currentNode->leftChild, current);
if (NULL != currentNode->rightChild)
current += countBr(currentNode->rightChild, current);
if (NULL == currentNode->rightChild && NULL == currentNode->leftChild)
current++;
current++;
return current;
}

void displayTree(TreePtr aTree)
{
int result = NULL;
if (aTree != NULL)
{
printf("Root: Name: %s = %s\n", aTree->root->note->name, aTree->root->note->number);
if (NULL != aTree->root->leftChild){
result = displayBranch(aTree->root->leftChild, 0);
}
if (NULL != aTree->root->rightChild){
result = displayBranch(aTree->root->rightChild, 0);
}
}
}
int displayBranch(NodePtr currentNode)
{
//printf("level:%d %s\n", currentNode->note->name);
printf("%s = %s\n", currentNode->note->name, currentNode->note->number);
if (NULL != currentNode->leftChild)
{
//printf("leftchild: %s = %s\n",currentNode->note->name,currentNode->note->number);
displayBranch(currentNode->leftChild);

}
if (NULL != currentNode->rightChild)
{
// printf("rightchild: %s = %s\n",currentNode->note->name,currentNode->note->number);
displayBranch(currentNode->rightChild);

}
//printf("\n-----------\n");

}

void deleteTree(TreePtr aTree)
{
if (aTree->root != NULL)
{
if (aTree->root->leftChild != NULL)
{
deleteBranch(aTree->root->leftChild);
freeNode(aTree->root->leftChild);
}
if (aTree->root->rightChild != NULL)
{
deleteBranch(aTree->root->rightChild);
freeNode(aTree->root->rightChild);
}
freeNode(aTree->root);
}
free(aTree);
}

void deleteBranch(NodePtr CurrentNode)
{
if (NULL != CurrentNode->leftChild)
{
deleteBranch(CurrentNode->leftChild);
freeNode(CurrentNode->leftChild);
}
if (NULL != CurrentNode->rightChild)
{
deleteBranch(CurrentNode->rightChild);
freeNode(CurrentNode->rightChild);
}
}
