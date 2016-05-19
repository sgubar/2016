#ifndef SingleLinkedList_h
#define SingleLinkedList_h

#include <stdio.h>

// Predeclaration
typedef struct __IntNode IntNode;

typedef struct __IntList
{
	IntNode *head;
	IntNode *tail;
	int count;
	char name;
}IntList;

extern const int kSLListError;

//Interface
//Create/delete a list
IntList *SLCreateList();
void SLFreeList(IntList *aList);

IntNode *SLAddNode(IntList *aList, IntNode *aNewNode);

int SLCountList(const IntList *aList);
IntNode *SLNodeAtIndex(const IntList *aList, int aIndex);

void *SLSwapNode(const IntList *getList, int getIndex, IntList *postList, int postIndex);

IntNode *SLInsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex);
IntNode *SLRemovedNodeAtIndex(IntList *aList, int anIndex);

void doPrintSLList(const IntList *aList);
void swapMaxMinNode(IntList *aList);
#endif /* SingleLinkedList_h */