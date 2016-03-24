#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
char* getString()
{
	FILE *file;
	bool fileCorrect = false;
	char string[6];

	while (fileCorrect == false)
	{
		printf("Please input strings with 6 symbols to file 'in.txt' and press ENTER\n");
		getchar();
		
		file = fopen("in.txt", "r");
		if ((file = fopen("in.txt", "r")) == 0) {
			printf("Error of opening file!");
		}
		else
		{

			
				fgets(string,6, file);
				
			
			printf("Is this correct?\n%s \n", string);
			char answer = getchar();

			if (answer == 'y')
			{
				
				fileCorrect = true;
			}
			else
			{
				printf("Change data file and press ENTER");
				getchar();
				getchar();
			}
		}

	}
	return string;
}
