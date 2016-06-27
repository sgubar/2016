#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StringNode.h"

StringNode *newNode(String value)
{
	StringNode *node = (StringNode *)malloc(sizeof(StringNode));
	node->value = duplicateString(value);
	node->nextNode = NULL;
	return node;
}

String duplicateString(String string)
{
	String returnString = (String)malloc(sizeof(strlen(string)) + 1);
	if (NULL != returnString)
	{
		strcpy(returnString, string);
	}
	return returnString;
}

void freeNode(StringNode *node)
{
	if (NULL != node)
	{
		free(node);
	}
}