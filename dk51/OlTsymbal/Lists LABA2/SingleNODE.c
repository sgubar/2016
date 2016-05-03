#include "SingleNODE.h"
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

MyNode *CreateNewNode(char *aValue)
{
	int len = strlen(aValue);

	MyNode *theResult;
	theResult = (MyNode *)malloc(sizeof(MyNode));
	
	char * value;
	value = malloc((len + 1)*sizeof(char));
	memset(value, 0, len + 1);

	for (int i = 0; i < len ; i++)
	{
		value[i] = *(aValue + i);
	}
	theResult->value = value;
	theResult->nextNode = NULL;
	return theResult;
}
void FreeMyNode(MyNode *Node)
{
	if (NULL != Node)
	{
		free(Node);
	}
}
