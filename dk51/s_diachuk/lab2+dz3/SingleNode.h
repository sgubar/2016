#ifndef SingleNode_h
#define SingleNode_h

#include <stdio.h>

typedef struct __CharNode CharNode;

struct __CharNode
{
	char *value;
	CharNode *nextNode;
};

#endif 