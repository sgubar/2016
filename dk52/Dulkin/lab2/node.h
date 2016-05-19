#ifndef SingleNode_h
#define SingleNode_h

#include <stdio.h>

typedef struct __FloatNode FloatNode;

struct __FloatNode
{
	float value;
	FloatNode *nextNode;
};

#endif
