//
//  Sorting.c
//
//
//  Created by Bogdan Maximovich on 5/04/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "List.h"
#include "DoubleList.h"
#include "Sorting.h"

void SortingNode(IntNode *theNode, IntList *theList)
{

	    for (int theOut = theNode - 1; theOut > 1; theOut--)
	{
		for (int theIn = 0; theIn < theOut; theIn++)
		{
			if (theNode > theNode + 1)
			{
				int theTmp = theList;
				theList = theNode + 1;
				theList = theTmp;
			}
		}
	}
	return(theNode);
}
