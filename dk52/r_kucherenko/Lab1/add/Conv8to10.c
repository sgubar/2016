#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	int val;
	int sum = 0;
	char oct_val[20];
	printf("Enter the number:\n");
	gets(oct_val);
	for(i =0;i<strlen(oct_val);i++)
	{
		sum = sum*8+oct_val[i]-'0';
	}
	printf("%d\n",sum);
	return 0;
}
