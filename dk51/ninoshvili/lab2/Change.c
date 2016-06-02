#include <stdio.h>
#include "node.h"
#include "Change.h"

node *Change(node *head)
{
	node *firstItem = head;
	node *previousItem = firstItem;
	node *secondItem = firstItem->next;

	for (secondItem; secondItem->next != NULL; secondItem = secondItem->next) //go to the last and second last 
		previousItem = previousItem->next;

	//printf("%d, %d, %d\n", firstItem->data, secondItem->data, previousItem->data);

	secondItem->next = head->next; //last has adress of the second element
	head = secondItem; //last element become the first
	firstItem->next = NULL; //early first item now has adress of the NULL
	previousItem->next = firstItem; //second last has adress of the early first element


	return head;
}