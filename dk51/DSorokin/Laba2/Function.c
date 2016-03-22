#include "Function.h"
#include <stdlib.h>
#include <stdio.h>
#include "FunctionList.h"

IntNode *CreateN(int perevod);

IntNode *CreateN(int perevod){
IntNode *theResult = (IntNode *)malloc(sizeof(IntNode));
theResult->value = perevod;
theResult->nextNode = NULL;
return theResult;
}

void FreeIntNode(IntNode *Node)
{
	if (NULL != Node)
	{
		free(Node);
	}
}
