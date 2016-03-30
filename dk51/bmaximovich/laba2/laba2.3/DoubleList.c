//
//  doublelist.c
// 
//
//  Created by Bogdan Maximovich on 23/03/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
//

#include "list.h"
#include "Node.h"
#include <stdlib.h>
#include "DoubleList.h"

IntList *ÑreateDoubleList(IntList *aList)
{
	IntList *theList = CreateList();
	IntNode *theNode = aList->head;

	while (theNode != NULL)
	{
		IntNode *theNode1 = CreateNode(theNode->value);
		IntNode *theNode2 = CreateNode(theNode->value);
		AddNode(theList, theNode1);
		AddNode(theList, theNode2);
		theNode = theNode->nextNode;

	}
	return theList;


}