//
//  main.c
//  Lab2
//
//  Created by Timoshenko Serj on 3/29/16.
//  Copyright (C) 2016 Timoshenko Serj. All rights reserved.
//



#include <stdio.h>
#include <stdlib.h>
#include "SingleNode.h"
#include "SingleList.h"

int main(int argc, const char * argv[]) {

	IntList *theList = CreateList();
	IntList *MinList = CreateList();
	for (int i = 1; i < argc; i++)
	{
		IntNode *theNode = CreateNode(strlen(argv[i]), argv[i]);
		AddNode(theList, theNode);
		
	}
	printf("The list\n");
	doPrintList(theList);
	TheMinAndTheMax(theList);
	system("pause");
}