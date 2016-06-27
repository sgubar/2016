#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "add.h"
#include "createNode.h"
#include "printList.h"
#include "Delete.h"

int main() {
	int value, n, m;
	Node *head, *removed, *newhead;

	printf("You have the list of random 10 numbers:\n");
	head = PrintList();										//sozdaem spisok iz 10 sluhainyh cifr


	printf("\n\nWhat is index of a new node?\n");
	scanf_s("%d", &n);
	if (n<1 || n>11) 
	{                                                      //korektnost' vvoda
		printf("\nYou pick the wrong index!\n");
		system("pause");
		exit(0);
	}


	printf("\nWhat value would you like to insert?\n");
	scanf_s("%d", &value);
	newhead = addNode(head, n, value);          //dobavlenie nodi


	printf("\n\nWhat is the index of node you would like to remove?\n");
	scanf_s("%d", &m);
	if (m<1 || m>12) {                                                      //korektnost' vvoda
		printf("You pick the wrong index!\n");
		system("pause");
		exit(0);
	}
	removed = DeleteNode(newhead, m);                                        //udalyaem nodu
	printf("\n\nYou removed %d\n", removed->number);

	system("pause");

	return 0;
};
