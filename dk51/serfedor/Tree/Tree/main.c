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

	insertNode(theTree, "Andrey", "1234");
	insertNode(theTree, "Alyosha", "1235");
	insertNode(theTree, "Azirov", "1232");
	insertNode(theTree, "Bodya", "1233");
	insertNode(theTree, "Badyrich", "3333");
	NodePtr theFindNode = findNode(theTree, "Bodya");

	printf("count = %d\n", countTree(theTree));
	printTree(theTree);

	if (deleteNode(theTree, "Azirov"))
	{
		theFindNode = findNode(theTree, "Azirov");
		printf("find result: %x\n", (unsigned int)theFindNode);
	}
	printf("\n");
	// insert code here...
	printTree(theTree);
	printf("count = %d\n", countTree(theTree));
	deleteTree(theTree);
	
	system("pause");
}