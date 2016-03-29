#include <stdio.h>
#include <stdlib.h>
#include "SingleNode.h"
#include "SingleList.h"

int main(int argc, const char * argv[]) {

	IntList *theList = CreateList();
	IntList *MinList = CreateList();
	for (int i = 1; i < argc; i++)
	{
		IntNode *theNode = CreateNode(strlen(argv[i]), argv[i]);
		AddNode(theList, theNode);
		printf("Node value: %d\n", theNode->value);
	}

	doPrintList(theList);
	MinToTheMax(theList);
	system("pause");
}