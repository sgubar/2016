#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "sortLib.h"
#include "node.h"

void PrintList(const FloatList *aList);
void PrintInversedList(const FloatList *aList);

int main()
{
	FloatList *theList = ListCreate();
	FloatList *newList = ListCreate();
	FloatList *sortedList = ListCreate();
	NodeAdd(theList, 1);
	NodeAdd(theList, 2);
	NodeAdd(theList, 3);
	NodeAdd(theList, 4);
	NodeAdd(theList, 5);
	NodeAdd(theList, 6);
	NodeAdd(theList, 7);


	PrintList(theList);
	printf("\n");

    //inversed list
	PrintInversedList(theList);
	printf("\n");

    //deleting
    RemovedNodeAtIndex(theList, 3);
    PrintList(theList);
	printf("\n");

	//minmax
	newList = MinMax(theList);
	PrintList(newList);
	printf("\n");

    //sorted list

    sortedList = Sorting(theList,3,0,6);
    PrintList(theList);
	printf("\n");

}

void PrintList(const FloatList *aList)
{
	for (int i = 0; i < CountList(aList); i++)
	{
		FloatNode *theNode = NodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %.3f\n", i, theNode->value);
		}
	}
}

void PrintInversedList(const FloatList *aList)
{
	int i = CountList(aList);
	for (i; i >= 0 ; i--)
	{
		FloatNode *theNode = NodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %.3f\n", i, theNode->value);
		}
	}
}
