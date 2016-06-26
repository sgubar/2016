#include <stdio.h>
#include <stdlib.h>

#include "add.h"

Node *addNode(Node *head, int n, int value)
{
	int i = 1;
	Node *succesive, *tmp;
	Node *prev = head;
	Node *read;

	if (n == 1)						//dobavlyaem nodu v nachalo
	{
		tmp = CreateNode(value);
		head = tmp;
		head->next = prev;
		return;
	}

	else{ 
		for (i; i < n - 1; i++)			//nahodim nodu, kotoraya dolzna nahoditsya pered novoi
		{
			prev = prev->next;
		};
		succesive = prev->next;			//dobavlyaem svyazi mezhdu novoi nodoy
		tmp = CreateNode(value);
		prev->next = tmp;
		tmp->next = succesive;
	};

	read = head;                             //vivodim spisok na ekran
	for (i = 1; read != NULL; i++) 
	{
		printf("[%d]:%d ", i, read->number);
		read = read->next;
	};
	return head;
};
