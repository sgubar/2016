#ifndef Node_h
#define Node_h

#include <stdio.h>

typedef char *String;

typedef struct __StringNode StringNode;

struct __StringNode 
{
	String value;
	StringNode *nextNode;
};

StringNode *newNode(String value);
StringNode *createStringNode(String value);
String duplicateString(String string);
void freeNode(StringNode *node);

#endif
