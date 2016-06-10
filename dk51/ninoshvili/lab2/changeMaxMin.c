#include <stdio.h>
#include "List.h"
#include "node.h"

list *changeMaxMin(list *thelist)
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

	if (beforemax == NULL && aftermin != NULL || beforemin == NULL && aftermax != NULL)/*one element is a head and second somewhere in the list*/
	{
		if (beforemax == NULL) /*max = head*/
		{
			/*max = min*/
			min->previous = NULL;
			aftermax->previous = min;
			min->next = aftermax;

			thelist->head = min;

			/*min = max*/
			beforemin->next = max;
			max->previous = beforemin;
			aftermin->previous = max;
			max->next = aftermin;
		}

		if (beforemin == NULL) /*min = head*/
		{
			/*min = max*/
			max->previous = NULL;
			aftermin->previous = max;
			max->next = aftermin;

			thelist->head = max;

			/*max = min*/
			beforemax->next = min;
			min->previous = beforemax;
			aftermax->previous = min;
			min->next = aftermax;
		}
		return thelist;
	}

	if (aftermax == NULL && beforemin != NULL || aftermin == NULL && beforemax != NULL) /*one element is tail and second somewhere in the list*/
	{
		if (aftermax == NULL)/*max = tail*/
		{
			/*max = min*/
			beforemax->next = min;
			min->previous = beforemax;
			min->next = NULL;

			thelist->tail = min;

			/*min = max*/
			beforemin->next = max;
			max->previous = beforemin;
			aftermin->previous = max;
			max->next = aftermin;
		}

		if (aftermin == NULL)/*min = tail*/
		{
			/*min = max*/
			beforemin->next = max;
			max->previous = beforemin;
			max->next = NULL;

			thelist->tail = max;

			/*max = min*/
			beforemax->next = min;
			min->previous = beforemax;
			aftermax->previous = min;
			min->next = aftermax;
		}
		return thelist;
	}

	if (aftermax == NULL && beforemin == NULL || aftermin == NULL && beforemax == NULL) /*when head = min or max, while tail = max or min*/
	{
		if (aftermax == NULL)
		{
			/*max = min*/
			beforemax->next = min;
			min->previous = beforemax;
			min->next = NULL;

			thelist->tail = min;

			/*min = max*/
			max->previous = NULL;
			aftermin->previous = max;
			max->next = aftermin;

			thelist->head = max;
		}

		if (aftermin == NULL)
		{
			/*max = min*/
			min->previous = NULL;
			aftermax->previous = min;
			min->next = aftermax;

			thelist->head = min;

			/*min = max*/
			beforemin->next = max;
			max->previous = beforemin;
			max->next = NULL;

			thelist->tail = max;
		}
		return thelist;
	}

	//BUG IF .....MAXMIN.....
	if (beforemax != NULL && beforemin != NULL && aftermax != NULL && aftermin != NULL) /*changing without taking head or tail of the list*/
	{
		if (max->next == min || min->next == max)
		{
			if (max->next == min)
			{
				beforemax->next = min;
				min->previous = beforemax;

				min->next = max;
				max->previous = min;

				max->next = aftermin;
				aftermin->previous = max;

				return thelist;
			}
			if (min->next == max)
			{
				beforemin->next = max;
				max->previous = beforemin;

				max->next = min;
				min->previous = max;

				min->next = aftermax;
				aftermax->previous = min;

				return thelist;
			}
		}
		/*max = min*/
		beforemax->next = min;
		min->previous = beforemax;
		aftermax->previous = min;
		min->next = aftermax;

		/*min = max*/
		beforemin->next = max;
		max->previous = beforemin;
		aftermin->previous = max;
		max->next = aftermin;

		return thelist;
	}

	return thelist;
}