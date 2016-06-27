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

	insertNode(theTree, "Andrew", "1234");
	insertNode(theTree, "Sergey", "1235");
	insertNode(theTree, "Petr", "1232");
	insertNode(theTree, "Vasiliy", "1233");
	insertNode(theTree, "Ivan", "3333");
	NodePtr theFindNode = findNode(theTree, "Basiliy");

	printf("count = %d\n", countTree(theTree));
	printTree(theTree);

	if (deleteNode(theTree, "Sergey"))
	{
		theFindNode = findNode(theTree, "Sergey");
		printf("find result: %x\n", (unsigned int)theFindNode);
	}
	printf("\n");
	// insert code here...
	printTree(theTree);
	printf("count = %d\n", countTree(theTree));
	deleteTree(theTree);
	
	system("pause");
}
