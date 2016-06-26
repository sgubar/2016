#include <stdio.h>
#include <stdlib.h>

#include "createList.h"

List* add(List** list, Node* node)		//sozdaem spisok
{
	if (*list) {
		node->next = (*list);
		node->prev = (*list)->prev;

		(*list)->prev->next = node;
		(*list)->prev = node;
	}
	else {
		node->next = node->prev = node;
		(*list) = node;
	}
	return (*list);
}

List* push(List* list, int value)
{
	Node* node = malloc(sizeof(Node));	//vidilyaem pamyat' pod structuru spiska
	node->value = value;

	return add(list, node);
}
