#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "node.h"
#include "list.h"

int main()
{
	Node *head = initializeList();
	int namber, i=0;
	printf("add ten integer namber to list \n");
	do //cycle 10 for input values
	{
		scanf("%i", &namber);
		pushBackToList(head, namber);
	}while(i != 9);
	printList(head); //function output list on screen
	sort(head); //function sorting
	printList(head);
	return 0;
}
