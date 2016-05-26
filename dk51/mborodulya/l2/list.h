#ifndef list_h
#define list_h


//  list.h
//  linked list
//
//  Created by Masha Borodulya
//  Copyright © 2016 Masha Borodulya. All rights reserved.
//

#include <stdlib.h>
#include "node.h"

struct FloatList
{
    FloatNode *head;
    FloatNode *tail;
    int count;
};

FloatList *CreateFloatList();
void FreeList(FloatList *tmpList);
void AddNodeToList(FloatList *list, FloatNode *nodeToAdd);
int CountList(FloatList *list);
FloatNode *getNodeAtIndex(FloatList *list, int index);
void PrintList(FloatList *list);
void RemoveFloatNode(FloatList *list, int index);
void InsertNodeAtIndex(FloatList *list, FloatNode *newNode, int index);
FloatList *ChangeMinMaxElements(FloatList *list);
void PrintInversedList(FloatList *list);
void PrintTwiceInDirectAndTwiceInInversedDirection(FloatList *list);
void SwapFloatNodes(FloatList *list, int indexFloatNodeOne, int indexFloatNodeTwo);
void BubbleSort(FloatList *list);
void SelectionSort(FloatList *list);

#endif
