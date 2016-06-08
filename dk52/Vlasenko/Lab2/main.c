#include <stdio.h>
#include <stdlib.h>
#include <time.h>



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

void Init_random(Node **begin)
{
	*begin = (Node*)malloc(sizeof(struct Node));
	srand(time(NULL));
	
	(*begin)->info = rand() % 1001;
	(*begin)->next = NULL;
	
	Node* end = *begin;
	
	int i;
	for (i=0; i<5; i++)
	{
		end->next = (Node*)malloc(sizeof(struct Node));
		end = end->next;
		end->info = rand() % 1001;
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

void Change_min_max(Node **begin)
{
	int min, max;
	Node *t1 = *begin;
	min = t1->info;
	if (t1->info < min)
	{
		*begin = t1->next;
		free(t1);
		return;
	}
}

void Bubble_sort(Node *begin)
{
    Node * p = NULL;
    
    if (begin != NULL)
	{
        while (begin->next != NULL)
		{
            p = begin->next;
            
            do
			{
                if (p->info < begin->info)
				{
                    int tmp = p->info;
                    p->info = begin->info;
                    begin->info = tmp;
                }
                
                p = p->next;
            } while (p != NULL);
            
            begin = begin->next;
        }
    }
}

void Insertion_sort(Node *begin)
{
    Node *p, *key;
    Node *result = begin;
    begin = begin->next;      /* Головой стал следующий элемент */
    result->next = NULL;    /* Первый элемент отсортированного списка */

    while(begin->next != NULL)
	{
        key = begin;
        begin = begin->next;
        if(key->info < result->info)
		{   /* Вставляем результат в голову */
            key->next = result;
            result = key;
        }
		else
		{
            p = result;
            while(p->next != NULL)
			{     /* Бежим по уже сформированному результату */
                if(p->next->info > key->info)
                    break;
                p = p->next;
            }
            key->next = p->next;
            p->next = key;
        }
    }
    begin = result;
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
	printf("\nWhat would you like to do?");
	printf("\n1. Insert the node. (It should be sorted before)");
	printf("\n2. Delete the node.");
	printf("\n3. Bubble-sort the list.");
	printf("\n4. Isertion-sort the list.");
	printf("\n5. Quit.\n");
}

int main(int argc, char *argv[])
{
	int answer, info;
	Node* begin = NULL;
	Init_random(&begin);
	
	printf("Welcome!\n");
	printf("\nThis is your list:\n");
	Print(begin);
	
	start:
	answer=0;
	MenuPrint();
	scanf("%d",&answer);
	if (answer == 1)
	{
		printf("Enter data: ");
		scanf("%d",&info);
		Insert(&begin, info);
		Print(begin);
		goto start;
	}
	if (answer == 2)
	{
		printf("Enter data: ");
		scanf("%d",&info);
		Delete(&begin, info);
		Print(begin);
		goto start;
	}
	if (answer == 3)
	{
		Bubble_sort(begin);
		Print(begin);
		goto start;
	}
	if (answer == 4)
	{
		Insertion_sort(begin);
		Print(begin);
		goto start;
	}
	if (answer == 5)
	{
		goto finish;
	}
	else
	printf("\nNo such answer!");
	
	finish:
	Free(&begin);
	return 0;
}
