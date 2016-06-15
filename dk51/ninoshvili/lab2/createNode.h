/* createNode.h												*
 * 															*
 *						 									*
 *															*
 * Created by Sergiy Ninoshvili on 15/06/2016 		        *
 *													        *
 * Copyright © 2016 Sergiy Ninoshvili. All rights reserved. *
 *													        */
#ifndef CREATENODE_H
#define CREATENODE_H

#include <stdio.h>
#include <stdlib.h>
#include "node.h"


node *createNode(int value)
{
	node *item = (node *)malloc(sizeof(node)); //allocate memory for node struct

	item->data = value;
	item->next = item->previous = NULL; //create lonely node

	return item;
}

#endif