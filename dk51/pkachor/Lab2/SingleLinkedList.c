#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SingleLinkedList.h"
#include "StringNode.h"
#include <Windows.h>

StringList *newStringList()
{
	StringList *newList = (StringList *)malloc(sizeof(StringList));
	newList->count = 0;
	newList->head = NULL;
	newList->tail = NULL;
	return newList;
}

void addStringNode(StringList *stringList, StringNode *newStringNode)
{
	if (NULL != stringList && NULL != newStringNode)
	{
		if (NULL == stringList->head && NULL == stringList->tail)
		{
			stringList->head = stringList->tail = newStringNode;
			stringList->head->nextNode = stringList->tail->nextNode = NULL;
		}
		else
		{
			StringNode *localNode = stringList->tail;
			stringList->tail = newStringNode;
			if (NULL != localNode)
			{
				localNode->nextNode = stringList->tail;
			}
			stringList->tail->nextNode = NULL;
		}
		stringList->count++;
	}
}

void printStringList(StringList *stringList)
{
	for (StringNode *node = stringList->head; node ; node = node->nextNode)
	{
		Sleep(100);
		printf("%s\n", node->value);
	}
}

StringNode *getNodeAtIndex(StringList *stringList, int index)
{
	if (NULL != stringList)
	{
		StringNode *searchIndex;
		if (index < stringList->count && index >= 0)
		{
			searchIndex = stringList->head;
			for (int i = 0; i != index; i++)
			{
				searchIndex = searchIndex->nextNode;
			}
		}
		else
		{
			printf("Error, invalid index");
			searchIndex = NULL;
		}
		return searchIndex;
	}
	else
	{
		return NULL;
	}
}

StringNode *stringNodeWithMinValue(StringList *stringList)
{
	if (NULL != stringList)
	{
		StringNode *stringNodeWithMinValue = stringList->head;
		for (StringNode *stringNode = stringNodeWithMinValue; NULL != stringNode; stringNode = stringNode->nextNode)
		{
			if (strcmp(stringNodeWithMinValue->value, stringNode->value) > 0)
			{
				stringNodeWithMinValue = stringNode;
			}
		}
		return stringNodeWithMinValue;
	}
	else
	{
		return NULL;
	}
}

StringNode *stringNodeWithMaxValue(StringList *stringList)
{
	if (NULL != stringList)
	{
		StringNode *stringNodeWithMaxValue = stringList->head;
		for (StringNode *stringNode = stringNodeWithMaxValue; NULL != stringNode; stringNode = stringNode->nextNode)
		{
			if (strcmp(stringNode->value, stringNodeWithMaxValue->value) > 0)
			{
				stringNodeWithMaxValue = stringNode;
			}
		}
		return stringNodeWithMaxValue;
	}
	else
	{
		return NULL;
	}
}

void swapStringNodeInSingleStringList(StringNode *stringNode1, StringNode *stringNode2, StringList *stringList)
{
	if (NULL != stringList && NULL != stringNode1 && NULL != stringNode2 && stringNode1 != stringNode2)
	{
		if (stringNode1 == stringList->head || stringNode2 == stringList->head)
		{
			if (stringNode1->nextNode == stringNode2 && stringNode1 == stringList->head)
			{
				if (stringList->tail == stringNode2)
				{
					stringList->tail = stringNode1;
				}
				StringNode *nextStringNode2 = stringNode2->nextNode;
				stringNode2->nextNode = NULL;
				stringList->head = stringNode2;
				stringList->head->nextNode = stringNode1;
				stringList->head->nextNode->nextNode = nextStringNode2;				
			}
			else if (stringNode2->nextNode == stringNode1 && stringNode2 == stringList->head)
			{
				if (stringList->tail == stringNode1)
				{
					stringList->tail = stringNode2;
				}
				StringNode *nextStringNode1 = stringNode1->nextNode;
				stringNode1->nextNode = NULL;
				stringList->head = stringNode1;
				stringList->head->nextNode = stringNode2;
				stringList->head->nextNode->nextNode = nextStringNode1;
			}
			else if (stringNode1 == stringList->head && stringNode1->nextNode != stringNode2)
			{
				if (stringNode2 == stringList->tail)
				{
					stringList->tail = stringNode1;
				}
				StringNode *preStringNode2 = NULL;
				for (StringNode *stringNode = stringList->head; stringNode != stringNode2; stringNode = stringNode->nextNode)
				{
					preStringNode2 = stringNode;
				}
				StringNode *theNode1 = stringList->head;
				StringNode *theNode2 = stringList->head->nextNode;
				StringNode *theNode3 = stringNode2->nextNode;
				stringList->head = stringNode2;
				stringList->head->nextNode = theNode2;
				preStringNode2->nextNode = theNode1;
				theNode1->nextNode = theNode3;
			}
			else if (stringNode2 == stringList->head && stringNode2->nextNode != stringNode1)
			{
				if (stringNode1 == stringList->tail)
				{
					stringList->tail = stringNode2;
				}
				StringNode *preStringNode1 = NULL;
				for (StringNode *stringNode = stringList->head; stringNode != stringNode1; stringNode = stringNode->nextNode)
				{
					preStringNode1 = stringNode;
				}
				StringNode *theNode1 = stringList->head;
				StringNode *theNode2 = stringList->head->nextNode;
				StringNode *theNode3 = stringNode1->nextNode;
				stringList->head = stringNode1;
				stringList->head->nextNode = theNode2;
				preStringNode1->nextNode = theNode1;
				theNode1->nextNode = theNode3;
			}
		}
		else
		{
			if (stringNode1->nextNode == stringNode2)
			{
				if (stringNode2 == stringList->tail)
				{
					stringList->tail = stringNode1;
				}
				StringNode *preStringNode1 = NULL;
				StringNode *nextStringNode2 = stringNode2->nextNode;
				for (StringNode *stringNode = stringList->head; stringNode != stringNode1; stringNode = stringNode->nextNode)
				{
					preStringNode1 = stringNode;
				}
				preStringNode1->nextNode = stringNode2;
				stringNode2->nextNode = stringNode1;
				stringNode1->nextNode = nextStringNode2;

			}
			else if (stringNode2->nextNode == stringNode1)
			{
				if (stringNode1 == stringList->tail)
				{
					stringList->tail = stringNode2;
				}
				StringNode *preStringNode2 = NULL;
				StringNode *nextStringNode1 = stringNode1->nextNode;
				for (StringNode *stringNode = stringList->head; stringNode != stringNode2; stringNode = stringNode->nextNode)
				{
					preStringNode2 = stringNode;
				}
				preStringNode2->nextNode = stringNode1;
				stringNode1->nextNode = stringNode2;
				stringNode2->nextNode = nextStringNode1;

			}
			else
			{
				if (stringNode1 == stringList->tail)
				{
					stringList->tail = stringNode2;
				}
				else if (stringNode2 == stringList->tail)
				{
					stringList->tail = stringNode1;
				}
				StringNode *preStringNode1 = NULL;
				StringNode *preStringNode2 = NULL;
				for (StringNode *stringNode = stringList->head; stringNode != stringNode1; stringNode = stringNode->nextNode)
				{
					preStringNode1 = stringNode;
				}
				for (StringNode *stringNode = stringList->head; stringNode != stringNode2; stringNode = stringNode->nextNode)
				{
					preStringNode2 = stringNode;
				}
				StringNode *nextStringNode1 = stringNode1->nextNode;
				StringNode *nextStringNode2 = stringNode2->nextNode;
				preStringNode1->nextNode = stringNode2;
				preStringNode2->nextNode = stringNode1;
				stringNode1->nextNode = nextStringNode2;
				stringNode2->nextNode = nextStringNode1;
			}
		}
	}
	
}

