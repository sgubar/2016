//
//  main.c
//  Lab2
//
//  Created by Sorokin Dmytro on 4/7/16.
//  Copyright (C) 2016 Sorokin Dmytro. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include "Function.h"
#include "FunctionList.h"

int main(int argc, const char * argv[]) {
	
	if (1 == argc) {
		printf("Error, incorrect input data");
		return 0;
	}

	IntList *theList = CreateList();
	IntList *aList;
	IntList *MinList = CreateList();
	int IndexMaximum;
	int IndexMinimum;
	int count;

	for (int i = 1; i < argc; i++) {
		IntNode *theNode = CreateN(atoi(argv[i]));
		AddNode(theList, theNode);
		printf("Node value: %d\n", theNode->value);
		}

		printf("Simple List\n");
		doPrintList(theList);
	
		IndexMaximum=doFindIndexMax(theList);
		IndexMinimum=doFindIndexMin(theList);
		count = CountList(theList);
		selectionSort(theList,IndexMinimum,IndexMaximum);
		insertionSort(theList, count);


	system ("pause");
}

