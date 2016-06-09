
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Binarry.h"

#define ARRAY_SIZE(a) (sizeof(theArray)/sizeof(theArray[0]))

	int main(int argc, const char * argv[])
	{
		//int theIndex1, theIndex2;
		ordArrayPtr theArray = binarycreate(10000);

		srand(0);
		for (int i = 0; i < 10000; i++)
		{
			binaryinsert(theArray, rand() % 5000);
		}

		printf("Test Binaryfind^ \n");
		clock_t theStart1 = clock();
		unsigned theIndex1 = binaryfind(theArray, theArray->storage[100]);
		clock_t theEnd1 = clock();
		printf("time of bubble sorting: %.15lf\n", (double)(theEnd1 - theStart1) / CLOCKS_PER_SEC);

		printf("Test LF\n");
		clock_t theStart2 = clock();
		unsigned theIndex2 = linefind(theArray, 100000, theArray->storage[100]);
		clock_t theEnd2 = clock();
		printf("time of bubble sorting: %.15lf\n", (double)(theEnd2 - theStart2) / CLOCKS_PER_SEC);



		printf("\ntheIndex: %d\n", theIndex1);
		printf("\ntheIndex: %d\n", theIndex2);

	//return 0;
	system("Pause");
}