#include<stdio.h>
#include<stdlib.h>
#include "List.h"
#include"Nodes.h"
#include "doublenodes.h"

List* CreateList()
{
    List* CreatedList =(List*)malloc(sizeof(List));
    CreatedList->head = NULL; /*there is no head or tail*/
    CreatedList->tail = NULL;
    CreatedList->elements=0;    
    return CreatedList;
}

Node* AddNode(List* theList, Node* theNewNode)
{
    if(theList==NULL || theNewNode==NULL)
        return NULL;
    
    else if(theList->head==NULL && theList->tail==NULL)/*list is empty*/
        theList->head=theList->tail=theNewNode;
    else
    {
        Node* lastNode = theList->tail;
        theList->tail=theNewNode;
        
        lastNode->next=theNewNode;
    }
    
    theList->elements++;
    
    theNewNode->next=NULL;
    
    return theNewNode;
}
void PrintList(List* theList)
{

	if (theList != NULL && theList->elements!=0) {

	
		int i = 1;
                Node *theNode = theList->head;
	
		do
		{
                    printf("Node#%d value=%d\n",i,theNode->value);
		
			i++; // increase index
			theNode = theNode->next; /* go to next node*/
		
		} while (theNode != NULL);
                
	}
	
        else
            printf("Error. List doesn't exist.\n");
}
void MinMaxSwap(List* theList)
{
if (NULL != theList)
	{
		
                Node* maxNode,*minNode,*theNode;
                theNode = maxNode= minNode= theList->head;
                
		do
		{
                    if(theNode->value > maxNode->value)
                        maxNode=theNode;
                    else if (theNode->value < minNode->value)
                        minNode=theNode;                        
                    
                    theNode = theNode->next; /*go to next node*/
		
		} while (NULL != theNode); /*swaping values of minimal and maximal elements*/
                int tempval=maxNode->value;
                maxNode->value=minNode->value;
                minNode->value=tempval;
	}
	
        else
            printf("Error.List doesn't exist\n");
}

List* DelNodeWithValue(List* theList,int val)
{    
 if (NULL != theList)
	{		
            Node* theNode=theList->head;
           
		do
		{
                    if (theNode==theList->head&&theNode==theList->tail&&theNode->value==val)/*one element at the list*/
                    {   
                        theList->head=theList->tail=NULL;
                        theList->elements=0;
                        break;
                    }
                    else if(theNode->next->value==val&&theNode->next==theList->tail)
                    {                     
                        
                        theNode->next=NULL; /*if node with a key is a tail of list*/
                        theList->tail=theNode;
                        theList->elements--;
                        break;
                    }  
                    else if (theNode==theList->head && theNode->value==val)/*if node with a key is a head of list*/
                    {  
                        theList->head=theNode->nextptr;
                        theList->elements--;
                        break;
                    }
                    
                    else if(theNode->next->value==val) /*if node with a key in the middle of list*/
                    {
                        theNode->next=theNode->next->next;
                        theList->elements--;
                        break;
                    }
                    
                    theNode = theNode->next; /*go to next node*/
                    if(theNode->next==NULL)
                    {
                        printf("Error. Element isn`t exist");
                       
                    }
		
		} while (theNode->next != NULL);
                  
                
               
                
	}
 return theList;
}

void SortList(List* theList) /*Bubblesort*/
{
    if(theList!=NULL)
    {
        int length=theList->elements, b=0;
        Node* theNode=theList->head;
        for (int i = 0; i < length-1; i++) {
            int  swapped = 0;
            theNode=theList->head;
            for (int j = 0; j < length-i-1; j++) {
             
             if (theNode->value > theNode->next->value) {
                  b = theNode->value; 
                 theNode->value = theNode->next->value;
                 theNode->next->value = b;
                 swapped = 1; 
             }
             theNode=theNode->next;
         }
         
         if(!swapped)
            break;
     }
    }
    else
        printf("Error. List doesn't exist.\n");
}

/*list for personal task*/
DList* CreateDList()
{
    DList* CreatedDList =(DList*)malloc(sizeof(DList));
    CreatedDList->head = NULL; /*there is no head or tail*/
    CreatedDList->tail = NULL;
    CreatedDList->elements=0;    
    return CreatedDList;
}

doubleNode* AddDNode(DList* theDList, doubleNode* aNewDNode)
{
    if(theDList==NULL || aNewDNode==NULL)
        return NULL;
    
    else if(theDList->head==NULL && theDList->tail==NULL)/*list is empty*/
        theDList->head=theDList->tail=aNewDNode;
    else
    {
        doubleNode* lastNode = theList->tail;
        theList->tail=aNewDNode;
        
        lastNode->next=aNewDNode;
    }
    
    theDList->elements++;
    
    aNewDNode->next=NULL;
    
    return aNewDNode;
}
void PrintDList(DList* theDList);
{

	if (theDList != NULL && theDList->elements!=0) {

	
		int i = 1;
                doubleNode *aDNode = theList->tail;
	
		do
		{
                    printf("doubleNode#%d value=%d\n",i,aDNode->value);
		
			i++; /*increase index*/ 
			aDNode = prevnode->aDNode; /* go to next node*/
		
		} while (aDNode != NULL);
                
	}
	
        else
            printf("Error. List doesn't exist.\n");
}

