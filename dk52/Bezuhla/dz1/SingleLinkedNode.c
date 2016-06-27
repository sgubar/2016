#include "SingleLinkedNode.h"
#include "SingleLinkedList.h"

IntNode *SLCreateNodeWithIntValue(int aValue) 
// создаем ноду
{
	IntNode* node = (IntNode*) malloc(sizeof (IntNode));
	// выделяем ей память
	
	node->value = aValue; // записываем в нее значение
	node->nextNode = NULL; 
	return node; // возвращает эту ноду
}

void SLFreeIntNode(IntNode *aNode)
{
	if(aNode != NULL) // если память под нее выделена
	{
		free(aNode); //чистим память отведенную под ноду
	}
}
