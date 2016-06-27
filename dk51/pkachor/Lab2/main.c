#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "StringNode.h"
#include "SingleLinkedList.h"

void swapMinMax(StringList *stringList);
void swapAllElementsWithinAnotherThatRepeatByValue(StringList *stringList, String value);

main()
{
	StringList *list = newStringList();
	addStringNode(list, newNode("5"));
	addStringNode(list, newNode("123"));
	addStringNode(list, newNode("1"));
	addStringNode(list, newNode("6"));
	addStringNode(list, newNode("7")); 
	addStringNode(list, newNode("215"));
	addStringNode(list, newNode("4352"));
	addStringNode(list, newNode("4"));
	addStringNode(list, newNode("42534"));
	addStringNode(list, newNode("5"));
	addStringNode(list, newNode("4000000"));
	addStringNode(list, newNode("347"));
	addStringNode(list, newNode("4"));
	addStringNode(list, newNode("12356"));
	addStringNode(list, newNode("234"));
	addStringNode(list, newNode("234"));
	addStringNode(list, newNode("5"));
	addStringNode(list, newNode("2345"));
	addStringNode(list, newNode("234"));
	addStringNode(list, newNode("123"));
	addStringNode(list, newNode("5"));

	printf("Create list:\n");
	printStringList(list);
	printf("\n\n");

	swapMinMax(list);
	printf("\n\n");

	printf("Swap min and max:\n");
	printStringList(list);
	printf("\n\n");

	addStringNode(list, newNode("9"));

	deleteNodeInStringListByValue(list, "5");
	printf("\n\n");

	printf("Delete by value \"5\":\n");
	printStringList(list);
	printf("\n\n");

	addStringNode(list, newNode("9"));

	swapAllElementsWithinAnotherThatRepeatByValue(list, "123");
	printf("\n\n");

	printf("Swap all elements within another that repeat by value:\n");
	printStringList(list);
	printf("\n\n");

	addStringNode(list, newNode("9"));

	sortSingleStringList(list);
	printf("\n\n");

	printf("Sort list:\n");
	printStringList(list);
	printf("\n\n");

	system("pause");
	return 0;
}

void swapMinMax(StringList *stringList)
{
	swapStringNodeInSingleStringList(stringNodeWithMaxValue(stringList), stringNodeWithMinValue(stringList), stringList);
}

void swapAllElementsWithinAnotherThatRepeatByValue(StringList *stringList, String value)
{
	if (NULL != stringList)
	{
		StringNode* firstRepeat = NULL;
		StringNode* secondRepeat = NULL;
		for (StringNode *stringNode = stringList->head; NULL != stringNode; stringNode = stringNode->nextNode)
		{
			if (NULL == firstRepeat && strcmp(stringNode->value, value) == 0)
			{
				firstRepeat = stringNode;
			}
			 if (NULL != firstRepeat && strcmp(stringNode->value, value) == 0)
			{
				secondRepeat = stringNode;
			}
		}
		if (NULL != firstRepeat && NULL != secondRepeat)
		{
			int i = getStringNodeIndexByStringNode(stringList, firstRepeat);
			int j = getStringNodeIndexByStringNode(stringList, secondRepeat);
			for (; i <= j; i++, j--)
			{
				swapStringNodeInSingleStringList(getNodeAtIndex(stringList, i), getNodeAtIndex(stringList, j), stringList);
			}
		}
	}
}



/*								*
	 *	if (NULL != node)			*
	 *	{							*
	 *		free(node);				*
	 *	}							*
	 *	if (NULL == node)			*
	 *	printf("yes");				*
	 *	printf("%s", node->value);	*
	 *	question					*/