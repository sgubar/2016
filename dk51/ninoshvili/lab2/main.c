//main.c
//
//linked list
//
//
//created by Sergey Ninoshvili 02/06/2016
//Copyright © 2016 Ninoshvili. All rights reserved

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "Insert.h"
#include "Change.h"
#include "Mission.h"


void print(node *item); //create a function to comfortable output of the list

int main()
{
	int position = 1;
	int data;
	int index = 0;
	int key;
	node *item;

	node *head = NULL; //empty list

	printf("please input only positive integer of data\n");

	do 
	{
		printf("data to %d position\n", position);
		scanf("%d", &data);
	} while (data <= 0);

	if (position == 1)
	{
		head = Insert(data, position, head);
		position++;
	}

	
	for (index = 2; index < 11; index++)
	{
			do
			{
				printf("data to %d position\n", position);
				scanf("%d", &data);
			} while (data <= 0);

			
			item = Insert(data, position, head);
			position++;
	}
	
	printf("so your list now:");
	print(head);

		head = Sort(head);

	printf("\nsorted list\n");
	print(head);

		head = Change(head);

	printf("\nchanged the lowest and the highest elements\n");
	print(head);

	printf("\nenter the data, which you wanna find and delete from the list\n");
	scanf("%d", &key);

		head = Find(head, key);
	printf("\nlist:");
	print(head);

	printf("\nsorted again:");
		head = Sort(head);
	print(head);

		head = Mission(head);
	printf("\ntask:\n");

	print(head);

	printf("\n");


	system("pause");
}

void print(node *item)
{
	//item = head
	for (; item != NULL; item = item->next)
		printf("%d ", item->data);
}