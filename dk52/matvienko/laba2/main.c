#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "ListAdd.h"



int main()
{
	int n, a;
	Node *head, *tail;
	
	scanf("%d\n", &n);
	
	for (int i; i < n; i++)
	{
		scanf("%c", &a);
		AddList(&head, &tail,a);
	}
}
