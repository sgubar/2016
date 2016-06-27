#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"


DynamicIntArray *createDAInt(int aSize)
    {
        DynamicIntArray *DynArray=(DynamicIntArray*)malloc(sizeof(DynamicIntArray));
        DynArray -> storage=(int*)malloc(aSize*sizeof(int));
        DynArray->logicalSize=0;
        DynArray->physicalSize=aSize;

        return DynArray;
    }
void freeDAInt(DynamicIntArray *anArray)
    {
    if(anArray!= NULL)//if array exists
        {
            if(anArray->storage!= NULL)
                free(anArray->storage);//firstly free array itself
    free (anArray);//then clear our struct memory (to prevent memory outflow)

    }
    }
int valueAtIndex(int anIndex,DynamicIntArray *anArray)
     {
     if (anIndex > anArray->physicalSize || anArray->storage == NULL)
        return NULL;
     else
      anArray->storage[anIndex];
     }
 void setValueAtIndex(int anValue, int anIndex,DynamicIntArray *anArray)

    {
     if (anIndex>anArray->physicalSize||anArray->physicalSize==anArray->logicalSize)
     {
            anArray->storage=realloc(anArray->storage,anIndex*sizeof(int)*3);//reallocating memory block
           anArray->physicalSize=anIndex*3;
           anArray->storage[anIndex]=anValue;
             anArray->logicalSize++;
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
            "\nphysical size: %d\n\n",DynArr->logicalSize,DynArr->physicalSize);
    return 0;
}
