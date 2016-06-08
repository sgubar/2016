/* 
 * File:   list.c
 * Author: Ruslan Kucherenko
 *
 * Created on 1 червня 2016, 1:22
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
    if(theList==NULL || theNewNode==NULL)//netu lista 
        return NULL;
    
    else if(theList->head==NULL && theList->tail==NULL)//pustoy
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
                    if(theNode->value > maxNode->value)//nahodim bolshuyu
                        maxNode=theNode;
                    else if (theNode->value < minNode->value)//nahodim menshuyu
                        minNode=theNode;                        
                    
                    theNode = theNode->nextptr; //<! - go to next node
		
		} while (NULL != theNode);
                
                //menayem znacheniya min i max
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
            Node* theNode=theList->head;//begin from head
           
		do
		{
                    if (theNode==theList->head&&theNode==theList->tail&&theNode->value==val)//odin element v liste
                    {   
                        theList->head=theList->tail=NULL;
                        theList->elements=0;
                        break;
                    }
                    else if(theNode->nextptr->value==val&&theNode->nextptr==theList->tail)//v hvoste
                    {                     
                        
                        theNode->nextptr=NULL;
                        theList->tail=theNode;//soyedinayem prediduschuyu k sleduyuschey
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
                                                  //Bubble algorithm
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

int Interface()
{
    printf("\nEnter lenght of the list ");
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
                    "\n'4' to delete similar elements;"
                    "\nor '0' to quit.");
                   
                    scanf("%d",&choise);
                            if(choise==1)
                            {
                                MinMaxSwap(NewList);
                                printf("\nDone!\n");
                                PrintList(NewList);
                            }
                            else if(choise==2)
                            {
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
                            }

                            else if(choise==3)
                            {
                                SortList(NewList);
                                printf("\nDone!\n");
                                PrintList(NewList);
                            }
                            else if(choise==4)
                            {                               
                                DeleteSimilar(NewList);
                                printf("\nDone!\n");
                                PrintList(NewList);
                            }   
                                            
                            
                            
                            else if(choise== 0)
                        {
                            printf("\nExit, bye!\n");
                            break;
                        }
                            else
                        {
                            printf("\nError\n");
                           
                        } 
                    
                            
                    } 
                   
                    //choise=NULL;
                   fflush(stdin);
                }   
    return 0;
}
    
    void DeleteSimilar(List* theList)
{
    if (NULL != theList&&theList->elements!=0) {

                int i = 0;
                Node *theNodeToCheck = theList->head;
                Node *SliderNode=theList->head;//vremennaja Node
		do
		{ 
                    if(theNodeToCheck->value==SliderNode->value)
                    {
			i++; // increase index
                    }
                    if(i==2)//case, when our value exists in two more nodes
                    {
                        DelNodeWithValue(theList,SliderNode->value);//delete node 
                       i--;
                    }
                    if(SliderNode->nextptr==NULL)//if we at the end of the list
                    {
                    i=0;
                    SliderNode=theList->head;//begin from head again
                    theNodeToCheck=theNodeToCheck->nextptr;//check next node 
                    }
                    SliderNode = SliderNode->nextptr; //<! - go to next node
		
		} while (NULL != theNodeToCheck);
                
	}
}    