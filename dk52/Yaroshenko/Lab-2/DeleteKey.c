#include <stdio.h>
#include <stdlib.h>
#include "DeleteKey.h"
#include "RemoveNode.h"

Node *DeleteKey(Node *head){
	Node *deleted, *tmp, *tmp1, *head1, *read;
	char key;
	int i=0,numbdel=0;
	tmp=head;
	head1=head;
	printf("Enter the key to delete from the list\n");
	scanf("%c",&key);
	while(tmp!=NULL){
		i++;
		if(tmp->symbol==key){
			tmp1=RemoveNode(head1,i,1);
			head1=tmp1;	
			i=0;
			numbdel++;
			tmp=tmp1;
		}else{
		tmp=tmp->next;
		}
	}
	read=head1;
	for(i=1; read!=NULL ;i++){
		printf("\nnode [%d]: %c ", i,read->symbol);
		read=read->next;
	};
	if(numbdel==0){
		printf("\nKey wasn't found ");
	}
	return head1;
}
