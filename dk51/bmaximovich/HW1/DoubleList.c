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

void *CreateDoubleList(IntList *aList, int i)
{
	int findNode = ValueNode(aList, i);
	if(findNode >= 0){
        IntNode *R = IndexNode(aList, findNode);
        IntNode *T = CreateNode(R->value);
        InsertNodeAtIndex(aList, T, findNode);
	} else {
	    printf("\n");
        printf("Not found this node\n");
        printf("\n");
	}
}
