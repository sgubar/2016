#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "insert.h"
#include "delete.h"
#include "sort.h"
#include "changeMaxMin.h"
#include "takeNode.h"
#include "List.h"
#include "node.h"
#include "createList.h"
#include "createNode.h"
#include "task.h"

void print(list *thelist);

int main()
{
	int value;
	int index = 0;

	//empty list
	list *thelist = createList();
	node *item = NULL;

	printf("please input only positive values for 10 items\n");
	for (index = 0; index < 10; index++)
	{
		do
		{
			printf("%d value is:", (index + 1));
			scanf("%d", &value);
			
			if (value > 0)
			{
				item = createNode(value);
				insert(item, thelist);
			}

			if (value < 1) 
				printf("try again and input only positive value\n");

		} while (value < 1);
	}
	printf("count now is:%d\n", thelist->count);
	print(thelist);

	printf("choose the value which want to delete from the list:");
	int key;
	scanf("%d", &key);

	del(thelist, key);
	printf("count now is:%d\n", thelist->count);
	print(thelist);

	printf("changing max and min\n");
	changeMaxMin(thelist);
	print(thelist);

	do
	{
		printf("choose the node of the list which you want to take:");
		scanf("%d", &key);

		if (key > thelist->count || key <1)
			printf("but not lower than 1 and bigger than count of nodes at the list\n");

	} while (key > thelist->count || key < 1);

	node *takenNode = take(thelist, key);
	printf("count now is:%d\n", thelist->count);
	print(thelist);

	printf("sorting...\n");
	sort(thelist);
	print(thelist);

	//TODO task
	printf("list after making task:\n");
	task(thelist);
	print(thelist);

	system("pause");
}

void print(list *thelist)
{
	node *item = thelist->head;

	printf("list: ");
	for (; item != NULL; item = item->next)
		printf("%d ", item->data);

	printf("\n");
}