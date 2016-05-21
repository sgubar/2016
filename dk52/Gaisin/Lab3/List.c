#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "Node.h"

// Initialize list
Node* initializeList()
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	node->value = 0;

	return node;
}

// Get number of elements in list
int count(Node* head)
{
	int count = 0;
	for (Node* current = head; current->next != NULL; current = current->next)
		count++;

	return count;
}

// Add element to end
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

// Remove element with specified value from list
void removeFromList(Node *head, int value)
{
	Node *current = head;
	while (current->next != NULL)
		if (current->next->value == value)
		{
			Node* node = current->next;
			current->next = node->next;
			free(node);
		}
		else
			current = current->next;
}

// Remove element with specified index
void removeAt(Node* head, int index)
{
	Node *current = head;
	int currentIndex = 0;
	while (current->next != NULL)
	{
		if (currentIndex == index)
		{
			Node* node = current->next;
			current->next = node->next;
			free(node);

			return;
		}
		current = current->next;
		currentIndex++;
	}

	printf("Invalid index");
}

// Print list
void printList(Node *head)
{
	if (head->next == NULL)
	{
		printf("List is empty\n");
		return;
	}

	printf("\nList: ");
	for (Node* current = head->next; current != NULL; current = current->next)
		printf("%i ", current->value);
	printf("\n\n");
}

// Get element with specified index
int atIndex(Node *head, int index)
{
	Node *current = head;
	int currentIndex = 0;
	while (current->next != NULL)
	{
		if (currentIndex == index)
			return current->next->value;
		current = current->next;
		currentIndex++;
	}
}

// Print reverse list
void printListReverse(Node *head) {
	printf("\nReverse list: ");
	for (int i = count(head) - 1; i >= 0; i--)
		printf("%i ", atIndex(head, i));
	printf("\n\n");
}

// Swap min and max elements
void changeMinMax(Node *head)
{
	int min = INT_MAX,
		max = INT_MIN;

	Node *maxPrev = NULL,
		*minPrev = NULL;

	Node *current = head;
	while (current->next != NULL)
	{
		int nextValue = current->next->value;
		if (nextValue > max)
		{
			maxPrev = current;
			max = nextValue;
		}
		if (nextValue < min)
		{
			minPrev = current;
			min = nextValue;
		}
		current = current->next;
	}

	Node* minElement = minPrev->next;
	Node* maxElement = maxPrev->next;
	Node* temp = maxElement->next;

	if (maxElement == minPrev)
	{
		maxPrev->next = minElement;
		maxElement->next = minElement->next;
		minElement->next = maxElement;
	}
	else {
		if (minElement == maxPrev)
		{
			minPrev->next = maxElement;
			minElement->next = maxElement->next;
			maxElement->next = minElement;
		}
		else
		{
			maxElement->next = minElement->next;
			minElement->next = temp;
			maxPrev->next = minElement;
			minPrev->next = maxElement;
		}
	}

}

// Get last element pointer
Node* last(Node *head)
{
	Node *last = head;
	while (last->next != NULL)
		last = last->next;

	return last;
}

// Bubble sort
void sort(Node* head)
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
