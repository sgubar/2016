#include<stdio.h>
#include"ordArray.h"
#include "BinaryRecursive.h"
#include "find.h"
#include <time.h>


void main()
{

	ordArrayPtr anArray = oa_create(10000);

	srand(time(NULL));
	for (int i = 0;i < 10000;i++) oa_insert(anArray, rand());

	int randomIndex = rand()%10000;

	printf("Lets Find number %d at index %d\n",anArray1->storage[randomIndex],randomIndex);



	clock_t theStart1 = clock();
	int index=BinaryFound(anArray, anArray->storage[randomIndex],0,anArray->size);
	clock_t theEnd1 = clock();
	
	printf("index = %d\n time = %.10lf\n", index, (double)(theEnd1 - theStart1) / CLOCKS_PER_SEC);

	printf("Start test a line find...\n");

	clock_t theStart2 = clock();
	index = line_find(anArray->storage, anArray->size, anArray->storage[randomIndex]);
	clock_t theEnd2 = clock();
	
	printf("index = %d\n time = %.10lf\n", index, (double)(theEnd2 - theStart2) / CLOCKS_PER_SEC);

	system("pause");
}