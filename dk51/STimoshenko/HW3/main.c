#include <stdlib.h>
#include <stdio.h>
#include "DynamicArray.h"


int DAProbe();
int printDAsize(DynamicIntArray *anArray);
int main()
{

DAProbe();


}
int DAProbe() {
	printf("DA masive created\n");
	DynamicIntArray *anArray = createDAInt(32);
	printDAsize(anArray);

	valueAtIndex(anArray, 16, 16);
	printf("Index[16]= %d\n", anArray->storage[16]);
	printDAsize(anArray);
		valueAtIndex(anArray, 160, 160);
		printf("Index[160]= %d\n", anArray->storage[160]);
		printDAsize(anArray);
		valueAtIndex(anArray, 16, 32);
		printf("Index[16]= %d\n", anArray->storage[16]);
		printDAsize(anArray);
	freeDAInt(anArray);
	system("pause");
}

int printDAsize(DynamicIntArray *anArray)
{
	printf("Physical size = %d\n Logical size = %d\n", anArray->physicalSize, anArray->logicalSize);
}