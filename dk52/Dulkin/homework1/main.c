#include <stdio.h>
#include "Node.h"
#include "List.h"

void Test()
{
	IntNode *N1 = CreateNode(2);
	IntNode *N2 = CreateNode(4);
	IntNode *N3 = CreateNode(3);
	
	printf("Creation elements:\n");
	
	IntList *NewList = CreateList();
	printf("number of elements: %d\n", ListSize(NewList));
	
	AddNode(NewList, N1);
	printf("number of elements: %d\n", ListSize(NewList));

	AddNode(NewList, N2);
	printf("number of elements: %d\n", ListSize(NewList));

	InsertAt(NewList, N3, 1);
	printf("number of elements: %d\n", ListSize(NewList));
	
	printf("Current list:\n");
	
	Print(NewList);

	printf("Removing the node [2]\n");
	DeleteAt(NewList, 2);
	
	Print(NewList);

	SetFree(NewList);
}

void Print(const IntList *InList)
{
	int i;
	for (i = 0; i < ListSize(InList); i++)
	{
		IntNode *theNode = NodeAt(InList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}
int main()
{
	Test();
	return 0;
}
