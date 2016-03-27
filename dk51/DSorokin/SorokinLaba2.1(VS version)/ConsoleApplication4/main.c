#include <stdio.h>
#include <stdlib.h>
#include "Function.h"
#include "FunctionList.h"

int main(int argc, const char * argv[]) {
	int min;
	IntList *theList = CreateList();
	IntList *MinList = CreateList();

	for (int i = 1; i < argc; i++) {
		IntNode *theNode = CreateN(atoi(argv[i]));
		AddNode(theList, theNode);
		printf("Node value: %d\n", theNode->value);
		}

		min = NodeAtIndex(theList, 0)->value;
		printf("Minimal first = %d\n", min);
		int j = 0;
		for (int j=0; j < CountList; j++) {
		
		//printf("i %d\n",i);
		//while (j < CountList(theList)) {
			if (NodeAtIndex(theList, j)->value<min ) {
				min = NodeAtIndex(theList, j)->value;
			}
		} 
	printf("Minimal new = %d\n", min);
	//printf("min value %d\n", min);
	//printf("number of elements: %d\n", CountList(theList));
	//printf("Simple List\n");
	//doPrintList(theList);
	printf("Sorting List\n");
	doPrintList(MinList);
	system ("pause");
}

