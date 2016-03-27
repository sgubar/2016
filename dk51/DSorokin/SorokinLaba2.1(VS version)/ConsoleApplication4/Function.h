#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

typedef struct __IntNode IntNode;
struct __IntNode
{
	int value;
	IntNode *nextNode;
};

//typedef struct __IntArray IntArray;
//typedef struct __IntArray {
	//int Param;
//};

IntNode *CreateN(int perevod);
void FreeIntNode(IntNode *aNode);

#endif // FUNCTION_H_INCLUDED
