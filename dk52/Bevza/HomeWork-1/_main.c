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
	IntNode *theNode8 = SLCreateNodeWithIntValue(8);
	IntNode *theNode16 = SLCreateNodeWithIntValue(16);
	
	IntList *theList = SLCreateList();
	printf("number of elements: %d\n", SLCountList(theList));
	
	SLAddNode(theList, theNode2);
	printf("number of elements: %d\n", SLCountList(theList));

	SLAddNode(theList, theNode4);
	printf("number of elements: %d\n", SLCountList(theList));
	
	SLAddNode(theList, theNode8);
	printf("number of elements: %d\n", SLCountList(theList));
	
	SLAddNode(theList, theNode16);
	printf("number of elements: %d\n", SLCountList(theList));
	
	doPrintSLList(theList);
	
	SLFreeList(theList);
	
	printf("Done.\n");
}

void doPrintSLList(const IntList *aList)
{
	int i = 0;
	for ( ;i < SLCountList(aList); i++)
	{
		IntNode *theNode = SLNodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}
