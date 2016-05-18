//
//  Sorting.c
//
//
//  Created by Bogdan Maximovich on 15/05/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "List.h"
#include "DoubleList.h"
#include "Sorting.h"

IntList *SortingNode(IntList *theList)
{
	for (int i = 0; i < CountList(theList)-1; i++) {

		for (int j = 0; j < CountList(theList)-1-i; j++)
		{
            IntNode *Node1 = IndexNode(theList,j);
            IntNode *Node2 = IndexNode(theList, j+1);
			if (Node1->value>Node2->value)
			{
				IntNode *TempNode1 = CreateNode(Node1->value);
				IntNode *TempNode2 = CreateNode(Node2->value);
                RemovedNodeAtIndex(theList,j);
				InsertNodeAtIndex(theList, TempNode2,j);
				RemovedNodeAtIndex(theList,j+1);
				InsertNodeAtIndex(theList, TempNode1,j+1);
			}
		}
	}
	printf("\n");
	printf("Edited list\n\n");
	return theList;
}
