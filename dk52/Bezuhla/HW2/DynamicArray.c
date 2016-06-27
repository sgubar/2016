#include "DynamicArray.h"

DynamicIntArray *createDAInt(int aSize) //создаем динамический массив
{
	DynamicIntArray* array = malloc(sizeof(DynamicIntArray)); 
	array->logicalSize = aSize; 
	array->physicalSize = sizeof(int)*(array->logicalSize);
	array->storage = malloc (sizeof(int)*aSize);
	return array; 
}
void freeDAInt(DynamicIntArray *anArray) // чистим память
{
	free(anArray->storage); 
	free(anArray);
}

int valueAtIndex(DynamicIntArray *anArray, int anIndex) //возвращает элемент по заданому номеру
{
	if(anIndex < anArray->logicalSize) //если этот номер в массиве есть
	{
		return anArray->storage[anIndex]; // возвращает этот элемент
	}
	else 
	{
		return NULL; //возвращает NULL
	}
}

void setValueAtIndex(DynamicIntArray *anArray, int anValue, int anIndex) //устанавливает элемент по заданому номеру
{
	if(anIndex < anArray->logicalSize) //если этот номер в массиве есть
	{
		anArray->storage[anIndex] = anValue; //присвоим элементу этого номера значение anValue
	}
}

void setArray(DynamicIntArray *anArray) // заполняем массив элементами
{
	int i;
	for(i = 0; i<anArray->logicalSize; i++) //для всех элементов массива
	{
		int val = i+100; 
		setValueAtIndex(anArray, val, i);//заполняем его значениями на 100 больше чем номер элемента
	}
}

void printArray(DynamicIntArray *anArray) //выводим на экран значения массива
{
	int i;
	for(i = 0; i<anArray->logicalSize; i++) //для всех элементов массива
	{
		printf("element%d: %d\n", i, valueAtIndex(anArray, i)); // печатаем номер элемента и сам элемент
	}
}
