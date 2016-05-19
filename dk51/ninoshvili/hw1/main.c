//
//
//
//
//
//
//

#define _CRT_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "Insert.h"


void print(node *item);

int main()
{
	int position = 1;
	int data = 0;
	int index = 0;
	node *item;

	node *head = NULL; //empty list

	if (position == 1)
	{
		head = Insert(data, position, head);
		position++;
		data++;
	}
	for (position = 2; position < 6; position++)
	{
		item = Insert(data, position, head);
		
		data++;
	}
	for (item = head; item != NULL; item = item->next)
		print(item);
	
	item = Insert(24, 3, head);

	del(2, head);
	
	for (item = head; item != NULL; item = item->next)
		print(item);

	system("pause");
}

void print(node *item)
{
	printf("%d", item->data);
	item = item->next;
	printf("\n");
}