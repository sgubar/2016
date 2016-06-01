#include <stdio.h>
#include <stdlib.h>
#include "CreateNode.h"
#include "PrintRandomList.h"

Node *PrintRandomList(){
	Node *head,*tail;
	srand(time(NULL));
	Node *tmp;
	Node *read;
	int value=0+rand()%(0 - 10);
	int i=1;
	while(i<11){
		value=rand()%10+1;
		tmp=CreateNode(value);
		if (i==1){
		head=tmp;
		tail=head;
		}
		tail->next=tmp;
		tail=tmp;
		i++;
	};
	read=head;
	for(i=1; i<11;i++){
		printf("\nnode [%d]: %d ", i,read->number);
		read=read->next;
			}	
	
	return head;
}
