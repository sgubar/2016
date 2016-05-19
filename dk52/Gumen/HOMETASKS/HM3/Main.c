//
//  CreateSLList.c
//  Created by Dima Humeniuk on 05/06/16.
//  Copyright © 2016 Dima Humeniuk. All rights reserved.
//

#include "CreateList.h"
#include <stdio.h>



void doSingleLinkedList();
void doCircularLinkedList();



int main()
{
	doSingleLinkedList();
	return 0;
}

void doSingleLinkedList()
{
	IntNode *theNode1 = CreateNode(1);
	IntNode *theNode10 = CreateNode(10);
	IntNode *theNode2 = CreateNode(2);
	IntNode *theNode9 = CreateNode(9);
	IntNode *theNode3 = CreateNode(3);
	IntNode *theNode8 = CreateNode(8);
	IntNode *theNode0 = CreateNode(0);
	IntNode *theNode100 = CreateNode(100);

	IntList *theList = CreateSLList();

	AddNode(theList, theNode10);
	AddNode(theList, theNode1);
	AddNode(theList, theNode100);
	AddNode(theList, theNode9);
	AddNode(theList, theNode2);
	AddNode(theList, theNode3);
	AddNode(theList, theNode0);
	AddNode(theList, theNode8);

	PrintList(theList);
	//task 1 done

	doSelectionSort(theList);
	//HOMETASK 3 DONE

	printf("\n\n");
	return;
}