#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#ifndef SingleLinkedList_h
#define SingleLinkedList_h
#include <stdio.h>

CreateN(int argv);





typedef struct __IntNode IntNode;
typedef struct __IntList
{
	IntNode *head;
	IntNode *tail;
	int count;
}
IntList;

IntList *CreateL();
void FreeList(IntList *aList);
IntNode *SLAddNode(IntList *aList, IntNode *aNewNode);

int SLCountList(const IntList *aList);
IntNode *SLNodeAtIndex(const IntList *aList, int aIndex);


#endif /* SingleLinkedList_h */
#endif // HEADER_H_INCLUDED
