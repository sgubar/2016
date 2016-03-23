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
//int countCharList(charList *inputList);

//charList arrangeCharList(charList *inputList);

//charList swapList(charList *inputList);

#endif // TWINLINKLIST_H_INCLUDED
