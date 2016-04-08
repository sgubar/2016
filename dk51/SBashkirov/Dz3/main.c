//
//  main.c
//  Laba 2
//
//  Created by Stanislav Bashkirov on 3/21/16.
//  Copyright © 2016 Stanislav Bashkirov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "SingleList.h"
#include "WorkWithFile.h"
#include "Sorting.h"
#include "SingleNode.h"

void PrintList(const FloatList *aList);

int main(int argc,char *argv[])
{
	if (argc != 5) printf("Error!\n Need syntax: <FileName> <Number> <FirstBorder> <SecondBorder>");
	else
	{
		if (argv[3] > argv[4]) printf("Error!\n FirstBorder > SecondBorder!!!\n Need: FirstBorder < SecondBorder");
		else
		{
			FloatList *theList = ListCreate();
			ReadTheFile(argv[1], theList);
			printf("The List: \n");
			PrintList(theList);
			MinMax(theList);
			printf("Your keys: %s %s %s\n", argv[2], argv[3], argv[4]);
			deleteKeys(theList, atof(argv[2]), atof(argv[3]), atof(argv[4]));
			printf("No sorting, exchange min max, deleting keys\n");
			PrintList(theList);
			NodeSorting(theList, atof(argv[2]), atof(argv[3]), atof(argv[4]));
			printf("After sorting\n");
			PrintList(theList);
			printf("insertion Sort:\n");
			insertionSort(theList);
			PrintList(theList);
		}
	}
	system("pause");

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
