#include <stdio.h>
#include <stdlib.h>

float getFloat()
{
	float number = 0;
	char *w, c;
	w = (char *)calloc(1, 50);
	int i = 0;
	while (1)
	{
		c = getchar();
		if (c == 10) break;
		w[i] = c;
		i++;
	}

	number = atof(w);


	return number;
}

int getInt()
{
	float number = 0;
	char *w, c;
	w = (char *)calloc(1, 50);
	int i = 0;
	while (1)
	{
		c = getchar();
		if (c == 10) break;
		w[i] = c;
		i++;
	}

	number = atoi(w);


	return number;
}


void inputParams(int *a, float *b, int *c)
{
	char answer = 'n';

	while (answer != 'y')
	{
		printf("\n \t Don't forget (B+C)>=0 | B!=0 | A>=0 | C>=0 } A&C are INTEGER\n");

		printf("Input A:");
		*a = getInt();

		printf("Input B:");
		*b = getFloat();

		printf("Input C:");
		*c = getInt();

		printf("\n\t\t\t\tYou've inputed:\n");
		printf("\t\tA=%i \t B=%f \t C=%i", *a, *b, *c);

		printf("\n\n\n \t \t Is this data correct?(y - Yes,n - No)\n\t\t\t\t");
		answer = getchar();

		if (answer != 'y') printf("\t\t\tTry it again!\n\n");
		getchar();
		printf("\n\n");

	}
}
