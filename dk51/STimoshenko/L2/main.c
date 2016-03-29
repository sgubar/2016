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
		
	}
	
	doPrintList(theList);
	TheMinAndTheMax(theList);
	system("pause");
}