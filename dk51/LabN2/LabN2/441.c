#include <stdio.h>
#include "SingleLinkedNode.h"
#include "SingleLinkedList.h"

void doTestSLList();
void doPrintSLList(const IntList *aList);

int main(int argc, const char * argv[])
{
	doTestSLList();
	system("pause");
	return 0;
}

void doTestSLList()
{
	printf("Start to demo a single-linked list ...\n");

	IntNode *theNode2 = SLCreateNodeWithIntValue(4);
	IntNode *theNode4 = SLCreateNodeWithIntValue(8);
	IntNode *theNode1 = SLCreateNodeWithIntValue(8);
	IntNode *theNode3 = SLCreateNodeWithIntValue(7);

	IntList *theList = SLCreateList();
	printf("number of elements: %d\n", SLCountList(theList));

	SLAddNode(theList, theNode2);
	printf("number of elements: %d\n", SLCountList(theList));

	SLAddNode(theList, theNode4);
	printf("number of elements: %d\n", SLCountList(theList));

	SLInsertNodeAtIndex(theList, theNode3, 1);
	printf("number of elements: %d\n", SLCountList(theList));
	
	SLInsertNodeAtIndex(theList, theNode1, 3);
	printf("number of elements: %d\n", SLCountList(theList));

	doPrintSLList(theList);

	printf("Removing the node\n");
	SLRemovedNodeAtIndex(theList, 2);

	doPrintSLList(theList);

	SLFreeList(theList);

	printf("Done.\n");
}

void doPrintSLList(const IntList *aList)
{
	for (int i = 0; i < SLCountList(aList); i++)
	{
		IntNode *theNode = SLNodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}
