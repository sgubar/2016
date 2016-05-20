#include <stdlib.h>
#include <stdio.h>
#include "Node.h"
#include "List.h"

int main()
{
	Node *head = initializeList();
	int answer;
	int number;
	do {
		printf("1) Add back to list\n");
		printf("2) Change min and max elements\n");
		printf("3) Remove element with specified value\n");
		printf("4) Sort\n");
		printf("5) Print\n");
		printf("6) Print reverse\n");
		printf("7) Exit\n");
		printf("Answer: ");

		scanf("%i", &answer);

		switch (answer) {
		case 1:
			printf("Number: ");
			scanf("%d", &number);
			pushBackToList(head, number);
			printList(head);
			break;
		case 2:
			changeMinMax(head);
			printList(head);
			break;
		case 3:
			printf("Value: ");
			scanf("%d", &number);
			removeFromList(head, number);
			printList(head);
			break;
		case 4:
			sort(head);
			printList(head);
			break;
		case 5:
			printList(head);
			break;
		case 6:
			printListReverse(head);
			break;
		}
	} while (answer != 7);

	return 0;
}
