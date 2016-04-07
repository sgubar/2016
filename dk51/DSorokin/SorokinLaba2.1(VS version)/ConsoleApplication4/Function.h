//
//  Function.h
//  Lab2
//
//  Created by Sorokin Dmytro on 4/7/16.
//  Copyright (C) 2016 Sorokin Dmytro. All rights reserved.
//



#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

typedef struct __IntNode IntNode;
struct __IntNode
{
	int value;
	IntNode *nextNode;
};

IntNode *CreateN(int perevod);
void FreeIntNode(IntNode *aNode);
void selectionSort(IntNode *theList,int IndexMin,int IndexMax);
int doFindIndexMax(IntNode *theList);
int doFindIndexMin(IntNode *theList);
void insertionSort(IntNode *theList, int count);
#endif // FUNCTION_H_INCLUDED
