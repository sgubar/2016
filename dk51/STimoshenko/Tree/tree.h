//
//  tree.h
//  demoTree
//
//  Created by Serj Timoshenko on 6/8/16.
//  Copyright © 2016Serj Timoshenko. All rights reserved.
//

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




NodePtr findNode(TreePtr aTree, const char *aName);
void insertNode(TreePtr aTree, char *aName, char *aPhoneNumber);
int deleteNode(TreePtr aTree, const char *aName);

int recursivecounttree(NodePtr theCurrent);
int countTree(TreePtr aTree);
void TreeKiller(TreePtr aTree);
void RecursiveDeleteTree(NodePtr theCurrentNode);

#endif /* tree_h */
