#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

int main(){
    TreePtr testTree = createTree();
    insertNode(testTree, "b", "1234");
	insertNode(testTree, "a", "1235");
	insertNode(testTree, "c", "1232");
    printf("Test tree created.\n");
    deleteTree(testTree);
    printf("Test tree deleted.\n");
    system("pause");
    TreePtr theTree = createTree();
	insertNode(theTree, "b", "1234");
	insertNode(theTree, "a", "1235");
	insertNode(theTree, "c", "1232");
	insertNode(theTree, "h", "1232");
	insertNode(theTree, "x", "1232");
	insertNode(theTree, "f", "1232");
	insertNode(theTree, "y", "1232");
	insertNode(theTree, "g", "1232");
	insertNode(theTree, "d", "1233");
	launchGraphics();
    int numOfNodes = countTree(theTree);
    printf("Tree counted, number of nodes: %d\n", numOfNodes);
    displayTree(theTree);
    return 0;
}
