/*Copyright (c), 2016, Mahnyov Aleksander. All rights reserved*/

#include <stdlib.h>
#include "twinLinkList.h"
#include "twinLinkNode.h"

charList *charListConstructor();
void charListDestructor(charList *listToBeDeleted);
void printCharList(const charList *inputList);
int findMaxNode(const charList *inputList);
int findMinNode(const charList *inputList);
charNode *addNode(charList *inputList, charNode *newNode);
charNode *removeCharNodeAtIndex(charList *aList, int anIndex);
charNode *insertCharNodeAtIndex(charList *aList, charNode *aNewNode, int anIndex);

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
        newNode->prevNode = NULL;
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

charNode *charNodeAtIndex(const charList *aList, int anIndex){
	charNode *theResult = NULL;
	if (NULL != aList && anIndex < aList->numOfNodes){
		int i = 0;
		charNode *theNode = aList->left;
		do{
			if (i == anIndex){ //<!- index was found
				theResult = theNode; //<! - our node
				break;
			}

			i++; // increase index
			theNode = theNode->nextNode; //<! - go to next node

		} while (NULL != theNode);
	}
	return theResult;
}

void printCharList(const charList *inputList){
	for (int i = 0; i < inputList->numOfNodes; i++){
		charNode *theNode = charNodeAtIndex(inputList, i);
		if (NULL != theNode){
			printf("node[%d].value = %c\n", i, theNode->letter);
		}
	}
}

//it is pretty self-documentary, but it goes through the list and finds the maximum one
//by comparing currentNode and updatable maxNode by ASCII table
int findMaxNode(const charList *inputList){
    charNode *currentNode = inputList->left;
    charNode *maxNode = currentNode;
    int index = 0;
    int indexOfMaxNode = 0;
    do{
        if(currentNode->letter > maxNode->letter){
            maxNode = currentNode;
            indexOfMaxNode = index;
        }
        currentNode = currentNode->nextNode;
        index++;
    }while(NULL != currentNode);
    return indexOfMaxNode;
}

//the same stuff for minNode
int findMinNode(const charList *inputList){
    charNode *currentNode = inputList->left;
    charNode *minNode = currentNode;
    int index = 0;
    int indexOfMinNode = 0;
    do{
        if(currentNode->letter < minNode->letter){
            minNode = currentNode;
            indexOfMinNode = index;
        }
        currentNode = currentNode->nextNode;
        index++;
    }while(NULL != currentNode);
    return indexOfMinNode;
}

charList *swapList(charList *inputList){
    int minNodeIndex = findMinNode(inputList);
    int maxNodeIndex = findMaxNode(inputList);

    charNode *minNode = charNodeAtIndex(inputList, minNodeIndex);
    charNode *maxNode = charNodeAtIndex(inputList, maxNodeIndex);
    if(minNodeIndex > maxNodeIndex){
        removeCharNodeAtIndex(inputList, minNodeIndex);
        removeCharNodeAtIndex(inputList, maxNodeIndex);

        insertCharNodeAtIndex(inputList, minNode, maxNodeIndex);
        insertCharNodeAtIndex(inputList, maxNode, minNodeIndex);
    }else{
        removeCharNodeAtIndex(inputList, maxNodeIndex);
        removeCharNodeAtIndex(inputList, minNodeIndex);
        printf("Index of min is %d, max %d \n", minNodeIndex, maxNodeIndex);
        //insertCharNodeAtIndex(inputList, maxNode, minNodeIndex);
        //insertCharNodeAtIndex(inputList, minNode, maxNodeIndex);
    }
    return inputList;
}

//fully copied from my homework, yes
charNode *insertCharNodeAtIndex(charList *aList, charNode *aNewNode, int anIndex){

    if (NULL == aList || NULL == aNewNode){ //"list vaild" check
		return NULL;
	}

    if (NULL == aList->left && NULL == aList->right && anIndex == 0){
		//The list is empty
		aList->left = aList->right = aNewNode;
	}else{
        charNode *theNode = charNodeAtIndex(aList, anIndex); //find a node with a given index
        if(NULL == theNode->prevNode){
            aList->left = aNewNode;
            aNewNode->nextNode = theNode;
            theNode->prevNode = aNewNode;
        }else{
            if(NULL == theNode->nextNode){ //if we are inserting aNewNode to the end of the list, edit list.tail
                aList->right = theNode;
                charNode *aPrevNode = theNode->prevNode;
                aPrevNode->nextNode = aNewNode;
                aNewNode->prevNode = aPrevNode;
                aNewNode->nextNode = theNode;
                theNode->prevNode = aNewNode;
            } else {
                    charNode *aPrevNode = theNode->prevNode;
                    aPrevNode->nextNode = aNewNode;
                    theNode->prevNode = aNewNode;
                    aNewNode->nextNode = theNode;
                    aNewNode->prevNode = aPrevNode;
                }
            }
        }

    aList->numOfNodes++; //so other functions would not freak out
    return aNewNode;
}

charNode *removeCharNodeAtIndex(charList *aList, int anIndex){
    if(anIndex < aList->numOfNodes){
        charNode *theNode = charNodeAtIndex(aList, anIndex); //find a node with a given index
        if(aList->right==theNode) aList->right=theNode->prevNode;
        else if(aList->left==theNode) aList->left=theNode->nextNode;
        else {
            charNode *aNextNode = theNode->nextNode; //remember the next node
            charNode *aPrevNode = theNode->prevNode; //and the previous one
            aPrevNode->nextNode=aNextNode; //skip theNode
            aNextNode->prevNode=aPrevNode;
        }
        aList->numOfNodes -= 1;

        return theNode;
    }
}
