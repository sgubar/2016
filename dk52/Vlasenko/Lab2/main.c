#include <stdio.h>
#include <stdlib.h>



typedef struct Node
{
	int info;
	struct Node* next;
}Node;

void Print(Node* b)
{
	Node* print = b;
	while (print)
	{
		printf("%d ",print->info);
		print = print->next;
	}
	printf("\n");
}

void Init(Node **begin)
{
	*begin = (Node*)malloc(sizeof(struct Node));
	
	(*begin)->info = 0;
	(*begin)->next = NULL;
	
	Node* end = *begin;
	
	int i;
	int j=10;
	for (i=0; i<5; i++)
	{
		end->next = (Node*)malloc(sizeof(struct Node));
		end = end->next;
		end->info = j;
		j = j+10;
		end->next = NULL;
	}
}

void Insert(Node **begin,int data)
{
	Node *tmp = (Node*)malloc(sizeof(struct Node));
	tmp->info = data;
	if (*begin == NULL)
	{
		tmp->next = NULL;
		*begin = tmp;
		return;
	}
	Node *t1 = *begin;
	if (t1->info >= tmp->info)
	{
		tmp->next = t1;
		*begin = tmp;
		return;
	}
	Node *t2 = t1->next;
	while (t2)
	{
		if(t1->info < tmp->info && tmp->info < t2->info)
		{
			t1->next = tmp;
			tmp->next = t2;
			return;
		}
		t1 = t2;
		t2 = t2->next;
	}
	t1->next = tmp;
	tmp->next = NULL;
}

void Delete(Node **begin,int data)
{
	if (*begin == NULL)
	{
		return;
	}
	Node *t1 = *begin;
	if (t1->info == data)
	{
		*begin = t1->next;
		free(t1);
		return;
	}
	Node *t2 = t1->next;
	while (t2)
	{
		if(t2->info == data)
		{
			t1->next = t2->next;
			free(t2);
			return;
		}
		t1 = t2;
		t2 = t2->next;
	}
}

void Free(Node **begin)
{
	if (*begin==0) return;
	Node *p = *begin;
	Node *t;
	while (p)
	{
		t = p;
		p = p->next;
		free(t);
	}
	*begin = NULL;
}

void MenuPrint()
{
	Printf("What would you like to do?");
	Printf("1. Insert the node.");
	Printf("2. Delete the node.");
}

void Menu(int answer)
{
	
}

int main(int argc, char *argv[])
{
	int answer;
	Node* begin = NULL;
	
	Printf("Welcome!");
	MenuPrint();
	scanf("%d",&answer);
	Menu(answer);
	
	Init(&begin);
	Print(begin);
	Insert(&begin,50);
	Print(begin);
	Insert(&begin,25);
	Print(begin);
	Insert(&begin,1);
	Print(begin);
	Delete(&begin,20);
	Print(begin);
	Free(&begin);
	Print(begin);
	
	return 0;
}
