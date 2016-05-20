#include <stdlib.h>
#include <stdio.h>
#include "Node.h"
#include "List.h"

int main()
{
	Node *head = initializeList();
	int answer;
	int number;
	int index;

	do {
		printf("1) Add to end\n");
		printf("2) Add to begin\n");
		printf("3) Remove from end\n");
		printf("4) Remove from begin\n");
		printf("5) Remove at index\n");
		printf("6) Get element at index\n");
		printf("7) Change min and max elements\n");
		printf("8) Remove element with specified value\n");
		printf("9) Set value at index\n");
		printf("10) Create array\n");
		printf("11) Sort\n");
		printf("12) Print\n");
		printf("13) Print reverse\n");
		printf("14) Exit\n");
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
			printf("Number: ");
			scanf("%d", &number);
			pushFrontToList(head, number);
			printList(head);
			break;
		case 3:
			popBackFromList(head);
			printList(head);
			break;;
		case 4:
			popFrontFromList(head);
			printList(head);
			break;
		case 5:
			printf("Index: ");
			scanf("%d", &number);
			removeAt(head, number);
			printList(head);
			break;
		case 6:
			printf("Index: ");
			scanf("%d", &number);
			printf("Element %i", atIndex(head, number));
			printList(head);
			break;
		case 7:
			changeMinMax(head);
			printList(head);
			break;
		case 8:
			printf("Value: ");
			scanf("%d", &number);
			removeFromList(head, number);
			printList(head);
			break;
		case 9:
			printf("Index: ");
			scanf("%d", &index);
			printf("Value: ");
			scanf("%d", &number);
			setAtIndex(head, index, number);
			printList(head);
			break;
		case 10:
			printf("Size: ");
			scanf("%d", &number);
			head = initializeArray(number);
			printList(head);
			break;
		case 11:
			sort(head);
			printList(head);
			break;
		case 12:
			printList(head);
			break;
		case 13:
			printListReverse(head);
			break;
		}
	} while (answer != 14);

	return 0;
}
