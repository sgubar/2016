#ifndef SingleList_h
#define SingleList_h

#include <stdio.h>

typedef struct __CharNode CharNode;

typedef struct __CharList
{
	CharNode *head;
	CharNode *tail;
	int count;
}CharList;

extern const int ListError;

void theBubbleSorting(CharNode *theList, int Count);//funcion for sorting list(the bubble sorting)
CharList *ListCreate();
void FreeList(CharList *aList);

CharNode *NodeAdd(CharList *aList, char *aValue);
CharList *MinMax(CharList *aList);
int CountList(const CharList *aList);
CharNode *NodeAtIndex(const CharList *aList, int aIndex);

CharNode *InsertNodeAtIndex(CharList *aList, CharNode *aNewNode, int anIndex);
CharNode *RemovedNodeAtIndex(CharList *aList, int anIndex);

#endif /* SingleList_h */