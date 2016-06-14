#include <stdio.h>
#include "List.h"
#include "node.h"

list *changeMaxMin(list *thelist) //BUG max opposite min
{
	node *item = thelist->head;
	node *nextItem = item->next;
	node *min = item;
	node *max = item;

	for (; item->next != NULL; nextItem = nextItem->next)
	{
		if (min->data > nextItem->data)
			min = nextItem;

		if (max->data < nextItem->data)
			max = nextItem;

		item = item->next;
	}
	printf("max:%d, min:%d\n", max->data, min->data);

	/*creating pointers to around nodes*/
	node *beforemax = max->previous;
	node *beforemin = min->previous;
	node *aftermax = max->next;
	node *aftermin = min->next;

	if (max->next == min)
	{
		if (beforemax != NULL)
			beforemax->next = min;
		else thelist->head = min;

		min->previous = beforemax;

		min->next = max;
		max->previous = min;

		max->next = aftermin;

		if (aftermin != NULL)
			aftermin->previous = max;
		else thelist->tail = max;

		return thelist;
	}
	if (min->next == max)
	{
		if (beforemin != NULL)
			beforemin->next = max;
		else thelist->head = max;

		max->previous = beforemin;

		max->next = min;
		min->previous = max;

		min->next = aftermax;

		if (aftermax != NULL)
			aftermax->previous = min;
		else thelist->tail = min;

		return thelist;
	}

		if (beforemax != NULL && beforemax != min) //max is not a head of the list
			beforemax->next = min;
		else thelist->head = min;

		if(aftermax != NULL && aftermax != min) //max is not a tali of the list
		    aftermax->previous = min; 
		else thelist->tail = min;

		if (beforemin != NULL && beforemin != max) //min is not a head of the list
			beforemin->next = max;
		else thelist->head = max;

		if(aftermin != NULL && aftermin != max) //min is not a tail of the list
			aftermin->previous = max;
		else thelist->tail = max;
		
		min->next = aftermax;
		min->previous = beforemax;
	
		max->next = aftermin;
		max->previous = beforemin;

	return thelist;
}