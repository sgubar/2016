//
//  main.c
//  Homework2
//
//  Created Sergey Fedorenko on 4/6/16.
//  Copyright © 2016 Sergey Fedorenko. All rights reserved.
//
#include "DynamicArray.h"
#include <stdio.h>
void DynAr();
void printDAsize(DynamicIntArray *anArray);
int main()
{
	DynAr();
	system("pause");
}

void DynAr() {
	printf("Create dynamic with integer value\n");
	DynamicIntArray *anArray = createDAInt(5);
	printDAsize(anArray);

	setValueAtIndex(5, 0, anArray);
	setValueAtIndex(2, 1, anArray);
	setValueAtIndex(10, 2, anArray);
	setValueAtIndex(1, 3, anArray);	
	setValueAtIndex(13, 4, anArray);
	
	printf("Index[2] = %d\n", valueAtIndex(2, anArray));

	printDAsize(anArray);
	setValueAtIndex(3, 6, anArray);
	setValueAtIndex(7, 5, anArray);
	setValueAtIndex(8, 7, anArray);

	printf("Index[7] = %d\n", valueAtIndex(7, anArray));

	printDAsize(anArray);

	freeDAInt(anArray);

	printDAsize(anArray);
}
void printDAsize(DynamicIntArray *anArray) 
{
	printf("Physical size = %d\n Logical size = %d \n", anArray->physicalSize, anArray->logicalSize);
}