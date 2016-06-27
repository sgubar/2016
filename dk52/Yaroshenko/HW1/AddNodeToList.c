#include <stdio.h>
#include <stdlib.h>
#include "CreateNode.h"

Node *AddNodeToList(Node* head, int n, int value){
	int i=1;
	Node *pred=head;
	Node *sled,*tmp;
	Node *read;
	if(n==1){
		tmp=CreateNode(value);    //в случае если мы собираемся вставить ноду в начало списка
		head=tmp;
		head->next=pred;          //список получает новый указатель на первый элемент ("голову")
		}
	else{
	for(i; i<n-1; i++){           //ищем ноду, которая должна находиться перед новой нодой
			pred=pred->next;	
	    };
	sled=pred->next;	          //вставляем новую ноду между соседними с указателями "pred" и "sled"
	tmp=CreateNode(value);
	pred->next=tmp;
	tmp->next=sled;
   };
   read=head;                             //выводим список на экран
	for(i=1; read!=NULL;i++){
		printf("\nnode[%d]: %d ", i,read->number);
		read=read->next;
			};
	return head;
	
};
