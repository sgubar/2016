//
//  tree.h
//  demoTree
//
//  Created by Slava Gubar on 5/18/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
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
void deleteTree(TreePtr aTree);
void deleteBranch(NodePtr CurrentNode);

int countTree(TreePtr aTree);
void displayTree(TreePtr aTree);
int maxLevelTree(TreePtr aTree);
int maxLevelBranch(NodePtr currentNode,int Result);

void printBranch(NodePtr CurrentNode, int needlvl,int currentlvl,int lvlSpace);
NodePtr findNode(TreePtr aTree, const char *aName);
void insertNode(TreePtr aTree, char *aName, char *aPhoneNumber);
int deleteNode(TreePtr aTree, const char *aName);

int RecursiveCountTree(NodePtr CurrentNode);

#endif /* tree_h */
