/*Copyright (c), 2016, Mahnyov Aleksander. All rights reserved*/
#include <stdio.h>
#include <stdlib.h>
#include "twinLinkList.h"
#include "twinLinkNode.h"
#include <string.h>

static void doDemo();
static void doTask();

int main(int argc, char* argv[]){
    if(argc == 1){
        if(strcmp(argv[1], "demo")==0){
            doDemo();
        }

        if(strcmp(argv[1], "task")==0){
            doTask();
        }
    } else {
        printf("Invalid syntax.\nlab2 <key>\nPossible keys: 'task', 'demo'\n");
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

static void doTask(){
    FILE *inputFile;
    char ch;
    charList *theList = charListConstructor();
    if((inputFile = fopen("input.txt", "r")) == NULL){
        printf("Invalid file!\n");
        exit(1);
    }
    while((ch=fgetc(inputFile)) != EOF){
        charNode *nodeToAdd = createCharNode(ch);
        addNode(theList, nodeToAdd);
    }
    if(checkIfSim(theList) == 0){
        printf("Input file string is symmetrical\n");
    }else{
        printf("Input file string is not symmetrical\n");
    }
    fclose(inputFile);
}
