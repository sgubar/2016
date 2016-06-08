//
//  DynamicArray.c
//  doTest
//
//  Created by Olexandr Tsymbal on 20/05/16.
//  Copyright © 2016 OlTsymbal. All rights reserved.
//
#include "DynamicArray.h"

#include <stdio.h>

void DoPrintDA(DynamicIntArray *aDynArray, int index);
void DoTest();

int main()
{
	DoTest();

	system("pause");
}

void DoTest()
{
	DynamicIntArray *aDynArray = createDAInt(10);

	setValueAtIndex(aDynArray, 100, 1);
	DoPrintDA(aDynArray, 1);

	setValueAtIndex(aDynArray, 999, 100);
	DoPrintDA(aDynArray, 100);

	freeDAInt(aDynArray);
}

void DoPrintDA(DynamicIntArray *aDynArray, int index)
{
	printf("Value at index %d = [%d]\n",index, valueAtIndex(aDynArray, index));
	printf("Logical Size of DA = [%d]\n", aDynArray->logicalSize);
	printf("Physical Size of DA = [%d]\n", aDynArray->physicalSize);
}