#include <stdio.h>
#include <stdlib.h>
#include "CreateNode.h"

//Sozdaem nody

 Node *CreateNode(char value){
	Node *tmp=(Node *) malloc(sizeof(Node));
	tmp->symbol = value;
	tmp->next=NULL;
	return tmp;
};
