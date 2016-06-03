
#ifndef tree_h
#define tree_h

#include <stdio.h>
#include <string.h>

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

int countTree(TreePtr aTree);
void displayTree(TreePtr aTree);

NodePtr findNode(TreePtr aTree, const char *aName);
void insertNode(TreePtr aTree, char *aName, char *aPhoneNumber);
int deleteNode(TreePtr aTree, const char *aName);

int RecursiveCountTree(NodePtr CurrentNode);
int maxLevelTree(TreePtr aTree);
void printBranch(NodePtr CurrentNode, int needlvl, int currentlvl, int lvlSpace);
int maxLevelBranch(NodePtr currentNode, int Result);

#endif /* tree_h */