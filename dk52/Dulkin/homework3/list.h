#ifndef SingleList_h
#define SingleList_h

#include <stdio.h>

typedef struct __FloatNode FloatNode;

typedef struct __FloatList
{
	FloatNode *head;
	FloatNode *tail;
	int count;
}FloatList;

extern const int ListError;


FloatList *ListCreate();
void FreeList(FloatList *aList);

FloatNode *NodeAdd(FloatList *aList, float aValue);
FloatList *MinMax(FloatList *aList);
FloatList *deleteKeys(FloatList *aList, float key1, float key2, float key3);
int CountList(const FloatList *aList);
FloatNode *NodeAtIndex(const FloatList *aList, int aIndex);

FloatNode *InsertNodeAtIndex(FloatList *aList, FloatNode *aNewNode, int anIndex);
FloatNode *RemovedNodeAtIndex(FloatList *aList, int anIndex);

#endif /* SingleList_h */
