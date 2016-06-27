/* 
 * File:   List.h
 * Author: Ruslan Kucherenko
 *
 * Created on 1 червня 2016, 1:21
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

int Interface();

void DeleteSimilar(List* theList);


#endif


