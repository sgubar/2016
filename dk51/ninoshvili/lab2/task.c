#include <stdio.h>
#include "List.h"
#include "node.h"

list *task(list *thelist)
{
	node *head = thelist->head;
	node *tail = thelist->tail;

	head->next = tail->previous;

	node *item = tail->previous;
	node *previousTOnext = item->previous;
	node *saveAdress = previousTOnext->previous;

	head->next = item;
	item->previous = head;

	while(previousTOnext != head)
	{
		item->previous = (head->next == item) ? head : item->next;
		item->next = previousTOnext;

		previousTOnext->previous = item;
		

		item = previousTOnext;
		previousTOnext = saveAdress;
		saveAdress = saveAdress->previous;
	}

	tail->previous = item;
	item->next = tail;

	return thelist;
}