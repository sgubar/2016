#include <stdio.h>
#include <stdlib.h>
#include "Insert.h"
#include "node.h"

int Insert(int data, int position, node *head)
{
	int index;

	node *item1 = (node*)malloc(sizeof(node)); //create a node
	item1->data = data;
	item1->next = NULL; //after creating has adress to nowhere

	if (position == 1)
	{
		item1->next = NULL; //now item1 has adress NULL - end of the list
		head = item1; //now head has adress of first element
		return head;
	}
	
	else
	{
		node *item2 = head; //create a pointer to struct and put the adress of the first element

		for (index = 0; index < (position - 2); index++)
		{
			item2 = item2->next; //we can write this just like: adress n-th element = pointer to the (n-th + 1) element
		}

		item1->next = item2->next; //now two elements are pointers to the next node (position+1)
		item2->next = item1; //pointer of node n-th - 1 now has adress of our new node

		return item2;
	}
	}