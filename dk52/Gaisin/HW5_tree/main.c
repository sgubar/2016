#include <stdio.h>

#include "tree.h"

int main()
{
	int qquantity_nodes;
	TreePtr theTree = createTree();
	
	insertNode(theTree, "aaa", "1234");
	insertNode(theTree, "abb", "1235");
	insertNode(theTree, "acc", "1232");
	insertNode(theTree, "baa", "1233");

	printf("quantity nodes = %i \n", countTree(theTree->root));
	deleteTree(theTree);
	return 0;
}
