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
	insertNode(theTree, "d", "01");
	insertNode(theTree, "b", "02");
	insertNode(theTree, "c", "03");
	insertNode(theTree, "a", "04");
	insertNode(theTree, "e", "05");
	insertNode(theTree, "f", "06");
	

	//printf("--%s\n\n", theTree->root->note->name);
	//printf("--%s\n\n", theTree->root->leftChild->note->name);

	

	/*NodePtr theFindNode = findNode(theTree, "f");

	if (deleteNode(theTree, "f"))
	{
		theFindNode = findNode(theTree, "f");
		printf("*find result: %x*", (unsigned int)theFindNode);
	}*/

	count = countTree(theTree->root);

	printf("Created a tree of %d nodes...\n", count);
	printf("Printing the tree...\n");

	displayTree(theTree->root);

	deleteTree(theTree, theTree->root);//verify that we deleted the tree
	
	/*if (theTree->root == NULL)
	{
		printf("Yahooo!!");
	}*/

	printf("Now there are %d nodes in the tree...\n", countTree(theTree->root));
	printf("Hello, World!\n");
	return 0;
}
