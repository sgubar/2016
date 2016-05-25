#include <stdio.h>

#include <stdlib.h>
#include "PrintRandomList.h"
#include "CreateNode.h"
#include "AddNodeToList.h"
#include "RemoveNode.h"


int main() {
	int value,n,m;
	Node *head,*removed,*newhead;
	printf("You have the list of random 10 numbers\n");
	
	
	head=PrintRandomList();                                               //создаем список из 10 случайных чисел
	printf("\nWhat is index of a new node?\n");
	scanf("%d",&n);
	if(n<1 || n>11){                                                      //проверяем корректность введенного индекса
	  printf("\nYou pick the wrong index!\n");
	  system("pause");
	  exit(0);
	}

	
	printf("What value would you like to insert?\n");
	scanf("%d",&value);
	newhead=AddNodeToList(head, n, value);                                //добавляем ноду
	
	printf("What is the index of node you would like to remove?\n");      
	scanf("%d",&m);
	if(m<1 || m>12){                                                      //проверяем корректность введенного индекса
	  printf("You pick the wrong index!\n");
	  system("pause");
	  exit(0);
	}
	removed=RemoveNode(newhead,m);                                        //извлекаем ноду из списка, но не удаляем его
	printf("\nYou removed %d ", removed->number);
	
	
	
	return 0;
};
