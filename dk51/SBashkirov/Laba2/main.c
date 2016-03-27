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

void PrintList(const IntList *aList);

int main(int argc,char *argv[])
{
	if (argc != 5) printf("Error!\n Need syntax: <FileName> <Number> <FirstBorder> <SecondBorder>");
	else
	{
		IntList *theList = ListCreate();
		ReadTheFile(argv[1],theList);
		printf("No sorting\n");
		PrintList(theList);
		printf("After sorting\n");
		NodeSorting(theList, atof(argv[2]), atof(argv[3]), atof(argv[4]));
		PrintList(theList);
	}
	system("pause");

}

void PrintList(const IntList *aList)
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
