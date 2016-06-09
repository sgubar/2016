//
//  find.h
//  demoFind
//
//  Created by Slava Gubar on 5/10/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#ifndef find_h
#define find_h

#include <stdio.h>

extern const unsigned kNotFound;

unsigned line_find(int anArray[], int aSize, int aKey);
int RecursiveBinarySearch(int* array,int left,int right,int value);

#endif /* find_h */
