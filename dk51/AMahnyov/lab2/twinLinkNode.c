#include "twinLinkNode.h"
#include <stdio.h>
#include <stdlib.h>

charNode *createCharNode(char aChar);

charNode *createCharNode(char aChar){
    charNode *returnNode = (charNode *)malloc(sizeof(charNode));
    //creates a linkless char node
    returnNode->letter=aChar;
    returnNode->prevNode=NULL;
    returnNode->nextNode=NULL;
    return returnNode;
}

void freeCharNode(charNode *theNode){
    if(NULL != theNode){ //if the node is valid
        free(theNode); //kill a node
    }
}
