#include <stdio.h>
#include "node.h"
#include "Find.h"
#include "delete.h"

node *Find(node *head, int key)
{
	node *firstItem = head;
	node *previousItem = firstItem;
	node *secondItem = firstItem->next;
	int position = 1;

	if (head->data == key)
	{
		printf("delete complete\n");
		del(1, head);
		head = secondItem; //after deleting first element the second will be the first
	}

	for (secondItem; secondItem->next != NULL; secondItem = secondItem->next)
	{
		position++;
		if (secondItem->data == key)
		{
			printf("delete complete\n");
			del(position, head);
			break;
		}

		if (secondItem->next == NULL && secondItem->data != key) //if didn't find the element
		{
			printf("\ndidn't find this data\n");
			break;
		}
	}	
	return head;
}