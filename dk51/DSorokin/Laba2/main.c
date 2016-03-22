#include <stdio.h>
#include <stdlib.h>
#include "Function.h"
#include "FunctionList.h"

int main(int argc, const char * argv[]){
	IntNode *theNode2 = CreateNodeWithIntValue(2);
	IntNode *theNode4 = CreateNodeWithIntValue(4);

	IntList *theList = CreateList();
	//printf("number of elements: %d\n", CountList(theList));

    doPrintSLList(theList);
if(argc!=1){
//IntNode *Node = CreateN(atoi(argv[1]));
printf("Node created.\n");
}
//printf("Node value: %s", Node->value);
return 0;
}

