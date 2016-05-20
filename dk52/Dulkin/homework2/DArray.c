#include <stdlib.h>

#include "DArray.h"

DynamicArray* CreateArr(int aSize)
{    
    DynamicArray *NewArr=(DynamicArray*)malloc(sizeof(DynamicArray));//pointer on our created dynamic array struct
   
    NewArr->storage=(int*)malloc(aSize*sizeof(int));//pointer on our created array itself
    
    NewArr->logicalSize=0;
    
    NewArr->physicalSize=aSize;
    
    NewArr->store=0;
    return  NewArr;    
}

void SetFree(DynamicArray *InArr)
{
    if(InArr!=NULL)//if array exists
    {
        if(InArr->storage!=NULL)
            free(InArr->storage);//firstly free array itself
        else
            InArr->store=-1;//array validity flag
        
        free(InArr);//then clear our struct memory (to prevent memory outflow)
    }
}

int IndexVal(int anIndex,DynamicArray *InArr)
{
    if(anIndex < InArr->physicalSize)
        return InArr->storage[anIndex];//return cell value anIndex; case:what we should return if our index > logical size?
    else
        InArr->store=-1;
   // return InArr->store;
}

void SetValue(int anValue, int anIndex,DynamicArray *InArr)
{   int k;
    if(InArr->logicalSize>=InArr->physicalSize && anIndex> InArr->physicalSize)
    {   //check for overflow
        int* tempptr=InArr->storage;
        
        InArr->storage=realloc(InArr->storage,anIndex*2);//reallocating memory block
        
        for(k=0;k < InArr->physicalSize;++k)//rewriting our logical cells to new memory block
            InArr->storage[k]=tempptr[k];
        
        InArr->logicalSize++;
        
        InArr->physicalSize=anIndex*2;
       
        InArr->storage[anIndex]=anValue;
    }
    else
    {
        InArr->storage[anIndex]=anValue;
        InArr->logicalSize++;
    }
}
    

int infofunc( DynamicArray *NewArr)//just for debug
{
    printf("logical size: %d"
            "\nphysical size: %d"
            "\nstorage validity: %d\n",NewArr->logicalSize,NewArr->physicalSize,NewArr->store);
    return 0;
}
