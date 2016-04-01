#include <stdio.h>
#include <stdlib.h>

typedef struct TList TList;

struct TList
{
    int Data;
    TList *Next;
};

/* функция добавления в список */
void AddToList(TList **pBegin,const int a)
{
    TList* p=NULL;
    if(*pBegin==NULL) /*новый список */
    {
        *pBegin=malloc(sizeof(**pBegin));
        (*pBegin)->Data=a;
        (*pBegin)->Next=NULL;
    }
    else
    {
        /* добавляем в конец */
        p=*pBegin;
        while(p->Next!=NULL) p=p->Next;
        p->Next=malloc(sizeof(*p));
        p->Next->Data=a;
        p->Next->Next=NULL;
    }
}

/* функция печати списка на экран */
void PrintList(const TList* pBegin)
{

    const TList *p=pBegin;
    printf("%s\n","===== List values =====");
    while(p!=NULL)
    {
        printf("%p%s%i\n",p,": ",p->Data);
        p=p->Next;
    }
    if(pBegin==NULL) printf("%s\n","List is empty");
}

/* функция очистки списка */
void ClearList(TList** pBegin)
{
    TList *p=NULL;
    while(*pBegin!=NULL)
    {
        p=(*pBegin)->Next;
        free(*pBegin);
        *pBegin=p;
    }
}

/* функция сортировки списка по возрастанию */
void SortList(TList** pBegin)
{
    int NodesCount=0;   /* количество узлов в списке */
    TList** Nodes=NULL; /* массив указателей на узлы списка */
    int i,j,max=1;            /* переменные циклов */
    TList* temp;        /* параметр */
    /* считаем число узлов в списке */
    temp=*pBegin;
    while(temp!=NULL)
    {
        NodesCount=NodesCount+1;
        temp=temp->Next;
    }
    if(NodesCount!=0)
    {
        Nodes=malloc(NodesCount*sizeof(*Nodes));
        i=0;
        /* копируем адреса узлов в массив */
        temp=*pBegin;
        while(temp!=NULL)
        {
            Nodes[i]=temp;
            i=i+1;
            temp=temp->Next;
        }
        for (i=1;i<NodesCount;i++)
        {
        	if((Nodes[max]->Data)>(Nodes[i]->Data)) max=i;
        }
        /* сортировка массива пузырьком */
        for(j=0;j<max+1;j++)
        {
            for(i=0;i<max;i++)
            {
                if((Nodes[i]->Data)>(Nodes[i+1]->Data))
                {
                    temp=Nodes[i];
                    Nodes[i]=Nodes[i+1];
                    Nodes[i+1]=temp;
                }
            }
        }
        /* восстанавливаем векторность списка */
        for(i=0;i<NodesCount-1;i++) Nodes[i]->Next=Nodes[i+1];
        Nodes[NodesCount-1]->Next=NULL;
        /* возвращаем модифицированный список */
        *pBegin=Nodes[0];
        free(Nodes);
    }
}

/* функция обработки списка */


int main(void)
{
    TList* a=NULL;  /* указатель на начало списка */
    int k=0;
    int i=0;
    for(i=0;i<10;i++)
    {
        scanf("%d",&k);
        AddToList(&a,k);
    }
    PrintList(a);
    SortList(&a);
    PrintList(a);
    ClearList(&a);
    getchar();
    return 0;
}
