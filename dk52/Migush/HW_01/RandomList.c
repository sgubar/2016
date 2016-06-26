#include <stdio.h>
#include <stdlib.h>
#include "NewNode.h"
#include "RandomList.h"

Node *RandomList(){
	Node *first_elem,*end_elem;
	srand(time(NULL));
	Node *tmp;
	Node *read;
	int value=0+rand()%(0 - 100);
	int i=1;
	while(i<101){
		value=rand()%100+1;
		tmp=CreateNode(value);
		if (i==1){
		first_elem=tmp;
		end_elem=first_elem;
		}
		end_elem->next=tmp;
		end_elem=tmp;
		i++;
	};
	read=first_elem;
	for(i=1; i<101;i++){
		printf("\nnode [%d]: %d ", i,read->number);
		read=read->next;
			}	
	
	return first_elem;
}




