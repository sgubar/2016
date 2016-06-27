/* task.c												     *
 * between head and tail of the list positioned node in the	 *
 * reverse order										     *
 *															 *
 * Created by Sergiy Ninoshvili on 15/06/2016 		         *
 *													         *
 * Copyright © 2016 Sergiy Ninoshvili. All rights reserved.  *
 *													         */
#include <stdio.h>
#include "List.h"
#include "node.h"

list *task(list *thelist)
{
	node *head = thelist->head;
	node *tail = thelist->tail;

	head->next = tail->previous; //previous to tail node would be the second of the list

	node *item = tail->previous;
	node *previousTOnext = item->previous;
	node *saveAdress = previousTOnext->previous;

	head->next = item;
	item->previous = head;

	while(previousTOnext != head)
	{
		// head										               tail
		// 1       2          4               5               6    7 -imagine that this is the list
		//		    saveAdress^ previousTOnext^           item^
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