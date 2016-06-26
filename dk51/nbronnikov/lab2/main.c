//
//  Lab2
// 
//
//  Created by Nazar Bronnikov on 09/05/16.
//  Copyright (C) 2016 Nazar Bronnikov. All rights reserved.
//

#include <stdio.h>
#include "List.h"
#include "Node.h"
void doPrintList(const List *aList);
void Sorting(int Array[5]);
int main(void)
{
	int count = 0;
	int anArray[5];
		List *theList = doList();
		doPrintList(theList);
		IntNode *minNode = findMinNode(theList);
		int minimum = minNode->value;
		IntNode *maxNode = findMaxNode(theList);
		int maximum = maxNode->value;
		printf("Min node: %d\nMax node: %d\n", minimum, maximum);
		int swap = minNode->value;
		minNode->value = maxNode->value;
		maxNode->value = swap;
		printf("Swap min and max in list\n");
		doPrintList(theList);
		printf("List after sorting\n");
		Sorting(theList, anArray);
		system("pause");

}
void doPrintList(const List *aList)
{
	
	for (int i = 0; i<CountList(aList); i++)
	{
		IntNode *theNode = NodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d]= %d\n", i, theNode->value);
			 
		}
	}
}
void Sorting(const List *aList, int Array[5] )
{
	int nodeValue;
	int noArray[5];
	for (int i = 0; i < CountList(aList); i++)
	{
		IntNode *theNode = NodeAtIndex(aList, i);
		nodeValue = theNode->value;
		noArray[i] = nodeValue;
	}
	IntNode *minNode = findMinNode(aList);
	int min = minNode->value;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			if (noArray[j] > noArray[j + 1])
			{
				int tmp = noArray[j];
				noArray[j] = noArray[j + 1];
				noArray[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		Array[i] = noArray[i];
		printf("Node[%d] = %d\n", i, Array[i]);
	}

}
