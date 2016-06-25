#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WorkWithFile.h"
#include "SingleNode.h"
#include "SingleList.h"


CharList ReadTheFile(CharList *aList)
{
	FILE *ReadingFile;
 	ReadingFile = fopen("text.txt", "r");
	if (ReadingFile == NULL)
	{
		printf("Can not foud file text.txt\n");
		return;
	}
	char RString[200], *Number, *last,*Number1;
	while (NULL != fgets(RString, 200, ReadingFile))
	{
		Number = strtok_s(RString, " ", &last);
		Number1 = Oborot(Number);
		CharNode *NewNode = NodeAdd(aList, Number1);
		printf("Value in node %s\n", NewNode->value);
		while (NULL != Number)
		{
			Number = strtok_s(NULL, " ", &last);
			if (NULL != Number)
			{
				*Number1 = Oborot(Number);
				CharNode *NewNode = NodeAdd(aList, Number1);
				
				printf("Value in node %s\n", NewNode->value);
			}
		}
	}
	fclose(ReadingFile);
}

char *Oborot(char *Word)
{
	printf("Word: %s\n", Word);
	char Result[30];
	int a = strlen(Word);
	for (int i = 0;i < a;i++)
	{
		Result[i] = Word[a - i-1];
	}
	printf("The result oborot %s \n", Result);
	return Result;
}