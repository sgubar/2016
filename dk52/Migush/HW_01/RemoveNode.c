#include <stdio.h>
#include <stdlib.h>
#include "NewNode.h"
#include "RemoveNode.h"

Node *RemoveNode(Node *first_elem, int m){
	int i=1;
	Node *prev_elem,*removed,*next_elem,*read;
	prev_elem=first_elem;
	
	if(m==1){                          //in that case if we delete the first ellement
	removed=prev_elem; 
		first_elem=next_elem->next;	
	}else{
	
	for(i; i<m-1; i++){                //We are looking for a node that's just in front of us desired
			prev_elem=prev_elem->next;	
	    };
	    removed=prev_elem->next;            //We hang up the remote node to the next and the previous one ("prev_elem" è "next_elem")
	    next_elem=removed->next;
	    prev_elem->next=next_elem;
		removed->next=NULL;            
	};
	read=first_elem;
	for(i=1; read!=NULL;i++){
		printf("\nnode[%d]: %d ",i, read->number);
		read=read->next;
		};
	return removed;
}


