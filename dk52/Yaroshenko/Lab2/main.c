#include <stdio.h>
#include "List.h"

void dotask();


void main() {
	
	dotask();
}

void dotask() {

	int LISTSIZE=1;
	str * MList = NULL; /*Create our main list*/
	printf("\nEnter size of List  "); 
	do { /*Check LISTSIZE WILL BE > 0	*/																		
		if (LISTSIZE<=0) printf("\nSize doesn't be 0 size. Retype : ");
		scanf_s("%d", &LISTSIZE);
	} while (LISTSIZE<=0);


	MList = CreateListWithRandomValue(LISTSIZE, MList); /*Create [LISTSIZE] list. Func return point of first element of list*/
	OutputList(MList); /*Display Result*/
	SearchAndDisplayMinMaxElemets(MList);


}
