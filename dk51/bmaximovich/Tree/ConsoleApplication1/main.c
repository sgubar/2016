//
//  Main.c
//
//
//  Created by Bogdan Maximovich on 6/08/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
//

#include <stdio.h>
#include "tree.h"

int main(int argc, const char * argv[])
//
//  Main.c
//
//
//  Created by Bogdan Maximovich on 6/08/16.
//  Copyright © 2016 Bogdan Maximovich. All rights reserved.
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

	displayTree(theTree);

	printf("\ncount before: %d\n\n\n", countTree(theTree->root));

	if(deleteNode(theTree, "baa")==1){
    printf("\n\n Node (baa) has been deleted\n\n");
	}else{
	printf("Node not found\n\n");
	}

	displayTree(theTree);



	printf("count after: %d\n\n\n", countTree(theTree->root));

    deleteTree(theTree, theTree->root);

	system("pause");
	return 0;
}
