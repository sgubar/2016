//
//  DynamicArray.c
//  
//  Created by Sorokin Dmytro on 5/05/16.
//  Copyright © 2016 Sorokin Dmytro. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"


DynamicIntArray *createDAInt(int aSize)//создаем дм
{
	DynamicIntArray *DynArray=(DynamicIntArray *)malloc(sizeof(DynamicIntArray));;//выделяем память размером структуры
	DynArray->physicalSize = aSize;//определяем физический размер (количесво ячеек) и помещаем значение в структуру
	DynArray->logicalSize = 0;//определяем логический размер (количество заполненых ячеек) и помещаем значение в структуру
	DynArray->storage = (int *)malloc(aSize * sizeof(int));//определяем размер начального масива
	for (int i=0; i < aSize; i++) DynArray->storage[i] = 0;//Заполняем "хранилище масива" 0
	return DynArray;
}

void freeDAInt(DynamicIntArray *anArray)//освобождаем память от масива
{
	free(anArray->storage);
	free(anArray);
}

int valueAtIndex(int anIndex, DynamicIntArray *anArray)//помещаем значение в ячейку по заданному индексу
{
	if (anIndex > anArray->physicalSize) return 0;//возвращаем 0 в случае выхода за граници масива
	int value;
	value = anArray->storage[anIndex];//помещаем значение по заданому индексу
	return value;
}


void setValueAtIndex(int anValue, int anIndex, DynamicIntArray *anArray)
{
	if (anIndex > anArray->physicalSize) //проверяем "поместились" ли мы в масив
	{
		//anArray->storage = (int *)realloc(anArray->storage, (anIndex+1)* 2 * sizeof(int));//выделяем новый блок памяти с укзанием на старый и размером его изменения
		//if (0 == anArray->storage[anIndex]) anArray->logicalSize += 1;// увеличиваем логический размер на 1 в случае если ячейка имеет значение 0
		//anArray->storage[anIndex] = anValue;//записываем значение в ячейку памяти 

		int aSize=anArray->physicalSize;
		int *NewStorage= (int *)malloc(anIndex * sizeof(int) * 2);
		anArray->physicalSize = anIndex*2;
		for (int j = 0; j <= aSize - 1; j++) {//Заполняем новое хранилище старыми элементами
			NewStorage[j] = anArray->storage[j];
		}
			
		free(anArray->storage);//Освобождаем старое хранилище
		for (int i = aSize; i < anArray->physicalSize -1; i++)//заполняем новые ячейки 0
			NewStorage[i] = 0;
		if (0 == anArray->storage[anIndex]) anArray->logicalSize += 1;// увеличиваем логический размер на 1 в случае если ячейка имеет значение 0
			NewStorage[anIndex] = anValue;//записываем значение в ячейку памяти 
			anArray->logicalSize += 1;
			anArray->storage = NewStorage;//Ссылаемся на новое хранилище
			}
	else//если попали в масив, то просто помещаем на нужный индекс элемент
	{
		anArray->storage[anIndex] = anValue;
		anArray->logicalSize += 1;
	}
}