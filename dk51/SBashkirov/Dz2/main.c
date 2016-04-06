//
//  main.c
//  Laba 2
//
//  Created by Stanislav Bashkirov on 3/21/16.
//  Copyright © 2016 Stanislav Bashkirov. All rights reserved.
//

#include <stdio.h>
#include "DynamicArray.h"

int main()
{
	printf("Create dynamic massive\n");
	DynamicIntArray *anArray= createDAInt(10);
	printf("Delete\n");
	freeDAInt(anArray);
	printf("Done\n");
	system("pause"); 
}