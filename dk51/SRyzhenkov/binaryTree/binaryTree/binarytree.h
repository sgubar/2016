
//
//  binarytree.h
//  binaryTree
//
//  Created by Serhii Ryzhenkov on 6/8/16.
//  Copyright © 2016 Serhii Ryzhenkov. All rights reserved.
//

#ifndef binarytree_h
#define binarytree_h

#include <stdio.h>

typedef struct __PhoneNote
{
	char *name; //!<- key
	char *number;
}PhoneNote, *PhoneNotePtr;

typedef struct __Node
{
	PhoneNotePtr note;
	struct __Node *leftChild;
	struct __Node *rightChild;
}Node, *NodePtr;

typedef struct __Tree
{
	NodePtr root;
}Tree, *TreePtr;

TreePtr createTree();

void deleteTree(TreePtr aTree);
void delete(NodePtr inputNode);
//int countTree(TreePtr aTree);
//void displayTree(TreePtr aTree);

NodePtr findNode(TreePtr aTree, const char *aName);
void insertNode(TreePtr aTree, char *aName, char *aPhoneNumber);
int deleteNode(TreePtr aTree, const char *aName);

#endif /* tree_h */

#pragma once
