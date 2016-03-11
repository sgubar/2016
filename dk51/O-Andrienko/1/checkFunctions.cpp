#include <stdio.h>
#include <stdlib.h>
bool checkparams(int a,float b, int c)
{
	bool paramsright = true;

		if ((b + c) < 0)
		{
			paramsright = false;
			printf("\t\t\t\t Hoho! It's FAIL. \n\tYour data does not satisfy the region of permissible values.\n\t\t\t\tTry it again!");
			printf("\n\t\t\t\tB+C=%.1f <0\n", b + c);
		}

		if (b == 0)
		{
			paramsright = false;
			printf("\t\t\t\t Hoho! It's FAIL. \n\t\t\t B=0; It's Dividing by zero \n\t\t\t\tTry it again!\n");

		}

		if (a < 0)
		{
			paramsright = false;
			printf("\t\t\t\t Hoho! It's FAIL. \n\t\t\t A<0; \n\t\t\t\tTry it again!\n");
			printf("\n\t\t\t\t !(%f+0)=%.1f <0\n", a, a);
		}
		if (c < 0)
		{
			paramsright = false;
			printf("\t\t\t\t Hoho! It's FAIL. \n\t\t\t C<0; \n\t\t\t\tTry it again!\n");
			printf("\n\t\t\t\t %i<0\n", c);
		}
		return paramsright;
}

