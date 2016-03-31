/*Copyright (c), 2016, Mahnyov Aleksander. All rights reserved*/
#include <stdio.h>
#include <stdlib.h>
#include "twinLinkList.h"
#include "twinLinkNode.h"

int main()
{
    charNode *testNode0 = createCharNode('h');
    charNode *testNode1 = createCharNode('a');
    charNode *testNode2 = createCharNode('g');
    charNode *testNode3 = createCharNode('z');
    charNode *testNode4 = createCharNode('y');
    charList *testList = charListConstructor();
    addNode(testList, testNode0);
    addNode(testList, testNode1);
    addNode(testList, testNode2);
    addNode(testList, testNode3);
    addNode(testList, testNode4);
    printCharList(testList);
    //printf("Swapping\n");
    //printCharList(swapList(testList));
    printf("Arranging\n");
	
	arrangeCharList(testList);
	
	 printCharList(testList);
    return 0;
}
