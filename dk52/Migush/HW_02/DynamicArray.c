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
    DynamicIntArray *DynArr=(DynamicIntArray*)malloc(sizeof(DynamicIntArray));//videlyaem pamyat pod massive ckotoruy predstavlyaet soboy structuru
   
    DynArr->storage=(int*)malloc(aSize*sizeof(int));//uckazatel na tolco chto sozdanuy massive
    
    DynArr->logicalSize=0;
    
    DynArr->physicalSize=aSize;
    
    return  DynArr;    
}

void freeDAInt(DynamicIntArray *anArray)
{
    if(anArray!=NULL)//uslovie
    {
        if(anArray->storage!=NULL)
            free(anArray->storage);//snachala udalyaem sam massive
    
	        free(anArray);//dalee udalyaem structuru
    }
}

int valueAtIndex(int anIndex,DynamicIntArray *anArray)
{
    if(anIndex < anArray->physicalSize)
        return anArray->storage[anIndex];//vozvrochyaem iz yacheycki
}

void setValueAtIndex(int anValue, int anIndex,DynamicIntArray *anArray)
{   int k;
    if(anArray->logicalSize>=anArray->physicalSize && anIndex> anArray->physicalSize)
    {   //uslovie vupolneniya napisanuh nije functsiy
                
        anArray->storage=realloc(anArray->storage,anIndex*5);//pri neobhodimosti funksiey realloc dovidelyaem pamyat
              
        anArray->logicalSize++;
        
        anArray->physicalSize=anIndex*5;
       
        anArray->storage[anIndex]=anValue;
    }
    else
    {
        anArray->storage[anIndex]=anValue;  //esli videlenie pamyati ne trebuetsa, to prosto zapisuvaem znachenie v yacheycky
        anArray->logicalSize++;
    }
}
