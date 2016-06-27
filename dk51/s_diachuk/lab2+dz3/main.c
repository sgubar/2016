#include <stdio.h>
#include <stdlib.h>
#include "SingleList.h"
#include "WorkWithFile.h"
#include "SingleNode.h"

void PrintList(const CharList *aList);

int main()
{
	CharList *theList = ListCreate();
	ReadTheFile(theList);
	theBubbleSorting(theList, theList->count);
	PrintList;
	system("pause");


}

void PrintList(const CharList *aList)
{
	for (int i = 0; i < CountList(aList); i++)
	{
		CharNode *theNode = NodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %s\n", i, theNode->value);
		}
	}
}