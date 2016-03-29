/*Copyright (c), 2016, Mahnyov Aleksander. All rights reserved*/
#include <stdio.h>
#include <stdlib.h>
#include "twinLinkList.h"
#include "twinLinkNode.h"

int main()
{
    charNode *testNode1 = createCharNode('d');
    charNode *testNode2 = createCharNode('e');
    charNode *testNode3 = createCharNode('f');
    charList *testList = charListConstructor();
    addNode(testList, testNode1);
    addNode(testList, testNode2);
    addNode(testList, testNode3);
    printCharList(testList);
    printCharList(swapList(testList));
    printf("maxChar = %d\n", findMaxNode(testList));
    printf("minChar = %d\n", findMinNode(testList));
    return 0;
}
