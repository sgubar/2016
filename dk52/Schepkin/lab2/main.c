#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "stdafx.h"

typedef struct node_s node;
struct node_s {
	int value;
	node *next;
};

int main () {
	printf("Enter count of elements: ");
	int count;
	scanf("%d", &count);

	if(count < 0)
		count = -count;

	node *first = (node *)malloc(sizeof(node));
	node* step = first;

	for(int i = 0; i < count; i++) {
		printf("Enter element %d: ", i+1);
		scanf("%d", &(step->value));
		if (i == count - 1)
			step->next = first;
		else
			step->next = (node *)malloc(sizeof(node));
		step = step->next;
	}

	printf("\n All elements is entered.\n");
	step = first;
	node *min_node = first;

	int min = step->value;

	for(int i = 0; i < count; i++) {
		if( step->value < min ){
			min = step->value;
			min_node = step;
		}
		step = step->next;
	}

	printf("Minimum is: %d\n", min);

	for(int i = 0; i < count + 5; i++) {
		printf("%d -> ", min_node->value);
		min_node = min_node->next;
	}

	printf(" that's all\n");

	_getch();

}
