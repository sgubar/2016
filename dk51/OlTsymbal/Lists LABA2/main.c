#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "SingleLIST.h"
#include "SingleNODE.h"

void DoTestList();
void doPrintList(MyList *aList);

int main(int argc, char * argv[])
{
	DoTestList();

	return 0;
}

void DoTestList()
{
	printf("My list -->\n");
	MyNode *theNode1 = CreateNewNode("HII ! ! !");
	MyNode *theNode2 = CreateNewNode("Hello");
	MyNode *theNode3 = CreateNewNode("Good Morning");
	MyNode *theNode4 = CreateNewNode("Good Afternoon");
	MyNode *theNode5 = CreateNewNode("Good Evening");
	

	MyList *aList = CreateANewList();

	AddNode(aList, theNode1);

	AddNode(aList, theNode2);

	AddNode(aList, theNode3);

	AddNode(aList, theNode4);

	printf("start number of elements: %d\n", ListCounter(aList));
	printf("My list without insertion\n");
	doPrintList(aList);

	InsertNode(aList, theNode5, 4);
	
	printf("My list with insertion\n\n");
	doPrintList(aList);
	printf("number of all elements with insertion: %d\n", ListCounter(aList));

	DeletedNode(aList, 0);

	printf("My list with delete\n\n");
	doPrintList(aList);
	printf("number of elements with delete: %d\n", ListCounter(aList));

	FreeMyList(aList);

	printf("DONE!!!\n");
	system("pause");
}

void doPrintList(MyList *aList)
{
	for (int i = 0; i < ListCounter(aList); i++)
	{
		MyNode *theNode = NodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("Node[%d] - value[%s]\n", i, theNode->value);
		}
	}
}