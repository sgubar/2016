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
	DynamicIntArray *anArray = createDAInt(10);
	printDAsize(anArray);

	printf("\nAdd number 5 at index 0\n");
	setValueAtIndex(5, 0, anArray);
	printf("Index[0] = %d\n", valueAtIndex(0, anArray));
	printDAsize(anArray);

	printf("\nAdd number 2 at index 1\n");
	setValueAtIndex(2, 1, anArray);
	printf("Index[1] = %d\n", valueAtIndex(1, anArray));
	printDAsize(anArray);

	printf("\nAdd number 10 at index 2\n");
	setValueAtIndex(10, 2, anArray);
	printf("Index[2] = %d\n", valueAtIndex(2, anArray));
	printDAsize(anArray);

	printf("\nAdd number 20 at index 3\n");
	setValueAtIndex(20, 3, anArray);
	printf("Index[3] = %d\n", valueAtIndex(3, anArray));
	printDAsize(anArray);
	freeDAInt(anArray);
}
void printDAsize(DynamicIntArray *anArray) 
{
	printf("Physical size = %d\n Logical size = %d \n", anArray->physicalSize, anArray->logicalSize);
}