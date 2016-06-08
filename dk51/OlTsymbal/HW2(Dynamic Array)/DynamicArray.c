//
//  DynamicArray.c
//  doTest
//
//  Created by Olexandr Tsymbal on 20/05/16.
//  Copyright © 2016 OlTsymbal. All rights reserved.
//

#include "DynamicArray.h"

#include <stdio.h>
#include <stdlib.h>

DynamicIntArray *createDAInt(int aSize)
{
	DynamicIntArray *anArray = (DynamicIntArray *)malloc(sizeof(DynamicIntArray));// виділяємо пам'ять розміром із структура
	anArray->storage = (int *)malloc(aSize*sizeof(int));//виділяєо пам'ять для масиву даних
	anArray->logicalSize = 0;//визначаємо логічний розмір(кількість заповнених комірок) (за замовчуванням 0)
	anArray->physicalSize = aSize;// визначаємо фізичний розмір(кількість комірок)
	memset(anArray->storage, 0, aSize);//заповнюємо початковий масив даних нулями

	return anArray;
}

void freeDAInt(DynamicIntArray *anArray)//звільняємо пам'ять
{
	free(anArray->storage);
	free(anArray);//
}

int valueAtIndex(DynamicIntArray *anArray, int anIndex)
{
	if (NULL == anArray) return NULL;//перевіряємо вхідний масив
	if (anIndex > anArray->physicalSize) return (anArray->physicalSize);//якщо це  індекс неіснуючого елемнта, то повертаємо фізичний розмір
	if (anIndex < anArray->physicalSize) return (anArray->storage[anIndex]);//якщо індекс існуючого елемента, то повертаємо значення по індексу з масиву
}

void setValueAtIndex(DynamicIntArray *anArray, int anValue, int anIndex)
{
	if (anIndex<anArray->physicalSize && anArray->physicalSize > anArray->logicalSize)//перевіряємо чи потрапили ми в масив
	{
		anArray->storage[anIndex] = anValue;//поміщаємо на потрібний індекс елемент
		anArray->logicalSize++;//збільшуємо логічний розмір
	}
	else//якщо не потрапили в масив
	{
		anArray->storage = (int *)realloc(anArray->storage,2 * anIndex*sizeof(int));//виділяємо новий блок пам'яті із вказівником на старий і новим розміром
		anArray->storage[anIndex] = anValue;
		anArray->logicalSize++;//збільшуємо логічий розмір 
		anArray->physicalSize = anIndex * 2;//збільшуєм фізичний розмір
	}
}