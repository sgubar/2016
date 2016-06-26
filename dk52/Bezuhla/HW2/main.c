#include <stdio.h>
#include "DynamicArray.h"

int main(int argc, const char * argv[]) 
{ 
	DynamicIntArray *ar = createDAInt(25); //создаем массив на 25 элементов
	setArray(ar);//заполняем массив

	printArray(ar); // выводим массив
	
	printf("\nphys size: %d\n", ar->physicalSize); //выводим физический размер и логический размер
	printf("log size: %d\n", ar->logicalSize);
	
//	printf(" size: %d\n", sizeof(DynamicIntArray));
	
	freeDAInt(ar); //чистим память
	printf("Done");
	return 0;
}
