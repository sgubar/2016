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

	DynamicIntArray *anArray = createDAInt(15);
	printDAsize(anArray);

	printf("\nAdd number 1 at index 1\n");
	setValueAtIndex(1, 1, anArray);
	printf("Index[1] = %d\n", valueAtIndex(1, anArray));
	printDAsize(anArray);

	printf("\nAdd number 2 at index 0\n");
	setValueAtIndex(2, 0, anArray);
	printf("Index[0] = %d\n", valueAtIndex(0, anArray));
	printDAsize(anArray);

	printf("\nAdd number 134 index 3\n");
	setValueAtIndex(134, 3, anArray);
	printf("Index[3] = %d\n", valueAtIndex(3, anArray));
	printDAsize(anArray);

	printf("\nAdd number 30 at index 25\n");
	setValueAtIndex(30, 25, anArray);
	printf("Index[25] = %d\n", valueAtIndex(25, anArray));
	printDAsize(anArray);

	freeDAInt(anArray);

	
}
void printDAsize(DynamicIntArray *anArray) 
{
	printf("Physical size = %d\n Logical size = %d \n", anArray->physicalSize, anArray->logicalSize);
}