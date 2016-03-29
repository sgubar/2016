#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

typedef struct __IntNode IntNode;
struct __IntNode
{
	int value;
	IntNode *nextNode;
};

IntNode *CreateN(int perevod);
void FreeIntNode(IntNode *aNode);
void doSorting(IntNode *theList);
void doChangeValue(IntNode *theList);

#endif // FUNCTION_H_INCLUDED
