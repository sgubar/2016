//
//  Main.c
//
//
//  Created by Nazar Bronnikov on 6/08/16.
//  Copyright © 2016 Nazar Bronnikov. All rights reserved.
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
	
	if (deleteNode(theTree, "acc"))
	{
		theFindNode = findNode(theTree, "acc");
		printf ("find result: %x", (unsigned int)theFindNode);
	}
	displayTree(theTree);
	int counttree = countTree(theTree);
	printf("counttree = [%d]", counttree);
	deleteTree(theTree);
	printf("Hello, World!\n");
	return 0;
}
