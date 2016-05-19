#include<stdio.h>

int pow(chislo, stepen)
{
	int index;
	int number;

	if (stepen == 0)
		return 1;

	else if (stepen == 1)
		return chislo;

	else if (stepen > 1)
	{
		number = chislo;
		for (index = 1; index < stepen; index++)
			chislo = chislo * number;

		return chislo;
	}
}
