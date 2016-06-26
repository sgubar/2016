#include "SingleLinkedNode.h"
#include "SingleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

IntList *SLCreateList() // функция создания списка
{
	IntList* list = (IntList*) malloc(sizeof (IntList)); 
	list->head = NULL; 
	list->tail = NULL;
	list->count = 0; 
	return list; 
}

int SLCountList(const IntList *aList) // фунуция возвращает число элементов списка
{
	return aList->count; 
}

IntNode *SLAddNode(IntList *aList, IntNode *aNewNode) 
//функция добавляет ноду в хвост списка
{
	if (aList->count == 0)  
	{
		aList->head = aNewNode; 
	}
	else 
	{
		aList->tail->nextNode = aNewNode; 
	}
	aList->tail = aNewNode; // в качестве хвоста списка обозначаем эту 
	// свежодобавленную ноду
	aList->count++; 
	return aNewNode; //возвращаем свежодобавленную ноду
}

void SLFreeList(IntList *aList) // чистим память под список
{
	while(aList->head != aList->tail) // пока не останеться только один элемент
	{
		IntNode *node = aList->head->nextNode; //записываем второй элемент
		SLFreeIntNode(aList->head); //удаляем первый
		aList->head = node; //обозначаем ранее записаный второй как первый
	}
	free(aList->head); //удаляем последний оставшийся элемент
	free(aList); //удаляем сам список
}

IntNode *SLNodeAtIndex(const IntList *aList, int aIndex) // функция вывода элемента по номеру элемента 
{
	if (aList->count-1 < aIndex || aIndex<0)
	//если число элементов списка меньше номера запрошенного элемента
	// или aIndex меньше нуля
	{
		return NULL;  	
	
	}
	else // ищем элемент
	{
		IntNode *node = aList->head; // временная нода, пока записываем туда голову списка
		int k = 0; 
		// временная переменная, при помощи которой мы будем перебирать элементы списка
		while (k < aIndex) // пока не доберемся до aIndex-го элемента
		{
			if (node->nextNode != NULL) 
			// если в нашей временной переменной node записан не последний элемент списка
			{
				node = node->nextNode; // то записываем в эту переменную следуюший элемент
				k++; 
				// инкрементируем k 
			}
			else 
			{
				return NULL; 
			}
		}
		return node; //раз мы попали в эту строчку, çзначит мы добрались до aIndex-го элемента
		//и его мы возвращаем
	}
}



IntNode *SLInsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex) 
// функция для вставки ноды на определенное место 
{
	if(aList->count <= anIndex) 
	{
		//добавляем в хвост 
		SLAddNode(aList, aNewNode);
	}
	else if (anIndex == 0) // элементы есть, но надо добавить в голову
	{
		IntNode *theHeadNode = aList->head;  
		aList->head = aNewNode; 
		aList->head->nextNode = theHeadNode; 
	}
	else if (anIndex < 0) // некоректный номер
	{
		// ничего не добавляем.
		return NULL;
	}
	else 
	{
		IntNode *thePreviousNode = SLNodeAtIndex(aList, anIndex-1);
		// находим ноду которая занимает предыдущее место перед интересующим нас местом
		
		IntNode *theNextNode = SLNodeAtIndex(aList, anIndex);
		// находим ноду которая занимает интересующим нас место

		thePreviousNode->nextNode = aNewNode; // к предыдущей ноды подцепляем добавленную ноду
		aNewNode->nextNode = theNextNode; 

	}
	aList->count++; 
	return aNewNode; // возвращаем свежодобавленную ноду
}



IntNode *SLRemovedNodeAtIndex(IntList *aList, int anIndex) // фунуция удаления ноды по номеру
{
	if (anIndex < 0) // некорректный номер
	{
		// ничего не удаляем
		return NULL;
	}
	else if(aList->count < anIndex || aList->count == 0) // если элементов в списке меньше, чем номер элемента который нужно удалить
	{
		// ничего не удаляем
		return NULL;
	}
	else if (anIndex == 0) // нужно удалить голову
	{
		IntNode *theHeadNode = aList->head; //находим первую ноду 
		if (aList->count == 1) // если у нас всего одна нода
		{
			aList->head = NULL; //опустошаем список, удаляя тем самым единственную ноду.
			aList->tail = NULL;
			aList->count = 0;
		}
		else
		{
			aList->head = theHeadNode->nextNode; // вместо головы устанавливаем вторую ноду
			aList->count--; 
		}
		return theHeadNode; //возвращаем только что удаленную ноду-голову
	}
	else if(aList->count == anIndex )
	// хотим удалить хвост и у нас больше одного элемента
	{
		IntNode *thePreviousNode = SLNodeAtIndex(aList, anIndex-1);
		// находим ноду которая занимает предыдущее место перед интересующим нас местом
		
		thePreviousNode->nextNode = NULL; // после нее ничего.
		aList->tail = thePreviousNode; // теперь предыдущая нода обозначена как хвост списка.
		aList->count--;// элементов стало меньше на один
	}
	else 
	{
		IntNode *thePreviousNode = SLNodeAtIndex(aList, anIndex-1);
		// находи ноду которая занимает предыдущее место перед интересующим нас местом
		
		IntNode *theNode = SLNodeAtIndex(aList, anIndex);
		// находим ноду которая занимает интересующим нас место
		
		IntNode *theNextNode = SLNodeAtIndex(aList, anIndex+1);
		//  находим ноду которая занимает слудующее за интересующим нас местом

		thePreviousNode->nextNode = theNextNode; // к предыдущей ноды подцепляем слкдующую ноду
		return theNode; //возвращаем только что удаленную ноду
	}
}
