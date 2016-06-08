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
	NodeAdd(theList, 3);
	NodeAdd(theList, 6);
	NodeAdd(theList, 2);
	NodeAdd(theList, 5);
	NodeAdd(theList, 4);
	NodeAdd(theList, 7);


	PrintList(theList);
	printf("\n");

    printf("Inversed List:\n");
	PrintInversedList(theList);
	printf("\n");

    printf("Deleted w/key List:\n");
    RemovedNodeAtIndex(theList, 3);
    PrintList(theList);
	printf("\n");

	printf("Min/Max swap List:\n");
	newList = MinMax(theList);
	PrintList(newList);
	printf("\n");

	printf("Sorted List:\n");
    sortedList = Sorting(theList);
    PrintList(theList);
	printf("\n");

}

void PrintList(const FloatList *aList)
{
	int i;
	for (i = 0; i < CountList(aList); i++)
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
