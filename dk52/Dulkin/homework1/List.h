#ifndef List_h
#define List_h

#include <stdio.h>

// Predeclaration
typedef struct __IntNode IntNode;

typedef struct __IntList
{
	IntNode *head;
	IntNode *tail;
	int count;
}IntList;

extern const int kSLListError;

//Interface
//Create/delete a list
IntList *CreateList();
void SetFree(IntList *InList);

IntNode *AddNode(IntList *InList, IntNode *aNewNode);

int ListSize(const IntList *InList);
IntNode *NodeAt(const IntList *InList, int aIndex);

//TODO: house work
IntNode *InsertAt(IntList *InList, IntNode *aNewNode, int anIndex);
IntNode *DeleteAt(IntList *InList, int anIndex);

#endif /* SingleLinkedList_h */