void deleteNodeInStringListByValue(StringList *stringList, String value)
{
	if (NULL != stringList && NULL !=stringList->head && NULL != stringList->tail)
	{
		int i = 0;
		StringNode *stringNode = NULL;
		if (strcmp(stringList->head->value, value) == 0 && stringList->tail == stringList->head)
		{
			stringNode = stringList->head;
			stringList->head = stringList->head->nextNode;
			stringList->tail = stringList->head;
			freeNode(stringNode);
			stringList->count--;
			i++;
		}
		else if (strcmp(stringList->head->value, value) == 0)
		{
			stringNode = stringList->head;
			stringList->head = stringList->head->nextNode;
			freeNode(stringNode);
			stringList->count--;
			i++;
		}
		else
		{
			StringNode *preNode = NULL;
			for (StringNode *localStringNode = stringList->head; NULL != localStringNode; localStringNode = localStringNode->nextNode)
			{
				if (stringList->tail == localStringNode && strcmp(localStringNode->value, value) == 0)
				{
					stringNode = localStringNode;
					stringList->tail = preNode;
					stringList->tail->nextNode = NULL;
					stringList->count--;
					i++;
					freeNode(stringNode);
					break;
				}
				else if (strcmp(localStringNode->value,value) == 0 && stringList->tail != localStringNode)
				{
					stringNode = localStringNode;
					preNode->nextNode = localStringNode->nextNode;
					stringList->count--;
					i++;
					freeNode(stringNode);
					break;
				}
				preNode = localStringNode;
			}
		}	
		stringNode = NULL;
		if (i > 0)
		{
			deleteNodeInStringListByValue(stringList, value);
		}
	}
}

StringNode *getStringNodeByValue(StringList *stringList, String value)
{
	if (NULL != stringList)
	{
		const StringNode *nonValue = NULL;
		for (StringNode *stringNode = stringList->head; NULL != stringNode; stringNode = stringNode->nextNode)
		{
			if (strcmp(value, stringNode->value) == 0)
			{
				return stringNode;
			}
		}
		return nonValue;
	}
}

int getStringNodeIndexByValue(StringList *stringList, String value)
{
	if (NULL != stringList)
	{
		const int nonValue = -1;
		int i = 0;
		for (StringNode *stringNode = stringList->head; NULL != stringNode; stringNode = stringNode->nextNode)
		{
			if (strcmp(value, stringNode->value) == 0)
			{
				return i;
			}
			i++;
		}
		return nonValue;
	}
}

int getStringNodeIndexByStringNode(StringList *stringList, StringNode *searchStringNode)
{
	if (NULL != stringList && NULL != searchStringNode)
	{
		const int nonValue = -1;
		int i = 0;
		for (StringNode *stringNode = stringList->head; NULL != stringNode; stringNode = stringNode->nextNode)
		{
			if (stringNode == searchStringNode)
			{
				return i;
			}
			i++;
		}
		return nonValue;
	}
}

void sortSingleStringList(StringList *stringList)
{
	for (int i = 0; i < stringList->count - 1; i++)
	{
		int index = i;
		for (int j = i + 1; j < stringList->count; j++)
		{
			if (strcmp(getNodeAtIndex(stringList, index)->value , getNodeAtIndex(stringList, j)->value) < 0)
			{
				index = j;
			}
		}
		swapStringNodeInSingleStringList(getNodeAtIndex(stringList, i),getNodeAtIndex(stringList,index), stringList);
	}
}
