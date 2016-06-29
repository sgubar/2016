#ifndef doublenodes_h
#define doublenodes_h
#include <stdio.h>
#include<stdlib.h>

/*description of the new data type doubleNode*/
typedef struct doubleNode doubleNode; 
struct doubleNode
{
	char letter;
	doubleNode* prevnode;
	doubleNode* nextnode;
}

doubleNode* CreateDNode(char aLetter);

void freeDNode(doubleNode *aDNode)

/*int letter;
	letter=getchar ();
	doubleNode* prevnode;
	doubleNode* nextnode;*/
#endif
