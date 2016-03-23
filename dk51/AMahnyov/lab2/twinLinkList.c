#include <stdlib.h>
#include "twinLinkList.h"
#include "twinLinkNode.h"

charList *charListConstructor();
void charListDestructor(charList *listToBeDeleted);

charList *charListConstructor(){
    charList *newList = (charList *)malloc(sizeof(charList)); //memory allocation (!malloc returns a pointer!)
    //whipe out the data
    newList->left = NULL;
    newList->right = NULL;
    newList->numOfNodes = 0;
    //return created list
    return newList;
}

void charListDestructor(charList *listToBeDeleted){
    if(NULL == listToBeDeleted){
        //invalid list!
        return;
    }
    charNode *currentNode = listToBeDeleted->left; //starting node
    while(NULL != currentNode){ //kill all of the nodes
        charNode *deletionNode = currentNode; //remeber the current node
        currentNode = currentNode->nextNode;  //move to the next node
        free(deletionNode);
    }
    free(listToBeDeleted); //kill the list
}

//add the node to the right side of the list

charNode *addNode(charList *inputList, charNode *newNode){
    if (NULL == newNode || NULL == inputList){
        return NULL; //valid parameters check
	}
    if(NULL == inputList->left && NULL == inputList->right){
        inputList->left = inputList->right = newNode; //in case the input list is empty
        newNode->prevNode = inputList->left;
    }else{
        charNode *rightNode = inputList->right; //save the right node
        inputList->right = newNode; //now the right node of the list is our new node
        if(NULL != rightNode){
            rightNode->nextNode = inputList->right; //old right node should link to the new right node
            newNode->prevNode = rightNode; //new right node should back-link to the old right node
        }
    }
    inputList->numOfNodes++;
    return newNode;
}

