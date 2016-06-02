#include <stdio.h>
#include <stdlib.h>
#include "CreateNode.h"
#include "RemoveNode.h"

Node *RemoveNode(Node *head, int m){
	int i=1;
	Node *pred,*removed,*sled,*read;
	pred=head;
	
	if(m==1){                          //в случае если извлекаем первый элемент списка
	removed=pred; 
		head=pred->next;	
	}else{
	
	for(i; i<m-1; i++){                //ищем ноду, которая должна находиться перед новой нодой
			pred=pred->next;	
	    };
	    removed=pred->next;            //разрываем связи удаленной ноды с соседними ("pred" и "sled)
	    sled=removed->next;
	    pred->next=sled;
		removed->next=NULL;            
	};
	read=head;
	for(i=1; read!=NULL;i++){
		printf("\nnode[%d]: %d ",i, read->number);
		read=read->next;
		};
	return removed;
}

