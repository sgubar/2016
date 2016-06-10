#include <stdio.h>
#include "List.h"
#include "node.h"

list *take(list *thelist, int key)
{
	if (key < 1 || key > thelist->count)
		return -1;

	int index = 1;
	node *firstItem = thelist->head;
	node *lastItem = thelist->tail;

	//and variable item
	node *item = thelist->head;

	//taking by the number of node
	for (index = 1; index < key; index++)
		item = item->next;

		if (item == thelist->head)
		{
			thelist->head = firstItem->next;
			thelist->count -= 1;

			return item;
		}

		if (item == thelist->tail)
		{
			thelist->tail = lastItem->previous;
			node *newtail = lastItem->previous;
			newtail->next = NULL;
			thelist->count -= 1;

			return item;
		}

		if (item !=  thelist->head && item != thelist->tail)
		{
			node *itemPrevious = item->previous;
			node *itemNext = item->next;

			itemPrevious->next = itemNext;
			itemNext->previous = itemPrevious;
			thelist->count -= 1;

			return item;
		}
	
	printf("can't find this node\n");

	return thelist;
}