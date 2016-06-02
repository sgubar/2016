#include <stdio.h>
#include "node.h"

node *Mission(node *head)
{
	node *temporaryhead = head->next; //setup the second element as a first
	node *previousItem = head->next;
	node *firstItem = previousItem->next;
	node *secondItem = firstItem->next;
	node *last = secondItem->next;

	for (last; last->next != NULL; last = last->next) //setup the second last element as a last
		;

	int index, j;

	for (index = 0; index < 10; index++)
	{
		node *previousItem = temporaryhead;
		node *firstItem = previousItem->next;
		node *secondItem = firstItem->next;
	
		//just like bubble sort, but conversely: the element with the lowest data will be the last 
		for (j = 0; j<10; j++)
		{
			if (previousItem == temporaryhead && previousItem->data < firstItem->data)
			{
				head->next = temporaryhead->next;
				previousItem->next = secondItem;
				firstItem->next = previousItem;
				temporaryhead = head->next;
				firstItem = firstItem->next;
				previousItem = head->next;
			}


			if (secondItem == last)
				break;

			if (firstItem->data < secondItem->data)
			{
				firstItem->next = secondItem->next;
				previousItem->next = secondItem;
				secondItem->next = firstItem;
				firstItem = previousItem->next;
				secondItem = firstItem->next;
			}

			previousItem = previousItem->next;
			firstItem = firstItem->next;
			secondItem = secondItem->next;
		}
	}
	return head;
}