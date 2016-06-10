#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "List.h"

node *insert(node *item, list *thelist)
{
	if (thelist->head == NULL && thelist->tail == NULL) //empty list
	{
		thelist->head = thelist->tail = item;
		thelist->count += 1;
		
		return thelist;
	}

	if (thelist->head != NULL && thelist->tail != NULL)
	{
		//previous node has adress of new node
		node *itemprevious = thelist->tail; 
		itemprevious->next = item;

		//new node has adress of the previous 
		item->previous = thelist->tail;
		item->next = NULL;
		thelist->count += 1;
		thelist->tail = item;

		return thelist;
	}
}