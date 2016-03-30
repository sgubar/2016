/*Copyright (c), 2016, Mahnyov Aleksander. All rights reserved*/

#include <stdlib.h>
#include "twinLinkList.h"
#include "twinLinkNode.h"

charList *charListConstructor();
void charListDestructor(charList *listToBeDeleted);
void printCharList(const charList *inputList);
charNode *findMaxNode(const charList *inputList);
charNode *findMinNode(const charList *inputList);
charNode *addNode(charList *inputList, charNode *newNode);
charNode *removeCharNodeAtIndex(charList *aList, int anIndex);
charNode *insertCharNodeAtIndex(charList *aList, charNode *aNewNode, int anIndex);
charList *swapList(charList *inputList);
charList *arrangeCharList(charList *inputList);
int maxNodeIndex(const charList *inputList);

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
charNode *findMaxNode(const charList *inputList){
    charNode *currentNode = inputList->left;
    charNode *maxNode = currentNode;
    do{
        if(currentNode->letter > maxNode->letter){
            maxNode = currentNode;
        }
        currentNode = currentNode->nextNode;
    }while(NULL != currentNode);
    return maxNode;
}

int maxNodeIndex(const charList *inputList){
    charNode *currentNode = inputList->left;
    charNode *maxNode = currentNode;
    int maxIndex = 0;
    int i = 0;
    do{
        if(currentNode->letter > maxNode->letter){
            maxNode = currentNode;
            maxIndex = i;
        }
        i++;
        currentNode = currentNode->nextNode;
    }while(NULL != currentNode);
    return maxIndex;
}

//the same stuff for minNode
charNode *findMinNode(const charList *inputList){
    charNode *currentNode = inputList->left;
    charNode *minNode = currentNode;
    do{
        if(currentNode->letter < minNode->letter){
            minNode = currentNode;
        }
        currentNode = currentNode->nextNode;
    }while(NULL != currentNode);
    return minNode;
}

charList *swapList(charList *inputList){
    charNode *minNode = findMinNode(inputList);
    charNode *maxNode = findMaxNode(inputList);
    char minLetter = minNode->letter;
    minNode->letter=maxNode->letter;
    maxNode->letter=minLetter;
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
        aList->numOfNodes--;

        return theNode;
    }
}

charList *arrangeCharList(charList *inputList){
    charList *arrangedList = charListConstructor();
    charNode *maxNode = NULL;
    do{
    maxNode = findMaxNode(inputList);
    addNode(arrangedList, maxNode);
    removeCharNodeAtIndex(inputList, maxNodeIndex(inputList));
    }while(inputList->numOfNodes>0);
    return arrangedList;
}
