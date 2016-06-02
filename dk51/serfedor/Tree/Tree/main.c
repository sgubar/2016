//
//  main.c
//  Tree
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
	insertNode(theTree, "acc", "1232");
	insertNode(theTree, "baa", "1233");

	NodePtr theFindNode = findNode(theTree, "acc");

	printf("count = %d\n", countTree(theTree));

	if (deleteNode(theTree, "acc"))
	{
		theFindNode = findNode(theTree, "acc");
		printf("find result: %x\n", (unsigned int)theFindNode);
	}
	printf("count = %d\n", countTree(theTree));
	// insert code here...
	printf("Hello, World!\n");
	system("pause");
}