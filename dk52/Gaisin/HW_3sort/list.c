#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "node.h"

Node* initializeList()
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	node->value = NULL;

	return node;
}

void pushBackToList(Node *head, int value)
{
		Node *node = (Node*)malloc(sizeof(Node));
		node->value = value;
		node->next = NULL;

		Node *last = head;
		while (last->next != NULL)
			last = last->next;

		last->next = node;
}

void printList(Node *head)
{
	if (head->next == NULL) //if in list no elements
	{
		printf("List is empty\n");
		return;
	}

	printf("\nList: ");
	//cycle will be executed until the current element does not indicate NULL
	for (Node* current = head->next; current != NULL; current = current->next)
		printf("%i ", current->value);
	printf("\n\n");
}

Node* last(Node *head)
{
	Node *last = head;
	while (last->next != NULL) //find last element
		last = last->next;

	return last;
}

void sort(Node* head) //bubble sort
{
	Node *lastNotSorted = last(head)->next;
	while (lastNotSorted != head->next)
	{
		Node *current = head->next;
		while (current->next != lastNotSorted)
		{
			if (current->value > current->next->value) {
				int temp = current->value;
				current->value = current->next->value;
				current->next->value = temp;
			}
			else
				current = current->next;
		}
		lastNotSorted = current;
	}
}
