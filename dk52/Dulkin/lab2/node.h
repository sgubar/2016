/* 
 * File:   node.h
 * Author: Dulkin Oleg
 *
 * Created on 19 квітня 2016, 4:04
 * Compiled with gcc(cygwin)
 */
ifndef SingleNode_h
#define SingleNode_h

#include <stdio.h>

typedef struct __FloatNode FloatNode;

struct __FloatNode
{
	float value;
	FloatNode *nextNode;
};

#endif
