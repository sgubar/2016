#include <stdio.h>
#include "MinMaxList.h"
#include "AddNodeToList.h"
#include "RemoveNode.h"



Node *MinMaxList(Node *head){
	Node *tmpMax, *tmpMin, *tmp,*read, *head1, *head2, *head3, *head4; 
	//*tmpMax - ykazatel na maximalnuy element spiska , *tmpMin - ykazatel na minimalnuy element spiska, *tmp - dlya pervoi iteratsii spiska,*read - dlya vivoda spiska na ekran
	//vse ostalnie peremennie vspomagatelnie
	int max=1,min=1,i=1;
	
	tmpMax=head;
	tmpMin=head;
	tmp=head;
	
	//nahodim ykazateli na maximalnuy i minimalnuy elementi spiska i ih poryadkovie nomera
	while(tmp!=NULL){                                
       if(tmpMax->symbol < tmp->symbol){           
       	tmpMax=tmp;
       	max=i;
	   };  
	   if(tmpMin->symbol > tmp->symbol){         
	   	tmpMin=tmp;
	   	min=i;
	   };
	   tmp=tmp->next;
	   i++;
	};
     
     
	 head1=AddNodeToList(head,max,tmpMin->symbol); //pered nodoi s maximalnym elementom sozdaem nody so znacheniem minimalnogo elementa
	 head2=RemoveNode(head1,max+1,0);                //ybiraem nody s maximalnym elementom (na ee meste ostaetsa noda s minimalnim elementom)
	 head3=AddNodeToList(head2,min,tmpMax->symbol);//pered nodoi s minimalnym elementom sozdaem nody so znacheniem maximalnogo elementa
	 head4=RemoveNode(head3,min+1,0);                //ybiraem nody s minimalnym elementom (na ee meste ostaetsa noda s maximalnym elementom)
	 
	printf("\nAfter changing max i min elements");//vivodim spisok na ekran
	read=head4;
		for(i=1; read!=NULL ;i++){
		printf("\nnode [%d]: %c ", i,read->symbol);
		read=read->next;
		};
	return head4;
};
