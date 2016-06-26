#include <stdio.h>
#include <stdlib.h>

#include "createList.h"
#include "reverseList.h"

Node* findFirst(List* list, int value) {			//nahodim perviy element
	Node* node = list;
	for (; (node->next != list) && (node->value != value); node = node->next) { ; }

	return (node->value == value) ? node : NULL;
}

Node* findLast(List* list, int value) {				//nahodim posledniy element
	Node* node = list;
	for (; (node->prev != list) && (node->value != value); node = node->prev) { ; }

	return (node->value == value) ? node : NULL;
}

List* reverseBetween(List* list, int value) {		//menyaem mestami elementi mezhdu pervimi i posslednimi
	Node* first = findFirst(list, value);
	Node* last = findLast(list, value);
	Node* node, *tail, *tmp;

	if (first && (first != last) && (first->next != last) && (last->prev != first)) {
		tail = last->prev;
		tmp = first->next;
		while (tmp != tail) {
			node = tmp;
			tmp = tmp->next;
			last = add(&last, node)->prev;
		}
		tail->prev = first;
		first->next = tail;
	}

	return list;
}
