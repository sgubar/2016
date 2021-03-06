#include <stdio.h>
#include "tree.h"

int main(int argc, const char * argv[])
{
	int count;
	TreePtr theTree = createTree();

	insertNode(theTree, "aaa", "1234");
	insertNode(theTree, "abb", "1235");
	insertNode(theTree, "acc", "1232");
	insertNode(theTree, "baa", "1233");
	insertNode(theTree, "baa", "1230");
	insertNode(theTree, "baa", "1227");

		NodePtr theFindNode = findNode(theTree, "acc");

	if (deleteNode(theTree, "acc"))
	{
	theFindNode = findNode(theTree, "acc");
	printf ("\nFind result: %d", (unsigned int)theFindNode);
	}

	// insert code here...
	//printf("\nHello, World!\n");

	count = countTree(theTree);
	printf("\nThere are %d element in the tree", count);
	deleteTree(theTree);
	system("pause");
	return 0;
}
