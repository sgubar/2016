//
//  DynamicArray.c
//  doTest
//
//  Created by Slava Gubar on 3/24/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include <stdlib.h>

#include "DynamicArray.h"

DynamicIntArray* createDAInt(int aSize)
{    
    DynamicIntArray *DynArr=(DynamicIntArray*)malloc(sizeof(DynamicIntArray));//pointer on our created dynamic array struct
   
    DynArr->storage=(int*)malloc(aSize*sizeof(int));//pointer on our created array itself
    
    DynArr->logicalSize=0;
    
    DynArr->physicalSize=aSize;
    
    DynArr->storvalidity=0;
    return  DynArr;    
}

void freeDAInt(DynamicIntArray *anArray)
{
    if(anArray!=NULL)//if array exists
    {
        if(anArray->storage!=NULL)
            free(anArray->storage);//firstly free array itself
        else
            anArray->storvalidity=-1;//array validity flag
        
        free(anArray);//then clear our struct memory (to prevent memory outflow)
    }
}

int valueAtIndex(int anIndex,DynamicIntArray *anArray)
{
    if(anIndex < anArray->physicalSize)
        return anArray->storage[anIndex];//return cell value anIndex; case:what we should return if our index > logical size?
    else
        anArray->storvalidity=-1;
   // return anArray->storvalidity;
}

void setValueAtIndex(int anValue, int anIndex,DynamicIntArray *anArray)
{   int k;
    if(anArray->logicalSize>=anArray->physicalSize && anIndex> anArray->physicalSize)
    {   //check for overflow
        int* tempptr=anArray->storage;
        
        anArray->storage=realloc(anArray->storage,anIndex*2);//reallocating memory block
        
        for(k=0;k < anArray->physicalSize;++k)//rewriting our logical cells to new memory block
            anArray->storage[k]=tempptr[k];
        
        anArray->logicalSize++;
        
        anArray->physicalSize=anIndex*2;
       
        anArray->storage[anIndex]=anValue;
    }
    else
    {
        anArray->storage[anIndex]=anValue;
        anArray->logicalSize++;
    }
}
    

int infofunc( DynamicIntArray *DynArr)//just for debug
{
    printf("logical size: %d"
            "\nphysical size: %d"
            "\nstorage validity: %d\n",DynArr->logicalSize,DynArr->physicalSize,DynArr->storvalidity);
    return 0;
}
