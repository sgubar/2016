#ifndef SingleLinkedNode_h
#define SingleLinkedNode_h
#include <stdio.h>

typedef char *String;
typedef struct __StringNode StringNode;

typedef struct __StringList
{
	StringNode *head;
	StringNode *tail;
	int count;
} StringList;

StringList *newStringList();
void addStringNode(StringList *stringList, StringNode *newStringNode);
void printStringList(StringList *stringList);
StringNode *getNodeAtIndex(StringList *stringList, int index);
StringNode *stringNodeWithMinValue(StringList *stringList);
StringNode *stringNodeWithMaxValue(StringList *stringList);
void deleteNodeInStringListByValue(StringList *stringList, String value);
void swapStringNodeInSingleStringList(StringNode *stringNode1, StringNode *stringNode2, StringList *stringList);
StringNode *getStringNodeByValue(StringList *stringList, String value);
int getStringNodeIndexByStringNode(StringList *stringList, StringNode *searchStringNode);
int getStringNodeIndexByValue(StringList *stringList, String value);
void sortSingleStringList(StringList *stringList);


#endif
