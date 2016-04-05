/*Copyright (c), 2016, Mahnyov Aleksander. All rights reserved*/
#include <stdio.h>
#include <stdlib.h>
#include "twinLinkList.h"
#include "twinLinkNode.h"
#include <string.h>

static void doDemo();

int main(int argc, char* argv[]){
    if(argc > 1){
        if(strcmp(argv[1], "demo")==0){
            doDemo();
        }
    }
    return 0;
}

static void doDemo(){
    charNode *testNode0 = createCharNode('a');
    charNode *testNode1 = createCharNode('b');
    charNode *testNode2 = createCharNode('c');
    charNode *testNode3 = createCharNode('b');
    charNode *testNode4 = createCharNode('a');
    charList *testList = charListConstructor();
    addNode(testList, testNode0);
    addNode(testList, testNode1);
    addNode(testList, testNode2);
    addNode(testList, testNode3);
    addNode(testList, testNode4);
    int error = checkIfSim(testList);
    printf("check: %d\n", error);
    printCharList(testList);
    //printf("Arranging\n");
	//arrangeCharList(testList);
    //printCharList(testList);
    printf("Swapping\n");
    printCharList(swapList(testList));
}
