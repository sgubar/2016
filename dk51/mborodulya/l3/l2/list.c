
//  list.c
//  linked list
//
//  Created by Masha Borodulya
//  Copyright © 2016 Masha Borodulya. All rights reserved.
//

#include "list.h"
#include "node.h"
#include <stdlib.h>

FloatList *CreateFloatList()
{
    FloatList *theList = (FloatList *)malloc(sizeof(FloatList));

    theList->head = NULL;
	theList->tail = NULL;
	theList->count = 0;

	return theList;
}

void FreeList(FloatList *tmpList)
{
    if (NULL == tmpList)
	{
		return;
	}
    FloatNode *theNode = tmpList->head;
    while (NULL != theNode)
    {
        FloatNode *theNodeToBeFree = theNode;
        theNode = theNode->nextNode;
        free(theNodeToBeFree);
    }

    free(tmpList);
}

void AddNodeToList(FloatList *list, FloatNode *nodeToAdd)
{
    if (NULL == list || NULL == nodeToAdd)
    {
        return;
    }
    if (NULL == list->head && NULL == list->tail)
	{
		list->head = list->tail = nodeToAdd;
	} else {
        FloatNode *tmpTail = list->tail;
        list->tail = nodeToAdd;
        if (NULL != tmpTail)
        {
            tmpTail->nextNode = list->tail;
        }
	}
    list->count += 1;
}

int CountList(FloatList *list)
{
    if (list != NULL)
    {
        return list->count;
    }
    return -1;
}

FloatNode *getNodeAtIndex(FloatList *list, int index)
{
    FloatNode *smth = NULL;
    if (list != NULL && index < list->count)
    {
        int i = 0;
        FloatNode *tmpNode = list->head;
        do
        {
            if (i == index)
            {
                return tmpNode;
            }

            i++;
            tmpNode = tmpNode->nextNode;
        } while(tmpNode != NULL);
    }
    return smth;
}


void PrintList(FloatList *list)
{
	for (int i = 0; i < CountList(list); i++)
	{
		FloatNode *theNode = getNodeAtIndex(list, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %5.2f\n", i, theNode->value);
		}
    }
    printf("\n");

}


void PrintInversedList(FloatList *list)
{

	for (int i = CountList(list)-1; i >= 0; i--)
	{
		FloatNode *theNode = getNodeAtIndex(list, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %5.2f\n", i, theNode->value);
		}
    }
    printf("\n");
}

void PrintTwiceInDirectAndTwiceInInversedDirection(FloatList *list)
{
    PrintList(list);
    PrintList(list);
    PrintInversedList(list);
    PrintInversedList(list);
}

void RemoveFloatNode(FloatList *list, int index)
{

    if (list != NULL && list->count>index)
    {

		if (0 == index)
		{
			FloatNode *NextNode = getNodeAtIndex(list, index + 1);
			list->head= NextNode;
			list->count -= 1;
		}
		else
		{
			FloatNode *PrevNode = getNodeAtIndex(list, index - 1);
			FloatNode *NextNode = getNodeAtIndex(list, index + 1);
			if (index == CountList(list)-1)
			{
                PrevNode->nextNode = NULL;
                list->tail = PrevNode;
			}
			else
			{
                PrevNode->nextNode = NextNode;
			}
			list->count -= 1;

			//printf("%f", PrevNode->value);
		}
    }
}

FloatList *ChangeMinMaxElements(FloatList *list)
{
    FloatNode *min = list->tail,
              *max = list->head;
    int minIndex = CountList(list)-1, maxIndex = 0;

    for (int i = 0; i < list->count;i++)
	{
        FloatNode *theNode = getNodeAtIndex(list,i);
        if (min->value > theNode->value)
		{
			min = theNode;
			minIndex = i;
		}
		if (max->value < theNode->value)
        {
            max = theNode;
            maxIndex = i;
        }
    }
    printf("%d %d\n", minIndex, maxIndex);
    if (minIndex < maxIndex)
    {
            SwapFloatNodes(list, minIndex, maxIndex);
    } else {
            SwapFloatNodes(list, maxIndex, minIndex);
    }

    return list;

}

void InsertNodeAtIndex(FloatList *list, FloatNode *newNode, int index)
{
    if (NULL == list || NULL == newNode || index > list->count)
	{
		return;
    }

    if (0 == index)
    {
        newNode->nextNode = list->head;
        list->head = newNode;
        list->count += 1;
    }
    else
    {
        FloatNode *PrevNode = getNodeAtIndex(list, index - 1);
        if (index == list->count) list->tail = newNode;
        else newNode->nextNode = PrevNode->nextNode;
        PrevNode->nextNode = newNode;
        list->count += 1;
    }
}

void BubbleSort(FloatList *list)
{
    int length = CountList(list);
    for (int i = 0; i < length-1; i++) {
         for (int j = i; j < length-i-1; j++) {
             if (getNodeAtIndex(list, j)->value > getNodeAtIndex(list, j+1)->value) {
                SwapFloatNodes(list, j, j+1);
             }
         }
    }

}

void SelectionSort(FloatList *list)
{
    int length = CountList(list);
    for (int i = 0; i < length - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < length; j++)
        {
            if (getNodeAtIndex(list, j)->value < getNodeAtIndex(list, minIndex)->value)
            {
                minIndex = j;
            }

        }
        if (minIndex != i)
        {
            SwapFloatNodes(list, i, minIndex);
        }
    }

}


void SwapFloatNodes(FloatList *list, int indexFloatNodeOne, int indexFloatNodeTwo)
{
    FloatNode *NodeOne = getNodeAtIndex(list, indexFloatNodeOne);
    FloatNode *NodeTwo = getNodeAtIndex(list, indexFloatNodeTwo);
    RemoveFloatNode(list, indexFloatNodeTwo);
    RemoveFloatNode(list, indexFloatNodeOne);
    InsertNodeAtIndex(list, NodeTwo, indexFloatNodeOne);
    InsertNodeAtIndex(list, NodeOne, indexFloatNodeTwo);
}


