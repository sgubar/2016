/* 
 * File:   newmain.c
 * Author: Dmitry Sakharov
 *
 * Created on 15 березня 2016, 0:40
 * Compiled with gcc(cygwin)
 */
#include<stdio.h>
#include<stdlib.h>
#include "List.h"
#include"Node.h"




List* CreateList()
{
    List* CreatedList =(List*)malloc(sizeof(List));
    CreatedList->head = NULL; //there is no head & tail in our created list
    CreatedList->tail = NULL;
    CreatedList->elements=0;    
    return CreatedList;
}

Node* AddNode(List* theList, Node* theNewNode)
{
    if(theList==NULL || theNewNode==NULL)
        return NULL;
    
    else if(theList->head==NULL && theList->tail==NULL)//list is empty
        theList->head=theList->tail=theNewNode;
    else
    {
        Node* lastNode = theList->tail;
        theList->tail=theNewNode;
        
        lastNode->nextptr=theNewNode;
    }
    
    theList->elements++;
    
    theNewNode->nextptr=NULL;
    
    return theNewNode;
}
void PrintList(List* theList)
{

	if (NULL != theList&&theList->elements!=0) {

	
		int i = 1;
                Node *theNode = theList->head;
	
		do
		{
                    printf("Node#%d value=%d\n",i,theNode->value);
		
			i++; // increase index
			theNode = theNode->nextptr; //<! - go to next node
		
		} while (NULL != theNode);
                
	}
	
        else
            printf("Error: list doesn't exist, or empty!\n");
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
                    
                    theNode = theNode->nextptr; //<! - go to next node
		
		} while (NULL != theNode);
                
                                            //swaping values of minimal and maximal elements
                int tempval=maxNode->value;
                maxNode->value=minNode->value;
                minNode->value=tempval;
	}
	
        else
            printf("Error: list doesn't exist!\n");
}

List* DelNodeWithValue(List* theList,int val)
{    
 if (NULL != theList)
	{		
            Node* theNode=theList->head;
           
		do
		{
                    if (theNode==theList->head&&theNode==theList->tail&&theNode->value==val)//one element in the list
                    {   
                        theList->head=theList->tail=NULL;
                        theList->elements=0;
                        break;
                    }
                    else if(theNode->nextptr->value==val&&theNode->nextptr==theList->tail)
                    {                     
                        
                        theNode->nextptr=NULL;
                        theList->tail=theNode;//connect prev node to the next node
                        theList->elements--;
                        break;
                    }  
                    else if (theNode==theList->head && theNode->value==val)//if needed node is a head of list
                    {  
                        theList->head=theNode->nextptr;
                        theList->elements--;
                        break;
                    }
                    
                    else if(theNode->nextptr->value==val)//in the middle of list
                    {
                        printf("Here, in middle");
                        theNode->nextptr=theNode->nextptr->nextptr;
                        theList->elements--;
                        break;
                    }
                    
                    theNode = theNode->nextptr; //<! - go to next node
                    if(theNode->nextptr==NULL)
                    {
                        printf("Error: element doesn't exist");
                       
                    }
		
		} while (NULL != theNode->nextptr);
                  
                
               
                
	}
 return theList;
}

void SortList(List* theList)
{
    if(theList!=NULL)
    {
        int length=theList->elements, b=0;
        Node* theNode=theList->head;
        
        for (int i = 0; i < length-1; i++) {
            int  swapped = 0;
            theNode=theList->head;
            for (int j = 0; j < length-i-1; j++) {
             
             if (theNode->value > theNode->nextptr->value) {
                  b = theNode->value; 
                 theNode->value = theNode->nextptr->value;
                 theNode->nextptr->value = b;
                 swapped = 1; 
             }
             theNode=theNode->nextptr;
         }
         
         if(!swapped)
            break;
     }
    }
    else
        printf("Error: list doesn't exist!\n");
}

Node* SortListAfterMinNode(List* theList)
{
    if(theList!=NULL){
        Node *minNode,*theNode;
        theNode = minNode= theList->head;
        int i=0,num=0;       
		do
		{
                    if (theNode->value < minNode->value)
                    {
                        minNode=theNode;
                        num=i;
                    }                        
                    i++;
                    theNode = theNode->nextptr; //<! - go to next node
		
		} while (NULL != theNode);
                //sorting elements after minNode;
        int length=theList->elements;
        
         theNode=minNode;
        
        for (int i = 0; i < length-1-num; i++) {
            int  swapped = 0;
            theNode=minNode;
            for (int j = 0; j < length-i-1-num; j++) {
                if (theNode->value > theNode->nextptr->value) {
                    int b = theNode->value; 
                    theNode->value = theNode->nextptr->value;
                    theNode->nextptr->value = b;
                    swapped = 1;
             }
                theNode=theNode->nextptr;
         }
         
         if(!swapped)
            break;
     }
        return minNode;
    }
    return NULL;
}

int Face()
{
    printf("Now you can create a list, which will be filled with random numbers from 1 to 100"
            "\nEnter lenght of the list ");
    char* length[10],input[10];
    char choise=0;
    gets(length);
    int l =atoi(length);
    if(!l)
        {
            printf("Error");
            return -1;
        }
    else
{
            List* NewList = CreateList();

            int i,val;
            for(i=0;i<l;i++)
                AddNode(NewList,CreateNode(rand()%100+1));
            PrintList(NewList);
           while(1)
                {
                    printf("Press:\n'1' to swap minimal and maximal elements;"
                    "\n'2' to delete an element with some value;"
                    "\n'3' to sort list;"
                    "\n'4' to sort list after minimal value;"
                    "\n'5' to copy existant value"    
                    "\nor '0' to quit.");
                   
                    scanf("%d",&choise);
                    switch (choise)
                        {
                        case 1:
                            MinMaxSwap(NewList);
                            printf("\nDone!\n");
                            PrintList(NewList);
                            break;
                        case 2:                
                            printf("\nEnter value\n");
                            //dummy=getchar();
                            scanf("%d",&val);
                            
                            if(!val)
                            printf("\nError\n");

                            else
                                {
                                DelNodeWithValue(NewList,val);
                                printf("\nDone!\n");
                                PrintList(NewList);
                                }

                            break;
                        case 3:
                            SortList(NewList);
                            printf("\nDone!\n");
                            PrintList(NewList);
                        case 4:
                            SortListAfterMinNode(NewList);
                            printf("\nDone!\n");
                            PrintList(NewList);
                            break;
                        case 5:
                             printf("\nEnter value\n");
                            //dummy=getchar();
                            scanf("%d",&val);
                            
                            if(!val)
                            printf("\nError\n");

                            else
                                {
                                if(!CopyValue(NewList,val))
                                    {
                                        printf("This value doesn't exist!");
                                    }
                                else
                                    {
                                        printf("\nDone!\n");
                                    }
                                PrintList(NewList);                                
                                }
                            break;
                        case 0:
                            ;
                            break;
                        
                        default:
                            printf("\nError\n");

                    } 
                    if(choise== 0)
                        {
                            printf("\nExit, bye!\n");
                            break;
                        }
                    //choise=NULL;
                   fflush(stdin);
                }   
}
    return 0;
}

