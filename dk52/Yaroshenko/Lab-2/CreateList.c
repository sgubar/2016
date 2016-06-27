#include <stdio.h>
#include "CreateNode.h"
#include "CreateList.h"
#include <string.h>

Node *CreateList(){
	char str[30];                                    //v kachestve istochnika dlya napolnieniya spiska ispolzyem stroky simvolov, rototyu vvel polzovatel
	int i=0,endofline;
	Node *head,*tmp,*tail,*read;
	printf("Enter the text (only one string)\n");
	gets(str);
	endofline=strlen(str);
	while(i<endofline){                              //napolnyaem spisok
		tmp=CreateNode(str[i]);
		if (i==0){
		head=tmp;
		tail=head;
		} else{
		tail->next=tmp;
		tail=tmp;
		}
		i++;
	};
	read=head;                                       //iteratsia i vivod spiska na ekran
		for(i=1; read!=NULL ;i++){
		printf("\nnode [%d]: %c ", i,read->symbol);
		read=read->next;
			}
	return head;	
}

