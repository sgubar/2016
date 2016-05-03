#include <stdio.h>

#include "SingleLIST.h"
#include "SingleNODE.h"

MyList *CreateANewList()
{
	MyList *TheList = (MyList *)malloc(sizeof(MyList));

	TheList->top = NULL;
	TheList->bottom = NULL;
	TheList->count = 0;

	return (TheList);
}

void FreeMyList(MyList *aList)
{
	if (NULL==aList)
	{
		return;
	}
	MyNode *theNode = aList->top;
	while (theNode != NULL)
	{
		MyNode *NodeWillBeFree = theNode;
		theNode = theNode->nextNode;
		free(NodeWillBeFree);
	}
	free(aList);
}

MyNode *AddNode(MyList *aList, MyNode *NewNode)
{
	if (NULL == aList || NULL == NewNode) { return NULL; }
	if (NULL == aList->top && NULL == aList->bottom)
	{
		aList->top = aList->bottom = NewNode;
	}
	else
	{
		MyNode *Bottom = aList->bottom;
		aList->bottom = NewNode;
		if (NULL != Bottom)
		{
			Bottom->nextNode = aList->bottom;
		}
	}
	aList->count += 1;
	return (NewNode);
}

int ListCounter(const MyList *aList)
{
	int Result = 0;
	if (NULL != aList)
	{
		Result = aList->count;
	}
	else { return NULL; }
	return Result;
}

MyNode *NodeAtIndex(const MyList *aList, int count)
{
	MyNode *TheResult = NULL;
	if (NULL != aList && count <= aList->count)
	{
		int i = 0;
		MyNode *TheNode = aList->top;
		do
		{
			if (i == count)
			{
				TheResult = TheNode;
				break;
			}
			i++;
			TheNode = TheNode->nextNode;
		}while (NULL != TheNode);
		
	}
	return TheResult;
}

MyNode *InsertNode(MyList *aList, MyNode *NewNode, int index)
{
	if(NULL==aList || NULL==NewNode || index>aList->count+1)
	{
		return NULL;
	}
	else
	{
		if (NULL != aList &&  index < aList->count+1)
		{
			if (index == 0)
			{
				NewNode->nextNode = aList->top;
				aList->top = NewNode;
				aList->count += 1;
				return (NewNode);
			}
			if (index == aList->count + 1)
			{
				aList->bottom = NewNode;
				NewNode->nextNode = aList->bottom;
				return (NewNode);
			}
			else
			{
				MyNode *previousNode = NodeAtIndex(aList, index - 1);
				NewNode->nextNode = previousNode->nextNode;
				previousNode->nextNode = NewNode;
				aList->count += 1;
				return (NewNode);
			}
		}
	}
}

MyNode *DeletedNode(MyList *aList, int index)
{
	if(NULL==aList || index>aList->count)
	{
		return NULL;
	}
	if (NULL != aList && index <= aList->count)
	{
		MyNode *removNode = NodeAtIndex(aList, index);
		if (index == 0)
		{
			aList->top = removNode->nextNode;
			FreeMyNode(removNode);
			aList->count -= 1;
			return aList;
		}
		else
		{
			MyNode *PreviousNode = NodeAtIndex(aList, index - 1);
			PreviousNode->nextNode = removNode->nextNode;
			FreeMyNode(removNode);
			aList->count -= 1;
			return aList;
		}
	}
}