#ifndef SingleLIST_h
#define SingleLIST_h

#include <stdio.h>

// Predeclaration
typedef struct __MyNode MyNode;

typedef struct _MyList
{
	MyNode *top;
	MyNode *bottom;
	int count;
}MyList;

MyList *CreateANewList();
void FreeMyList(MyList *aList);

MyNode *AddNode(MyList *aList, MyNode *NewNode);
int ListCounter(const MyList *aList);
MyNode *NodeAtIndex(const MyList *aList, int count);
MyNode *InsertNode(MyList *aList, MyNode *NewNode, int index);
MyNode *DeletedNode(MyList *aList, int index);

#endif

