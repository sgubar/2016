#include <stdio.h>
#include <stdlib.h>
#include "CreateNode.h"

 Node *CreateNode(int value){
	Node *tmp=(Node *) malloc(sizeof(Node));
	tmp->number = value;
	tmp->next=NULL;
	return tmp;
};
