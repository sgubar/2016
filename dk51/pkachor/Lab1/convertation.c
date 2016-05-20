#include<stdio.h>
long int convertationDecimalToInt(char *string)
{
	int number = 0;
	while(*string)
	{
		number = number * 10 + *string++ - '0';
	}
	return number;
}

long int convertationBinaryToInt(char *string)
{
	int number = 0;
	while(*string)
	{
		number = number * 2 + *string++ -'0';
	}
	return number;
}

long int convertationOctalToInt(char *string)
{
	int number = 0;
	while(*string)
	{
		number = number * 8 + *string++ -'0';
	}
	return number;
}

long int convertationHexadecimalToInt(char *string)
{
	int number = 0;
	while(*string)
	{
		if((*string >= '0')&& (*string <= '9'))
		{
			number = number * 16 + *string++ -'0';
		}
		else if ((*string >= 'A') && (*string <= 'F'))
		{
			number = number * 16 + *string++ -'A' + 10;
		}
	}
	return number;
}

void convertationIntToBinary(long int number, char *string)
{
	char bufer[100];
	int index = 0;
		do
	{
		bufer[index++] = (number%2) +'0';
	}
	while(number/=2);   
	while(index)
	{
		*string++ = bufer[index-- - 1];
	}
	*string = '\0';
}

void convertationIntToDecimal(long int number, char *string)
{
	char bufer[100];
	int index = 0;
		do
	{
		bufer[index++] = (number%10) +'0';
	}
	while(number/=10);   
	while(index)
	{
		*string++ = bufer[index-- - 1];
	}
	*string = '\0';
}

void convertationIntToOctal(long int number, char *string)
{
	char bufer[100];
	int index = 0;
		do
	{
		bufer[index++] = (number%8) +'0';
	}
	while(number/=8);   
	while(index)
	{
		*string++ = bufer[index-- - 1];
	}
	*string = '\0';
}

void convertationIntToHexadecimal(long int number, char *string)
{
	char bufer[100];
	int index = 0;
		do
	{
		if((number%16 >= 0) && (number%16 <= 9))
		{
			bufer[index++] = (number%16) +'0';
		}
		else if((number%16 >= 10) && (number%16 <=15))
		{
			bufer[index++] = (number%16) - 10 + 'A';
		}
	}
	while(number/=16);   
	while(index)
	{
		*string++ = bufer[index-- - 1];
	}
	*string = '\0';
}
