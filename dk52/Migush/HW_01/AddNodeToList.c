#include <stdio.h>
#include <stdlib.h>
#include "NewNode.h"

Node *AddNodeToList(Node* head, int n, int value){
	int i=1;
	Node *prev_elem=head;
	Node *next_elem,*tmp;
	Node *read;
	if(n==1){
		tmp=CreateNode(value);    //if we want to insert a node in the top of the list
		head=tmp;
		head->next=prev_elem;          //list gets a new pointer to the first element( "first_elem")
		}
	else{
	for(i; i<n-1; i++){           //We are looking for a node that is in front of the one that we create
			prev_elem=prev_elem->next;	
	    };
	next_elem=prev_elem->next;	          //inserted between adjacent year, with pointers "prev_elem" è "next_elem"
	tmp=CreateNode(value);
	prev_elem->next=tmp;
	tmp->next=next_elem;
   };
   read=head;                             
	for(i=1; read!=NULL;i++){
		printf("\nnode[%d]: %d ", i,read->number);
		read=read->next;
			};
	return head;
	
};

