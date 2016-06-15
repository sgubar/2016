/* insert.c	(for doubly linked list)	   					*
 * insertion node to the end of the list or if the list is	*
 * empty to the beggining 									*
 *															*
 * Created by Sergiy Ninoshvili on 15/06/2016 		        *
 *													        *
 * Copyright © 2016 Sergiy Ninoshvili. All rights reserved. *
 *													        */
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "List.h"

node *insert(node *item, list *thelist)
{
	if (thelist->head == NULL && thelist->tail == NULL) //empty list
	{
		thelist->head = thelist->tail = item; //single node
		thelist->count += 1;
		
		return thelist;
	}

	if (thelist->head != NULL && thelist->tail != NULL) //add to the end of the list
	{
		//previous node has adress of new node
		node *itemprevious = thelist->tail; 
		itemprevious->next = item;

		item->previous = thelist->tail;
		item->next = NULL;
		thelist->count += 1;
		thelist->tail = item; //now this item is a new tail

		return thelist;
	}
}