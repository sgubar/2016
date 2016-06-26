#include <stdio.h>
#include "SingleLinkedNode.h"
#include "SingleLinkedList.h"

void doTestSLList(); // объявление функции
void doPrintSLList(const IntList *aList); 

int main(int argc, const char * argv[]) 
{ 
	doTestSLList(); // вызов функции

	return 0;
}

void doTestSLList() // реализация функции
{
	printf("Start to demo a single-linked list ...\n");
	
	
	IntNode *theNode2 = SLCreateNodeWithIntValue(2); 
	IntNode *theNode4 = SLCreateNodeWithIntValue(4);
	
	IntList *theList = SLCreateList(); //создание листа
	printf("number of elements: %d\n", SLCountList(theList));
	// выводим число элементов
	
	SLAddNode(theList, theNode2); // добавление ноды в лист
	printf("number of elements: %d\n", SLCountList(theList));


	SLAddNode(theList, theNode4);
	
	
	printf("number of elements: %d\n", SLCountList(theList));

	
	doPrintSLList(theList);
	
	
	SLFreeList(theList); 
	
	printf("Done.\n");
}

void doPrintSLList(const IntList *aList) // функция печати списка
{
	for (int i = 0; i < SLCountList(aList); i++) 
	{
		IntNode *theNode = SLNodeAtIndex(aList, i); 
		//находим ноду которая по номеру соответствует значению i
		if (NULL != theNode) 
		//если эта нода не пуста
		{
			printf("node[%d].value = %d\n", i, theNode->value); 
			//выводим эту ноду на экран
		}
	}
}
