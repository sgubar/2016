#include <stdio.h>
#include "formula.h"

int main(int argc, char *argv[])
{
	if (argc == 4)
		calculate(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	else 
		printf("Error! \nSyntax: '<A> <B> <C>'\n");
	system("pause");
}