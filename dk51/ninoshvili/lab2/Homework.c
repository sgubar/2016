#include <stdio.h>
#include "List.h"
#include "node.h"

list *Homework(list *thelist)
{
	node *head = thelist->head;
	node *tail = thelist->tail;
	node *insertionItem = head->next;
	node *compareItem = head;
	node *beforeCompare = (compareItem->previous == NULL) ? head : compareItem->previous;
	node *saveAdress = insertionItem->next;
	node *EndSorted = insertionItem->previous;

	while (compareItem != tail) 
	{
		saveAdress = insertionItem->next;

		while (compareItem != NULL)
		{
			if (compareItem->data > insertionItem->data && beforeCompare->data < insertionItem->data)
			{
				
				if (insertionItem == tail)
				{
					thelist->tail = compareItem;

					compareItem->next = NULL;
					compareItem->previous = insertionItem;

					insertionItem->next = compareItem;
					insertionItem->previous = beforeCompare;

					beforeCompare->next = insertionItem;

					return thelist;
				}

				if (beforeCompare != NULL)
					beforeCompare->next = insertionItem;
				else thelist->head = insertionItem;

				insertionItem->previous = beforeCompare;
				node *afterInsertionItem = insertionItem->next;
				insertionItem->next = compareItem;
				compareItem->previous = insertionItem;

				if (compareItem != EndSorted)
				{
					EndSorted->next = afterInsertionItem;
					afterInsertionItem->previous = EndSorted;
				}
				else 
				{
					compareItem->next = afterInsertionItem;
					afterInsertionItem->previous = compareItem;
				}
				break;
			}

			compareItem = beforeCompare;
			beforeCompare = (compareItem == NULL)? head : compareItem->previous;
		}

		insertionItem = saveAdress;
		EndSorted = (insertionItem == NULL)? tail : insertionItem->previous;
		compareItem = (insertionItem == NULL)? tail: insertionItem->previous;
		beforeCompare = (compareItem == NULL) ? head : compareItem->previous;
	}
	

	return thelist;
}