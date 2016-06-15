/* sort.c												    *
 * bubble sorting doubly list						     	*
 *															*
 *															*
 * Created by Sergiy Ninoshvili on 15/06/2016 		        *
 *													        *
 * Copyright © 2016 Sergiy Ninoshvili. All rights reserved. *
 *													        */
#include <stdio.h>
#include "List.h"
#include "node.h"

list *sort(list *thelist)
{
	int index = 1;
	int j = 1;
	node *item = thelist->head;
	node *nextItem = item->next;
	node *beforeitem = item->previous;
	node *afterNextItem = nextItem->next;

	for (index = 1; index < thelist->count; index++)
	{
		item = thelist->head;
		nextItem = item->next;

		for (j = 1; j < thelist->count; j++)
		{
			if (item->data > nextItem->data)
			{
				//adress of around nodes
				beforeitem = item->previous;
				afterNextItem = nextItem->next;

				if(beforeitem != NULL)
					beforeitem->next = nextItem;

				nextItem->previous = beforeitem;
				nextItem->next = item;
				item->previous = nextItem;
				item->next = afterNextItem;

				if(afterNextItem != NULL)
					afterNextItem->previous = item;

				if (item == thelist->head)
					thelist->head = nextItem;

				if (nextItem == thelist->tail)
					thelist->tail= item;

				//after changing nextItem located before item, so swap it
				item = item->previous;
				nextItem = item->next;
			}

			item = nextItem;
			nextItem = nextItem->next;
		}
	}
	return thelist;
}