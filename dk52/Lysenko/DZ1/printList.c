#include <stdio.h>
#include <stdlib.h>
#include "CreateNode.h"
#include "PrintList.h"

Node *PrintList() 
{
	Node *head = (Node *)malloc(sizeof(Node));
	Node *tail = (Node *)malloc(sizeof(Node));
	srand(time(NULL));
	Node *tmp;
	Node *read;
	int value = 0 + rand() % (0 - 10);
	int i = 1;
	while (i<11) {
		value = rand() % 10 + 1;
		tmp = CreateNode(value);
		if (i == 1) {
			head = tmp;
			tail = head;
		}
		tail->next = tmp;
		tail = tmp;
		i++;
	};
	read = head;
	for (i = 1; i<11; i++) {
		printf("[%d]:%d ", i, read->number);
		read = read->next;
	}

	return head;
}
