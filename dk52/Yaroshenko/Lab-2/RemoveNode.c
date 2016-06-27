#include <stdio.h>
#include <stdlib.h>
#include "CreateNode.h"
#include "RemoveNode.h"

Node *RemoveNode(Node *head, int m,int need){
	int i=1;
	Node *pred,*removed,*sled,*read;
	pred=head;
	
	if(m==1){                          
	removed=pred; 
		head=pred->next;	
	}else{
	
	for(i; i<m-1; i++){                  
			pred=pred->next;	
	    };
	    removed=pred->next;            
	    sled=removed->next;
	    pred->next=sled;
		removed->next=NULL;            
	};
	if(need==1){ 
	free(removed);
	}

    

	return head;
}
