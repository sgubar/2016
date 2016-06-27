//
//  main.c
//  Lab2
//
//  Created by Andrew Toporivskiy on 6/26/16.
//  Copyright © 2016 Andrew Toporivskiy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h"
#include "bubbleSort.h"
#include "SingleLinkedNode.h"

void printList(const IntList *aList);

int main(int argc, char *argv[])
{
	if (argc != 3) printf("Correct syntax: <FileName> <Key>");
	else
	{
		IntList *theList = CreateList();
		printf("The List: \n");
		printList(theList);

		MinMax_Swapper(theList);
		printf("Swapped min max nodes:\n");

		printf("Your key: %s\n", argv[2]);
		DeleteByKey(theList, atof(argv[2]));
		printf("Deleted by key:\n");
		printList(theList);

		bubbleSorting(theList);
		printf("Sorted:\n");
		printList(theList);
	}
	system("pause");

}

void printList(const IntList *aList)
{
	for (int i = 0; i < CountList(aList); i++)
	{
		IntNode *theNode = NodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}
