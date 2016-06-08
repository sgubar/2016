#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

int main(){
    TreePtr theTree = createTree();

	insertNode(theTree, "b", "1234");
	insertNode(theTree, "a", "1235");
	insertNode(theTree, "c", "1232");
	//insertNode(theTree, "asd", "7523");
	insertNode(theTree, "d", "1233");
    int numOfNodes = countTree(theTree);
    printf("Tree counted, number of nodes: %d\n", numOfNodes);
    system("pause");
    launchGraphics();
    displayTree(theTree);
    system("pause");
    return 0;
}
