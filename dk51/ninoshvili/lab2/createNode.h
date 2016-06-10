#ifndef CREATENODE_H
#define CREATENODE_H

#include <stdio.h>
#include <stdlib.h>
#include "node.h"


node *createNode(int value)
{
	node *item = (node *)malloc(sizeof(node));

	item->data = value;
	item->next = item->previous = NULL; 

	return item;
}

#endif