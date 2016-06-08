#include <stdio.h>
#include <stdlib.h>
#include "CreateNode.h"
#include "AddNodeToList.h"

Node *AddNodeToList(Node* head, int n, char symbol){
	int i=1;
	Node *pred=head;
	Node *sled,*tmp;
	Node *read;
	if(n==1){
		tmp=CreateNode(symbol);    
		head=tmp;
		head->next=pred;          
		}
	else{
	for(i; i<n-1; i++){           
			pred=pred->next;	
	    };
	sled=pred->next;	          
	tmp=CreateNode(symbol);
	pred->next=tmp;
	tmp->next=sled;
   };
  
	return head;
	
};
