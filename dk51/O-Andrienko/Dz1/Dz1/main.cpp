
#include <stdio.h>
#include "SingleLinkedNode.h"
#include "SingleLinkedList.h"

void doTestSLList();
void doPrintSLList(const IntList *aList);

int main(int argc, const char * argv[])
{
	doTestSLList();

	return 0;
}

void doTestSLList()
{
	printf("Start to demo a single-linked list ...\n");

	IntNode *theNode2 = SLCreateNodeWithIntValue(2);
	IntNode *theNode4 = SLCreateNodeWithIntValue(4);

	IntNode *theNode1 = SLCreateNodeWithIntValue(1);

	IntList *theList = SLCreateList();
	printf("number of elements: %d\n", SLCountList(theList));

	SLAddNode(theList, theNode2);
	printf("number of elements: %d\n", SLCountList(theList));

	SLAddNode(theList, theNode4);
	printf("number of elements: %d\n", SLCountList(theList));

	SLInsertNodeAtIndex(theList, theNode1, 0);
	printf("number of elements: %d\n", SLCountList(theList));

	doPrintSLList(theList);

	printf("Removing the node\n");
	SLRemovedNodeAtIndex(theList, 2);

	doPrintSLList(theList);

	SLFreeList(theList);

	printf("Done.\n");

	getchar();

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