#include <stdio.h>
#include <stdlib.h>
#include "ord_array.h"
#include "recursive_search.h"
#include "linear_find.h"
#include <time.h>


int main()
{
	printf("Start test:\n");
	printf("Create an array...\n");

	ordArrayPtr anArray1 = oa_create(10000);

	srand(time(NULL));
	for (int i = 0;i < 1000;i++) oa_insert(anArray1, rand());

	int randomIndex = rand()%1000;

	printf("Lets Find number %d at index %d\n",anArray1->storage[randomIndex],randomIndex);

	printf("Start test a binary find...\n");

	clock_t theStart1 = clock();
	int index=BinaryFound(anArray1, anArray1->storage[randomIndex],0,anArray1->size);
	clock_t theEnd1 = clock();

	printf("index = %d\n time = %.10f\n", index, (double)(theEnd1 - theStart1) / CLOCKS_PER_SEC);

	printf("Start test a line find...\n");

	clock_t theStart2 = clock();
	index = linear_find(anArray1->storage, anArray1->size, anArray1->storage[randomIndex]);
	clock_t theEnd2 = clock();

	printf("index = %d\n time = %.10f\n", index, (double)(theEnd2 - theStart2) / CLOCKS_PER_SEC);


    clock_t theStart3 = clock();
	index = oa_find(anArray1, anArray1->storage[randomIndex]);
	clock_t theEnd3 = clock();

	printf("index = %d\n time = %.10f\n", index, (double)(theEnd3 - theStart3) / CLOCKS_PER_SEC);


	system("pause");
    return 0;
}
