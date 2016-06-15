/* delete.c  (for doubly linked list)						*
 * finding node by value and deleting    					*
 *															*
 *															*
 * Created by Sergiy Ninoshvili on 15/06/2016 		        *
 *													        *
 * Copyright © 2016 Sergiy Ninoshvili. All rights reserved. *
 *													        */
#include <stdio.h>
#include "List.h"
#include "node.h"

list *del(list *thelist, int key)
{
	node *firstItem = thelist->head;
	node *lastItem = thelist->tail;

	//and variable item
	node *item = thelist->head; 

	for (; item->next != NULL; item = item->next)
	{
		if (firstItem->data == key) //deleting head 
		{
			thelist->head = firstItem->next;
			node *newhead = firstItem->next;
			newhead->previous = NULL;

			free(firstItem);
			firstItem = NULL; //after this we can't use this node
			thelist->count -= 1;

			return thelist;
		}

		if (lastItem->data == key) //deleting tail
		{
			thelist->tail = lastItem->previous;
			node *newtail = lastItem->previous;
			newtail->next = NULL;

			free(lastItem);
			lastItem = NULL;
			thelist->count -= 1;

			return thelist;
		}

		if (item->data == key) //deleting somewhere in the middle 
		{
			//adress around of deleting node
			node *itemPrevious = item->previous;
			node *itemNext = item->next;

			itemPrevious->next = itemNext;
			itemNext->previous = itemPrevious;

			free(item);
			item = NULL;
			thelist->count -= 1;

			return thelist;
		}
	}

	printf("can't find this value\n");

	return thelist;
}