#include <stdio.h>
#include <stdlib.h>
#include "RandomList.h"
#include "NewNode.h"
#include "AddNodeToList.h"
#include "RemoveNode.h"


int main() {
	int value,n,m;
	Node *first_elem,*removed,*newhead;
	printf("You have the list of random 100 numbers\n");
	printf("\nFollow the instructions after the list of actions that you can enter only numbers , letters or symbols to enter prohibited !!!!\n");
	
	
	first_elem=RandomList();                                               //Create new list of 100 items

	printf("\nWhat will be the new index nodes?\n");
	scanf("%d",&n);
	if(n<1 || n>101){                                                      //Check the correctness of the index values
	  printf("\nERROR_ERROR_ERROR!\n");
	  system("pause");
	  exit(0);
	}

	
	printf("What value will be stored in the newly created node?\n");
	scanf("%d",&value);
	newhead=AddNodeToList(first_elem, n, value);                                // add a new node
	
	printf("What is the index of node you would like to remove?\n");      
	scanf("%d",&m);
	if(m<1 || m>102){                                                      //Check the correctness of the index values
	  printf("ERROR_ERROR_ERROR!\n");
	  system("pause");
	  exit(0);
	}
	removed=RemoveNode(newhead,m);                                        //We extract node but do not remove it
	printf("\nYou removed %d ", removed->number);	
	
	return 0;
};

