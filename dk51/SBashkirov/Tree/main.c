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
	
	insertNode(theTree, "abb", "50");
	insertNode(theTree, "aaa", "30");
	insertNode(theTree, "acc", "70");
	insertNode(theTree, "cav", "36");
	insertNode(theTree, "acb", "60");
	insertNode(theTree, "aad", "28");
	

	NodePtr theFindNode = findNode(theTree, "acb");
	printf("count = %d\n", countTree(theTree));
	displayTree(theTree);
	if (deleteNode(theTree, "acc"))
	{
		theFindNode = findNode(theTree, "acc");
		printf ("find result: %x\n", (unsigned int)theFindNode);
	}
	// insert code here...
	printf("Hello, World!\n");
	system("pause");
}
