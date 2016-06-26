#include <stdio.h>
#include <stdlib.h>

#include "createList.h"
#include "writeList.h"

void write(const List* list) {			//vivodim spisok na ekran
	const Node* node = list;

	if (node) {
		while (node->next != list) {
			printf("%d ", node->value);
			node = node->next;
		}
		printf("%d\n", node->value);
	}
}
