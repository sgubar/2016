#include "Output.h"

void Output(int *dynarray, int N_f)
{
	printf("An updated array:\n");
	for (int indx_f = 0; indx_f < N_f; indx_f++)
		printf("%d\t", dynarray[indx_f]);
}
