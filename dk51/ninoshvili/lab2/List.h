#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include "node.h"

typedef struct {
    struct node *head;
    struct node *tail;
	int count;
}list;

#endif
