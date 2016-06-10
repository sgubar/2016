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
		if (firstItem->data == key)
		{
			thelist->head = firstItem->next;
			node *newhead = firstItem->next;
			newhead->previous = NULL;

			free(firstItem);
			firstItem = NULL; //after this we can't use this node
			thelist->count -= 1;

			return thelist;
		}

		if (lastItem->data == key)
		{
			thelist->tail = lastItem->previous;
			node *newtail = lastItem->previous;
			newtail->next = NULL;

			free(lastItem);
			lastItem = NULL;
			thelist->count -= 1;

			return thelist;
		}

		if (item->data == key)
		{
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