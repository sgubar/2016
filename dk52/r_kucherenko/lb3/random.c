//
//  SimpleSort.h
//  demoSimpleSort
//
//  Created by Slava Gubar on 4/7/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include "random.h"
#include"stdlib.h"

int* randArray (int aSize)
{
    int i;
    int* anArray=malloc(aSize*sizeof(int));
    for (i=0;i<aSize;i++)
    {
     anArray[i]=rand( ) % 100 + 1;
    }
    return anArray;
}

