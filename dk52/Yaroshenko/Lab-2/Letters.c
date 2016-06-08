#include <stdio.h>
#include "CreateNode.h"
#include "Letters.h"

Node *Letters(Node *head){

	Node *tmp, *head1;	
	int i=65,j=97;
	char big[2][i], small[2][j]; //massiv big - dlya zaglavnih bykv, small - dlya srtochnih

    head1=head;
	tmp=head;

	for(i; i<91 ; i++){          //zapolnyaem massiv zaglavnimi bykvami
		big[0][i]=i;
		big[1][i]=0;
		
	}

	for(j; j<123 ; j++){         //zapolnyaem massiv strochnimi bykvami
	    small[0][j]=j;
	    small[1][j]=0;
	}

	while(tmp!=NULL){                        //provodim iteratsiu spiska
		for(i=65; i<91 ; i++){               //opredelyaem kakie i skolko zaglavnih bykv voshlo v spisok
			if(tmp->symbol==big[0][i]){
				big[1][i]++;
			}
		}
		for(j=97; j<123 ; j++){
			if(tmp->symbol==small[0][j]){    //opredelyaem kakie i skolko strochnih bykv voshlo v spisok
			    small[1][j]++;	
			}
		}
		tmp=tmp->next;	
		}
	for(i=65; i<91 ; i++){                       //vivodim zaglavnie bykvi i kolichestvo vhozhdeniy kazhdoi iz nih
	   if(big[1][i]!=0){
	   	printf("\n%c: %d",big[0][i],big[1][i]);
	   }
	}
	for(j=97; j<123 ; j++){                      ////vivodim strochnie bykvi i kolichestvo vhozhdeniy kazhdoi iz nih
	   if(small[1][j]!=0){
	   	printf("\n%c: %d",small[0][j],small[1][j]);
	   }
	}		
		
	return head1;	
		
}

