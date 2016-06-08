//
//  main.c
//  
//  Created by Serhii Ryzhenkov on 6/8/16.
//  Copyright © 2016 Serhii Ryzhenkov. All rights reserved.
//

#include <stdio.h>
#include "binarytree.h"

int main(int argc, const char * argv[])
{
	TreePtr theTree = createTree();

	insertNode(theTree, "aaa", "1234");
	insertNode(theTree, "abb", "1235");
	insertNode(theTree, "acc", "1232");
	insertNode(theTree, "baa", "1233");

	NodePtr theFindNode = findNode(theTree, "acc");
	printf("%s \n", theFindNode->note->name);

	if (deleteNode(theTree, "acc"))
	{
		theFindNode = findNode(theTree, "acc");
		printf("find result: %x \n", (unsigned int)theFindNode);
	}

	deleteTree(theTree);

	//printf("  %s \n", theFindNode->note->name);


	//return 0;
	system("Pause");
}