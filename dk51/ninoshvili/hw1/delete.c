#include<stdio.h>
#include"delete.h"
#include "node.h"

void del(int position, node* head)
{
	int index = 0;
	node *item1 = head; //pointer to the first element of the list

	if (position == 1)
	{
		head = item1->next; //head has adress of the second element 
		free(item1); //delete first element
		item1 = NULL;
		return;
	}

	for (index = 0; index < (position - 2); index++)
		item1 = item1->next;  //we can write this just like: adress n-th element = pointer to the (n-th + 1) element
	
	node *item2 = item1->next; //create a pointer to delete node
	item1->next = item2->next; // take the adress from delete node
	free(item2); //delete the pointed node
	item2 = NULL;
	return;
}