//
//  main.c
//  demoTree
//
//  Created by Slava Gubar on 5/18/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include "tree.h"

int main(int argc, const char * argv[])
{
	TreePtr theTree = createTree();

	insertNode(theTree, "aaa", "1234");
	insertNode(theTree, "abb", "1235");
	//insertNode(theTree, "acc", "1232");
	insertNode(theTree, "sg", "1233");
        insertNode(theTree, "basdfa", "12333");
       // insertNode(theTree, "baasdf", "12233");
        insertNode(theTree, "basdfa", "1233");
	//insertNode(theTree, "basdfa", "14533");


	//NodePtr theFindNode = findNode(theTree, "acc");



        displayTree(theTree);
        deleteTree(theTree);
        printf("Number of nodes: %d\n",countTree(theTree));
	return 0;
}