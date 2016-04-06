/*Copyright (c), 2016, Mahnyov Aleksander. All rights reserved*/

#ifndef TWINLINKLIST_H_INCLUDED
#define TWINLINKLIST_H_INCLUDED

#include "twinLinkNode.h"

typedef struct charListTag charList;
typedef struct charListTag{
    charNode *left;
    charNode *right;
    int numOfNodes;
}charList;

charList *charListConstructor(); //create/destroy interface
void charListDestructor(charList *listToBeDeleted);

charNode *addNode(charList *inputList, charNode *newNode);

charNode *charNodeAtIndex(const charList *aList, int anIndex);

void printCharList(const charList *inputList);

charNode *findMaxNode(const charList *inputList);
charNode *findMinNode(const charList *inputList);

charNode *removeCharNodeAtIndex(charList *aList, int anIndex);
charNode *insertCharNodeAtIndex(charList *aList, charNode *aNewNode, int anIndex);

void arrangeCharList(charList *inputList);

charList *swapList(charList *inputList);

int checkIfSim(const charList *inputList);
#endif // TWINLINKLIST_H_INCLUDED
