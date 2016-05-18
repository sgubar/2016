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

	printf("\nAdd number 666 at index 3\n");
	setValueAtIndex(666, 3, anArray);
	printf("Index[3] = %d\n", valueAtIndex(3, anArray));
	printDAsize(anArray);

	printf("\nAdd number 25 at index 25\n");
	setValueAtIndex(25, 25, anArray);
	printf("Index[25] = %d\n", valueAtIndex(25, anArray));
	printDAsize(anArray);
	freeDAInt(anArray);

}

void printDAsize(DynamicIntArray *anArray) {
	printf("Physical size = %d\n Logical size = %d \n", anArray->physicalSize, anArray->logicalSize);
}