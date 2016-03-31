/*Copyright (c), 2016, Mahnyov Aleksander. All rights reserved*/
#include <stdio.h>
#include <stdlib.h>
#include "twinLinkList.h"
#include "twinLinkNode.h"

int main()
{
    charNode *testNode1 = createCharNode('a');
    charNode *testNode2 = createCharNode('g');
    charNode *testNode3 = createCharNode('z');
    charList *testList = charListConstructor();
    addNode(testList, testNode1);
    addNode(testList, testNode2);
    addNode(testList, testNode3);
    printCharList(testList);
    //printf("Swapping\n");
    //printCharList(swapList(testList));
    printf("Arranging\n");
    printCharList(arrangeCharList(testList));
    return 0;
}
