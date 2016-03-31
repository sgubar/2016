/*Copyright (c), 2016, Mahnyov Aleksander. All rights reserved*/

#include <stdlib.h>
#include <string.h>
#include "twinLinkList.h"
#include "twinLinkNode.h"

charList *charListConstructor();
void charListDestructor(charList *listToBeDeleted);
void printCharList(const charList *inputList);
charNode *findMaxNode(const charList *inputList);
charNode *findMinNode(const charList *inputList);
charNode *ignoredMax(const charList *inputList, const int ignorance);
charNode *addNode(charList *inputList, charNode *newNode);
charNode *removeCharNodeAtIndex(charList *aList, int anIndex);
charNode *insertCharNodeAtIndex(charList *aList, charNode *aNewNode, int anIndex);
charList *swapList(charList *inputList);
void arrangeCharList(charList *inputList);

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
//        charNode *rightNode = inputList->right; //save the right node
//        inputList->right = newNode; //now the right node of the list is our new node
//        if(NULL != rightNode){
//            rightNode->nextNode = newNode; //old right node should link to the new right node
//            newNode->prevNode = rightNode; //new right node should back-link to the old right node
//        }
				newNode->prevNode = inputList->right;
				inputList->right->nextNode = newNode; //<! - in it place right != NULL
				inputList->right = newNode;
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

void printCharList(const charList *inputList)
{
	charNode *theNode = inputList->left;
	int i = 0;
	
	while (NULL != theNode)
	{
		printf("node[%d].value = %c\n", i, theNode->letter);
		theNode = theNode->nextNode;
		i ++;
	}
	
//	for (int i = 0; i < inputList->numOfNodes; i++){
//		charNode *theNode = charNodeAtIndex(inputList, i);
//		if (NULL != theNode){
//			printf("node[%d].value = %c\n", i, theNode->letter);
//		}
//	}
}

//it is pretty self-documentary, but it goes through the list and finds the maximum one
//by comparing currentNode and updatable maxNode by ASCII table
charNode *findMaxNode(const charList *inputList){
    charNode *currentNode = inputList->left;
    charNode *maxNode = currentNode;
    do{
        if(currentNode->letter >= maxNode->letter){
            maxNode = currentNode;
        }
        currentNode = currentNode->nextNode;
    }while(NULL != currentNode);
    return maxNode;
}

charNode *ignoredMax(const charList *inputList, const int ignorance){
    charNode *currentNode = charNodeAtIndex(inputList, ignorance);
    charNode *maxNode = currentNode;
    do{
        if(currentNode->letter >= maxNode->letter){
            maxNode = currentNode;
        }
        currentNode = currentNode->nextNode;
    }while(NULL != currentNode);
    return maxNode;
}

//the same stuff for minNode
charNode *findMinNode(const charList *inputList){
    charNode *currentNode = inputList->left;
    charNode *minNode = currentNode;
    do{
        if(currentNode->letter <= minNode->letter){
            minNode = currentNode;
        }
        currentNode = currentNode->nextNode;
    }while(NULL != currentNode);
    return minNode;
}

charList *swapList(charList *inputList){
    charNode *minNode = findMinNode(inputList); //i use this, not do-while cycle for sake of simplicity
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
        if(NULL == theNode->prevNode){ //the node is at 0 index
            aList->left = aNewNode;
            aNewNode->nextNode = theNode;
            theNode->prevNode = aNewNode;
        }else{
            if(NULL == theNode->nextNode){ //if we are inserting aNewNode to the end of the list
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
        if(aList->right==theNode){
            aList->right=theNode->prevNode;
            theNode->nextNode = NULL;
        }
        else if(aList->left==theNode){
            aList->left=theNode->nextNode;
            theNode->prevNode=NULL;
        }
        else {
            charNode *aNextNode = theNode->nextNode; //remember the next node
            charNode *aPrevNode = theNode->prevNode; //and the previous one
            aPrevNode->nextNode=aNextNode; //skip theNode
            aNextNode->prevNode=aPrevNode; //backlink
        }
        aList->numOfNodes--;

        return theNode;
    }
	
	return NULL;
}

void arrangeCharList(charList *inputList)
{
	// Do simple sorting
	charNode *theNode = inputList->left; //<!- seems like 'left' is head
	
	while (NULL != theNode)
	{
		charNode *theSubNode = theNode->nextNode;
	
		while (NULL != theSubNode)
		{
			if (theNode->letter > theSubNode->letter)
			{
				//swap nodes
				//1. Swap pointers
			
				charNode *theTmpNode = theNode;
				if (NULL != theNode->prevNode)
				{
					theNode->prevNode->nextNode = theSubNode;
				}
				else
				{
					//the border case: update head
					inputList->left = theSubNode;
				}
			
				if (NULL != theSubNode->nextNode)
				{
					theSubNode->nextNode->prevNode = theNode;
				}
				else
				{
					//the border case: update tail.
					inputList->right = theNode;
				}
			
				charNode *theTmpNext = theNode->nextNode;
				charNode *theTmpPrev = theNode->prevNode;
			
				theNode->nextNode = theSubNode->nextNode;
				theNode->prevNode = (theNode != theSubNode->prevNode) ? theSubNode->prevNode : theSubNode;
			
				theSubNode->nextNode = (theSubNode != theTmpNext) ? theTmpNext : theNode;
				theSubNode->prevNode = theTmpPrev;
			
				//3. Corrected local variables
				theTmpNode = theNode;
				theNode = theSubNode;
				theSubNode = theTmpNode;
			}
		
			theSubNode = theSubNode->nextNode;
		}
	
		theNode = theNode->nextNode;
	}
	
}
// 3/31 - DK51.LR2.Mahnyov_Aleksander
