//  Source.c
//  Laba. 2 var. 13
//
//  Created by Ryzhenkov Serhii on 30/03/16.
//  Copyright © 2016 Ryzhenkov Serhii. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include "Fun.h"
#include "FunList.h"

int main(int argc, const char * argv[])   //ѕринимаем аргументы
{	
	int count;
	if (1 == argc)						// цикл проверки на присутствие аргументов
	{
		printf("Error");
		return 0;
	}

	IntList *theList = Create_L();		// создаем списки 

	for (int i = 1; i < argc; i++)				// цикл дл€ создани€ нод, за количеством введенных аргументов 
	{
		IntNode *theNode = CreateNode(atoi(argv[i]));	//atoi переводит char в int
		AddNode(theList, theNode);
		printf("Node: %d\n", theNode->value);
	}

	printf("List: \n");			// вывод списка
	PrintList(theList);

	distribution(theList);		// функци€ дл€ сортировки
	//UpdatedValue(theList);
	count = CountList(theList);
	bubbleSort(theList, count);

	system("pause");
}

