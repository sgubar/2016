#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "ListAdd.h"


Node *createList(int k)
{
	Node *head = (Node *)malloc(sizeof(Node));
	head->next = NULL;
	head->value = k;
	return head;
}


void AddList(Node **head, Node **tail, int data)
{
	if (*head == NULL || *tail == NULL)
	{
		if (*head == NULL && *tail == NULL)
			*head = *tail = createList(data);
		else exit(-1);

	}

	else

	{

		Node *tmp = (Node *)malloc(sizeof(Node));

		tmp->value = data;
		tmp->next = NULL;

		(*tail)->next = tmp;
		(*tail) = tmp;

	}

}


