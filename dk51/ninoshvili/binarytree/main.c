/*															 /
/  tree.h													 /
/  Binary tree												 /
/															 /
/  Created by Sergey Ninoshvili on 06/25/16.				 /
/  Copyright © 2016 Sergey Ninoshvili. All rights reserved.  /
/															*/
#include <stdio.h>
#include "tree.h"

int main()
{
	Tree *tree = createTree();
	int count = 0;
	int order = 0;

	insertNode(tree, "ken", "111");		//1
	insertNode(tree, "joy", "112");		//2
	insertNode(tree, "bart", "121");	//3
	insertNode(tree, "ed", "211");		//4
	insertNode(tree, "tod", "122");		//5
	insertNode(tree, "carl", "221");	//6	
	insertNode(tree, "zak", "222");		//7
	insertNode(tree, "poul", "223");	//8
	insertNode(tree, "rob", "232");		//9
	insertNode(tree, "johnny", "322");	//10
	insertNode(tree, "stewie", "233");	//11
	insertNode(tree, "vida", "332");	//12
	insertNode(tree, "web", "333");		//13
	insertNode(tree, "cena", "444");	//14

	order = displayTree(tree->root, &order);
	order = 0;

	count = countTree(tree->root, &count);

	printf("\ncount is:%d\n", count);

	node *item = findNode(tree->root, "cena");
	if(item != NULL)
		printf("\nnode with finding name - %s has phone:%s\n",  item->note->name, item->note->number);
	else printf("sorry, but I can't find this name\n");

	deleteNode(tree, "ken");
	
	order = displayTree(tree->root, &order);
	order = 0;
	
	printf("\ndestroing the tree...\n");
	deleteTree(tree->root, tree);
	printf("destroyed!\n");

	order = displayTree(tree->root, &order);
	if (order == 0)
		printf("\nsorry, but somebody destroyed tree\n");

	printf("\nfine\n");

	system("pause");
}
