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
	int count = 0;
	char *anArray[100];
	TreePtr theTree = createTree();
	
	insertNode(theTree, "aaa", "1234");
	insertNode(theTree, "aab", "1235");
	insertNode(theTree, "aac", "1236");
	insertNode(theTree, "aba", "1237");
	insertNode(theTree, "aca", "1238");
	insertNode(theTree, "baa", "1239");
	insertNode(theTree, "caa", "1231");
	
	NodePtr theFindNode = findNode(theTree, "acc");
	
/*	if (deleteNode(theTree, "acc"))
	{
		theFindNode = findNode(theTree, "acc");
		printf ("find result: %x", (unsigned int)theFindNode);
	} */
	
	count = countTree(theTree->root);

	printf("Tree consists of %d nodes \n", count);
	printf("Tree looks like\n");

	displayTree(theTree->root);
	
	printf("Now tree has %d nodes \n", countTree(theTree->root));
	return 0;
}
