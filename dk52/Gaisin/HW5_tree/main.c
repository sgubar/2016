#include <stdio.h>

#include "tree.h" //connect your file 

int main()
{
	TreePtr theTree = createTree(); //create list and assign theTree
	
	insertNode(theTree, "aaa", "1234");
	insertNode(theTree, "abb", "1235");
	insertNode(theTree, "acc", "1232");
	insertNode(theTree, "baa", "1233");

	printf("quantity nodes = %i \n", countTree(theTree->root)); //output count nodes on screen
	deleteTree(theTree);
	return 0;
}
