//
//  main.c
//  Dz 2
//
//  Created by Stanislav Bashkirov on 4/7/16.
//  Copyright © 2016 Stanislav Bashkirov. All rights reserved.
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

	printf("\nAdd number 20 at index 100\n");
	setValueAtIndex(20, 100, anArray);
	printf("Index[100] = %d\n", valueAtIndex(100, anArray));
	printDAsize(anArray);
	freeDAInt(anArray);

}

void printDAsize(DynamicIntArray *anArray) {
	printf("Physical size = %d\n Logical size = %d \n", anArray->physicalSize, anArray->logicalSize);
}