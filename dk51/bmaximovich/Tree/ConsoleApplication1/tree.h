//
//  tree.h
//
//
//  Created by Bogdan Maximovich on 6/08/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
//

#pragma once
#ifndef tree_h
#define tree_h

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
void deleteTree(TreePtr aTree,NodePtr theCurrentNode);

int countTree( NodePtr theCurrentNode);
void displayTree(TreePtr aTree);

NodePtr findNode(TreePtr aTree, const char *aName);
void insertNode(TreePtr aTree, char *aName, char *aPhoneNumber);
int deleteNode(TreePtr aTree, const char *aName);

#endif /* tree_h */