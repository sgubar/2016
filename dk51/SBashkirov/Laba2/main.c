//
//  main.c
//  Laba 2
//
//  Created by Stanislav Bashkirov on 3/21/16.
//  Copyright © 2016 Stanislav Bashkirov. All rights reserved.
//

#include <stdio.h>
#include "SingleNode.h"
#include "SingleList.h"
#include "WorkWithFile.h"


int main(int argc,char *argv[])
{
	if (argc != 5) printf("Error!\n Need syntax: <FileName> <Number> <FirstBorder> <SecondBorder>");
	else
	{
		IntList *theList = ListCreate();
		ReadTheFile(argv[2],theList);
		printf("number of elements: %d\n", CountList(theList));
	}
	system("pause");

}
