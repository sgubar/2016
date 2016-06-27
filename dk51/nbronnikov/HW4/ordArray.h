//
//  ordArray.h
//  demoFind
//
//  Created by Bronnikov Nazar on 5/10/16.
//  Copyright © 2016 Bronnikov Nazar. All rights reserved.
//

#ifndef ordArray_h
#define ordArray_h

#include <stdio.h>

typedef struct __ordArray
{
	int *storage;
	unsigned size;
	unsigned maxSize;
}ordArray, *ordArrayPtr;


ordArrayPtr oa_create(unsigned aSize);
void oa_destroy(ordArrayPtr anArray);

unsigned oa_insert(ordArrayPtr anArray, int aValue);
unsigned oa_delete(ordArrayPtr anArray, int aValue);
unsigned oa_size(ordArrayPtr);
unsigned oa_find(ordArrayPtr anArray, int aValue);
void oa_print(ordArrayPtr anArray);

#endif /* ordArray_h */