#include <stdio.h>
#include <stdlib.h>
#include "CreateNode.h"
#include "CreateList.h"
#include "MinMaxList.h"
#include "SortList.h"
#include "Letters.h"

int main(){
	Node *head,*head1,*head2, *head3, *head4;    //eti peremennie - ykazateli na pervuy element spiska posle vipolneniya kazhdoi funktsii

	 //sozdaem spisok (vvodit polzovatel)
	head=CreateList();
	
    //menyaem mestami elemementi s maximalnim i minimalnim znacheniem
	head1=MinMaxList(head); 
	
	//ydalyaem element s zadannim polzovatelem kluchom
	head2=DeleteKey(head1);
	
	//otsortiryem spisok
	head3=SortList(head2);

    //podschitaem kolichestvo vhozhdeniy kazhdoi bykvi v spisok
    head4=Letters(head3);
	return 0;
};
