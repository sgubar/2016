
#include <string.h>
#include <stdio.h>
#include "tree.h"
#include <time.h>
#include <iostream>

int main(int argc, const char * argv[])
{
	TreePtr theTree = createTree();

	insertNode(theTree, "a", "1");
	insertNode(theTree, "b", "2");
	insertNode(theTree, "c", "3");
	insertNode(theTree, "d", "4");
	insertNode(theTree, "e", "5");
	insertNode(theTree, "f", "6");
	insertNode(theTree, "g", "7");
	insertNode(theTree, "h", "8");
	insertNode(theTree, "i", "9");
	insertNode(theTree, "j", "10");
	insertNode(theTree, "k", "11");
	
	

	
	
	
	clock_t theStart = clock();
	NodePtr theFindNode = findNode(theTree, "f");
	clock_t theEnd = clock();
	printf("Time of finding: %.15lf\n", (double)(theEnd - theStart) / CLOCKS_PER_SEC);


	printf("count = %d\n", countTree(theTree));
	displayTree(theTree);
	if (deleteNode(theTree, "f"))
	{
		theFindNode = findNode(theTree, "f");
		printf("find result: %x\n", (unsigned int)theFindNode);
	}
	printf("count = %d\n", countTree(theTree));
	displayTree(theTree);
	deleteTree(theTree);
	
	
	system("pause");

	return 0;
}