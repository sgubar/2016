//
//  main.c
//  
//
//  Created by Sorokin Dmytro on 5/05/16.
//  Copyright © 2016 Sorokin Dmytro. All rights reserved.
//

#include <stdio.h>
#include "DynamicArray.h"

void printDAsize(DynamicIntArray *anArray);
void testDA();

int main()
{
	testDA();
	system("pause");
}

void testDA() {
	printf("Create dynamic massive\n");
	DynamicIntArray *anArray = createDAInt(10);
	printDAsize(anArray);

	printf("\nAdd number 5 at index 2\n");
	setValueAtIndex(5, 2, anArray);
	printf("Index[2] = %d\n", valueAtIndex(2, anArray));
	printDAsize(anArray);

	printf("\nAdd number 2 at index 0\n");
	setValueAtIndex(2, 0, anArray);
	printf("Index[0] = %d\n", valueAtIndex(0, anArray));
	printDAsize(anArray);

	printf("\nAdd number 140 at index 1\n");
	setValueAtIndex(140, 1, anArray);
	printf("Index[1] = %d\n", valueAtIndex(1, anArray));
	printDAsize(anArray);

	printf("\nAdd number 20 at index 20\n");
	setValueAtIndex(20, 20, anArray);
	printf("Index[20] = %d\n", valueAtIndex(20, anArray));
	printDAsize(anArray);
	freeDAInt(anArray);

}

void printDAsize(DynamicIntArray *anArray) {
	printf("Physical size = %d\n Logical size = %d \n", anArray->physicalSize, anArray->logicalSize);
}