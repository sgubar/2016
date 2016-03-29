#include <stdio.h>
#include <stdlib.h>
#include "Function.h"
#include "FunctionList.h"

int main(int argc, const char * argv[]) {
	
	if (1 == argc) {
		printf("Error, incorrect input data");
		return 0;
	}

	IntList *theList = CreateList();
	IntList *MinList = CreateList();

	for (int i = 1; i < argc; i++) {
		IntNode *theNode = CreateN(atoi(argv[i]));
		AddNode(theList, theNode);
		printf("Node value: %d\n", theNode->value);
		}

		printf("Simple List\n");
		doPrintList(theList);
	
		doSorting(theList);
		doChangeValue(theList);
		
	system ("pause");
}
