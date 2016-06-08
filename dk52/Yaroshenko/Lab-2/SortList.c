#include <stdio.h>
#include "SortList.h"
#include "CreateNode.h"
#include "AddNodeToList.h"
#include "RemoveNode.h"

Node *SortList(Node *head){
	Node *tmp, *tmp1,*compare, *head1,*beginning ,*read; //*tmp - dlya pervoi iteratsii spiska, *compare - dlya iteratsii pri sravnenii vstavlyaemogo elemnta s predidyshimi nodami,*read - dlya iteratsii spiska pri vivode na ekran
	int i=0,j=0;                                         //vse ostalnie peremennie vspomagatelnie
	beginning=head;
	tmp=beginning;
	compare=beginning;
	
	//sortirovka vstavkoi
	while(tmp!=NULL){                                                    //prohodim spisok, sravnivaya kazhduy nody s predidyshimi                                        
		i++;
		tmp1=tmp->next;
		while(1){                                                        //sravivaem tekyshuy nody s predidyshimi i nahodim ee novuy poryadkovuy nomer
			j++;
			if( tmp->symbol <= compare->symbol || compare==tmp) break;
			compare=compare->next;
		}
		head1=AddNodeToList(beginning,j,tmp->symbol);                    //sozdaem nody s tekyshim znacheniem v novom meste i ybiraem ee so starogo
		beginning=RemoveNode(head1,i+1);
	    j=0;                                                             //"obnylyaem" nekotorie vspomogatelnie peremennie
		compare=beginning;
		tmp=tmp1;
	}
	read=beginning;
	i=1;
	printf("\nSorted list");                                             //vivodim spisok na ekran
	while(read!=NULL){
		printf("\nnode[%d]: %c",i,read->symbol);
		read=read->next;
		i++;
	}
	return beginning;
}
