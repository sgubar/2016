

/* 
 * File:   List.h
 * Author: Dmitry Sakharov
 *
 * Created on 10 квітня 2016, 2:51
 */

#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include<stdlib.h>
#include "Node.h"

typedef struct List List;
struct List
{
    Node* tail;
    Node* head;
   int elements;
};

List* CreateList();

Node* AddNode(List* theList,Node* theNewNode);

void PrintList(List* theList);

void MinMaxSwap(List* theList);

List* DelNodeWithValue(List* theList,int value);

void SortList(List* theList);

Node* SortListAfterMinNode(List* theList);

Node* CopyValue(List* theList,int value);

int Face();


List* AdvancedListMode(List* theList);
List* SaveToFile(List* theList);
List* LoadFromFile();


#endif


