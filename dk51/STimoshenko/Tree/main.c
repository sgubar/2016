//
//  main.c
//  demoTree
//
//  Created by Serj Timoshenko on 6/8/16.
//  Copyright © 2016Serj Timoshenko. All rights reserved.
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
	insertNode(theTree, "bad", "1236");
	insertNode(theTree, "bda", "1237");
	insertNode(theTree, "daa", "1238");
	
	NodePtr theFindNode = findNode(theTree, "acc");
	
	if (deleteNode(theTree, "acc"))
	{
		theFindNode = findNode(theTree, "acc");
		printf ("find result: %x\n", (unsigned int)theFindNode);
	}
	printf("Count tree: %d\n", countTree(theTree));
	system("pause");

}
