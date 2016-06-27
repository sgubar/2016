#include <stdio.h>
#include <stdlib.h>

#include "CreateNode.h"

Node *CreateNode(int value)
{
	Node *tmp = (Node *)malloc(sizeof(Node)); //videlenie pamyati dlya structury spiska
	tmp->number = value;
	tmp->next = NULL;
	return tmp;
}
