//
//  SingleList.h
//  List Laba2
//
//  Created by Tsymbal Olexandr on 19/05/16.
//  Copyright © 2016 OlTsymbal. All rights reserved.
//
#ifndef SingleLIST_h
#define SingleLIST_h

#include <stdio.h>

// Predeclaration
typedef struct __MyNode MyNode;

typedef struct _MyList//declaration the struct 
{
	MyNode *top;// pointer to top of list
	MyNode *bottom;//pointer to bottom of list 
	int count;// number elements in list
}MyList;

MyList *CreateANewList();
void FreeMyList(MyList *aList);

MyNode *AddNode(MyList *aList, MyNode *NewNode);
int ListCounter(const MyList *aList);
MyNode *NodeAtIndex(const MyList *aList, int count);
MyNode *InsertNode(MyList *aList, MyNode *NewNode, int index);
MyNode *DeletedNode(MyList *aList, int index);

#endif

