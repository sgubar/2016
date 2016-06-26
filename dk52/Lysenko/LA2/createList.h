#ifndef createList_h
#define createList_h

#include <stdio.h>


typedef struct Node_t {
	int value;
	struct Node_t* next;
	struct Node_t* prev;
}   Node;

typedef Node List;

List* add(List** list, Node* node);
List* push(List** list, int value);
#endif
