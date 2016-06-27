/*																 /
/  main.c			                                             / 
/  compare sort                                                  /
/                                                                / 
/  Created by Sergey Ninoshvili on 25/6/16.                      /
/  Copyright © 2016 Sergey Ninoshvili. All rights reserved.      /
/																*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "SimpleSort.h"
#include "shellSort.h"
#include "quickSort.h"
#include "compare.h"

int main(int argc, const char * argv[])
{
	bubbleRezult();

	selectionRezult();

	insertionRezult();

	shellRezult();

	quickRezult();

	system("pause");
}
