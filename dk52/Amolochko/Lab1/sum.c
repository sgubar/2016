#include <stdio.h>
#include "fact.h"

int dosum(int A, int C)
{
	int D, rez, z;
	for (D=A;D<=C+A;D++)
		{
			z=fact(D);
			rez += z;
		}
	return rez;
}
