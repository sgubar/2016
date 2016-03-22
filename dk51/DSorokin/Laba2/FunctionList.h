#ifndef FUNCTIONLIST_H_INCLUDED
#define FUNCTIONLIST_H_INCLUDED


typedef struct __IntNode IntNode;
typedef struct __IntList
{
	IntNode *head;
	IntNode *tail;
}IntList;

IntList *CreateList();
void FreeList(IntList *aList);
IntNode *AddNode(IntList *aList, IntNode *aNewNode);

//int CountList(const IntList *aList);
//IntNode *NodeAtIndex(const IntList *aList, int aIndex);

#endif // FUNCTIONLIST_H_INCLUDED
