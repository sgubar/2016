//  Source.c
//  Laba. 2 var. 13
//
//  Created by Ryzhenkov Serhii on 30/03/16.
//  Copyright © 2016 Ryzhenkov Serhii. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include "Fun.h"
#include "FunList.h"

int main(int argc, const char * argv[])
{

	if (1 == argc) 
	{
		printf("Error");
		return 0;
	}

	IntList *theList = Create_L();
	IntList *MinList = Create_L();

	for (int i = 1; i < argc; i++)
	{
		IntNode *theNode = CreateNode(atoi(argv[i]));
		AddNode(theList, theNode);
		printf("Node: %d\n", theNode->value);
	}

	printf("List: \n");
	PrintList(theList);

	distribution(theList);
	UpdatedValue(theList);

	system("pause");
}