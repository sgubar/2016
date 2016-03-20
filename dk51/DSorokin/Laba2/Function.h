#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <stdio.h>

typedef struct __IntNode IntNode;
struct __IntNode
{
    int value;
    IntNode *nextNode;
};

IntNode *CreateN(int perevod);

#endif // FUNCTION_H_INCLUDED
