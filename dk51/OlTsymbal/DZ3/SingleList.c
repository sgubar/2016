//
//  SingleList.c
//  List Laba2
//
//  Created by Tsymbal Olexandr on 19/05/16.
//  Copyright © 2016 OlTsymbal. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SingleLIST.h"
#include "SingleNODE.h"

MyList *CreateANewList() //creat a new list 
{
	MyList *TheList = (MyList *)malloc(sizeof(MyList));//

	TheList->top = NULL;//initialization the top of list as Null
	TheList->bottom = NULL;//initialization the bottom of list as Null
	TheList->count = 0;//initialization the number of elements of list as Null

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
			if (i == count) // index found
			{
				TheResult = TheNode;// our Node
				break;
			}
			i++;// increas index
			TheNode = TheNode->nextNode;// go to the next Node
		}while (NULL != TheNode);// while we have Node which isn`t Null
		
	}
	return TheResult;
}

MyNode *InsertNode(MyList *aList, MyNode *NewNode, int index)
{
	if(NULL==aList || NULL==NewNode || index>aList->count+1)//if no List or no Node or index of Node overval
	{
		return NULL;
	}
	else
	{
		if (NULL != aList &&  index < aList->count+1)
		{
			if (index == 0)//if index 0 we insert our node on top of list
			{
				NewNode->nextNode = aList->top;
				aList->top = NewNode;
				aList->count += 1;
				return (NewNode);
			}
			if (index == aList->count + 1)//if index > number of element of list we insert our node on bottom of List
			{
				aList->bottom = NewNode;
				NewNode->nextNode = aList->bottom;
				aList->count += 1;
				return (NewNode);
			}
			else
			{
				MyNode *previousNode = NodeAtIndex(aList, index - 1);//found previous node
				NewNode->nextNode = previousNode->nextNode;//link of new node to next node = link of previous node to next node
				previousNode->nextNode = NewNode;//link of previous node = new node
				aList->count += 1;//increas a count a number of element
				return (NewNode);
			}
		}
	}
}

MyNode *DeletedNode(MyList *aList, int index)
{
	if(NULL==aList || index>aList->count)//if there are no list or index overval we don`t doing anythyng
	{
		return NULL;
	}
	if (NULL != aList && index <= aList->count)
	{
		MyNode *removNode = NodeAtIndex(aList, index);//find a node 
		if (index == 0)// if this node is first in list
		{
			aList->top = removNode->nextNode;//a top of list is next node
			FreeMyNode(removNode);
			aList->count -= 1;//decreas a count a number of elements
			return aList;
		}
		else
		{
			MyNode *PreviousNode = NodeAtIndex(aList, index - 1);//find previous node
			PreviousNode->nextNode = removNode->nextNode;//link of prevnode to next node = link remov node ro next node
			FreeMyNode(removNode);
			aList->count -= 1;
			return aList;
		}
	}
}

MyNode *FindMinNode(const MyList *inList)//find min node of number of symbols in node
{
	MyNode *aCurrentNode = inList->top;
	MyNode *aMinNode = aCurrentNode;
	do
	{
		if (strlen(aCurrentNode->value) <= strlen(aMinNode->value))
		{
			aMinNode = aCurrentNode;
		}
		aCurrentNode = aCurrentNode->nextNode;
	} while (NULL != aCurrentNode);
	return aMinNode;
}

MyNode *FindMaxNode(const MyList *inList)
{
	MyNode *aCurrentNode = inList->top;
	MyNode *aMaxNode = aCurrentNode;
	do
	{
		if (strlen(aCurrentNode->value) >= strlen(aMaxNode->value))
		{
			aMaxNode = aCurrentNode;
		}
		aCurrentNode = aCurrentNode->nextNode;
	} while (NULL != aCurrentNode);
	return aMaxNode;
}

MyList *SwapNodeInList(const MyList *inputList)
{
	MyNode *aMinNode = FindMinNode(inputList);
	MyNode *aMaxNode = FindMaxNode(inputList);
	char *aMinValue = aMinNode->value;
	aMinNode->value = aMaxNode->value;
	aMaxNode->value = aMinValue;
	return inputList;
}

MyList *SortingList(const MyList *theInList)
{
	if (theInList->count == 1)
	{
		return theInList;
	}
	if (theInList->count > 1)
	{
		for (int theOut = 0; theOut < ListCounter(theInList); theOut++)
		{
			for (int theIn = (ListCounter(theInList) - 1); theIn > theOut; theIn--)
			{
				if (strlen(NodeAtIndex(theInList, theIn)->value) <= strlen(NodeAtIndex(theInList, theIn - 1)->value))
				{
					MyNode *theTmp = NodeAtIndex(theInList, theIn);
					MyNode *thePrev = NodeAtIndex(theInList, theIn - 1);
					char *theValue = theTmp->value;
					theTmp->value = thePrev->value;
					thePrev->value = theValue;
				}
			}
		}
		return theInList;
	}
}

MyList *SelectionSorting(const MyList *inList)
{
	MyNode *aMinNode = inList->top;
	int count = ListCounter(inList);
	for (int i = 0; i < count - 1; i++)
	{
		MyNode *aNextNode = aMinNode->nextNode;
		/*for (aNextNode; aNextNode->nextNode != NULL; aNextNode = aNextNode->nextNode)*/
		do
		{
			if (strlen(aNextNode->value) <= strlen(aMinNode->value))
			{
				char *theValue = aMinNode->value;
				aMinNode->value = aNextNode->value;
				aNextNode->value = theValue;
			}
		aNextNode = aNextNode->nextNode;
		}while (aNextNode!=NULL);
		
		aMinNode = aMinNode->nextNode;
	}
return inList; 
}

MyList *DeleteKey(const MyList *theList, char *key)
{
	int result = 0;
	for (int i = 0; i < theList->count; i++)
	{
		MyNode *theNode = NodeAtIndex(theList, i);
		int len = strlen(theNode->value);
		char *nodeValue;
		nodeValue = malloc((len + 1)*sizeof(char));
		memset(nodeValue, 0, len + 1);
		nodeValue=theNode->value;
		if (*key == *nodeValue)
		{
			DeletedNode(theList, i);
		}
	}
	return theList;
}

void LatterCount(const MyList *inList)
{
	char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char letterCount[27];
	memset(letterCount, 0, 27);
	for (int i = 0; i < 26; i++)
	{
		for (int k = 0; k < inList->count; k++)
		{
			MyNode *aNode = NodeAtIndex(inList, k);
			int len = strlen(aNode->value);
			char *value;
			value = malloc((len + 1)*sizeof(char));
			memset(value, 0, len + 1);
			value = aNode->value;
			for (int n = 0; n < len; n++)
			{
				if (alphabet[i]==value[n] || alphabet[i+26] == value[n])
				{
					letterCount[i]++;
				}
			}
		}
		printf("A Latter [%c] was found [%d] times\n", alphabet[i], letterCount[i]);
	}
}
