//
//  DynamicArray.c
//  doTest
//
//  Created by Slava Gubar on 3/24/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include "DynamicArray.h"

DynamicIntArray* createDAInt(int aSize)
{    
    DynamicIntArray *DynArr=(DynamicIntArray*)malloc(sizeof(DynamicIntArray));//pointer on our created dynamic array struct
   
    DynArr->storage=(int*)malloc(aSize*sizeof(int));//pointer on our created array itself
    
    DynArr->logicalSize=aSize;//if i understand correctly
    
    DynArr->physicalSize=aSize*sizeof(int);
    
    return DynArr;    
}

void freeDAInt(DynamicIntArray *anArray)
{
    if(anArray!=NULL)
    {
        free(anArray->storage);//firstly free array itself
       
        free(anArray);//then clear our struct memory (to prevent memory outflow)
    }
}

int valueAtIndex(int anIndex,DynamicIntArray *anArray)
{
    return anArray->storage[anIndex];//return cell value anIndex; case:what we should return if our index > logical size?
}

void setValueAtIndex(int anValue, int anIndex,DynamicIntArray *anArray)
{  if(anIndex <= anArray->logicalSize)//check for overflow
    
    anArray->storage[anIndex]=anValue; 
}