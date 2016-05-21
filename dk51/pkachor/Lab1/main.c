#include <stdio.h>
#include "checkCorectInput.h"
#include "inputOutputString.h"
#include "convertation.h"

#define MAX 100

int main(int argc, char *argv[]) {
	char string[MAX];
	int max = MAX;
	int switcher = 0;
	printString("This is program of notation scale convertation\n");
	while(1)
	{
		printString("Please, choose the system which will be converted.\nPress 1 - Binary, 2 - Decimal, 3 - Octal, 4 - Hexadecimal\n");
		scanString(string, max);
		if(checkCorectDecimal(string)  && convertationDecimalToInt(string) < 5)
		{
		switcher = convertationDecimalToInt(string);
		switch(switcher)
		{
			case 1:
				printString("Please, choose the system which is being converted.\nPress 1 - Binary, 2 - Decimal, 3 - Octal, 4 - Hexadecimal\n");
				scanString(string, max);
				if(checkCorectDecimal(string) && convertationDecimalToInt(string) < 5)
				{
				switcher = convertationDecimalToInt(string);
				printString("Please, input binary number less than 24 bit\n");
				scanString(string,max);
				if(checkCorectBinary(string))
					switch(switcher)
					{
						case 1: convertationIntToBinary(convertationBinaryToInt(string),string);
						printString(string);
						printString("\n");
							break;
						case 2:
							convertationIntToDecimal(convertationBinaryToInt(string),string);
						printString(string);
						printString("\n");
							break;
						case 3:
							convertationIntToOctal(convertationBinaryToInt(string),string);
						printString(string);
						printString("\n");
							break;
						case 4:
							convertationIntToHexadecimal(convertationBinaryToInt(string),string);
						printString(string);
						printString("\n");
							break;
						default:
							printString("Uncorect input\n");
							break;
					}
				}
				else
				{
					printString("Uncorect input\n");
				}
				break;
			case 2:
				printString("Please, choose the system which is being converted.\nPress 1 - Binary, 2 - Decimal, 3 - Octal, 4 - Hexadecimal\n");
				scanString(string, max);
				if(checkCorectDecimal(string) && convertationDecimalToInt(string) < 5)
				{
				switcher = convertationDecimalToInt(string);
				printString("Please, input decimal number less than 16.777.215\n");
				scanString(string,max);
				if(checkCorectDecimal(string))
					switch(switcher)
					{
						case 1: convertationIntToBinary(convertationDecimalToInt(string),string);
						printString(string);
						printString("\n");
							break;
						case 2:
							convertationIntToDecimal(convertationDecimalToInt(string),string);
						printString(string);
						printString("\n");
							break;
						case 3:
							convertationIntToOctal(convertationDecimalToInt(string),string);
						printString(string);
						printString("\n");
							break;
						case 4:
							convertationIntToHexadecimal(convertationDecimalToInt(string),string);
						printString(string);
						printString("\n");
							break;
						default:
							printString("Uncorect input\n");
							break;
					}
					else
				{
					printString("Uncorect input\n");
				}
				
				break;
			case 3:
				printString("Please, choose the system which is being converted.\nPress 1 - Binary, 2 - Decimal, 3 - Octal, 4 - Hexadecimal\n");
				scanString(string, max);
				if(checkCorectDecimal(string)  && convertationDecimalToInt(string) < 5)
				{
				switcher = convertationDecimalToInt(string);
				printString("Please, input octal number less than 77777777\n");
				scanString(string,max);
				if(checkCorectOctal(string))
					switch(switcher)
					{
						case 1: convertationIntToBinary(convertationOctalToInt(string),string);
						printString(string);
						printString("\n");
							break;
						case 2:
							convertationIntToDecimal(convertationOctalToInt(string),string);
						printString(string);
						printString("\n");
							break;
						case 3:
							convertationIntToOctal(convertationOctalToInt(string),string);
						printString(string);
						printString("\n");
							break;
						case 4:
							convertationIntToHexadecimal(convertationOctalToInt(string),string);
						printString(string);
						printString("\n");
							break;
						default:
							printString("Uncorect input\n");
							break;
					}
				}
				else
				{
					printString("Uncorect input\n");
				}
				break;
			case 4:
				printString("Please, choose the system which is being converted.\nPress 1 - Binary, 2 - Decimal, 3 - Octal, 4 - Hexadecimal\n");
				scanString(string, max);
				if(checkCorectDecimal(string)  && convertationDecimalToInt(string) < 5)
				{
				switcher = convertationDecimalToInt(string);
				printString("Please, input hexadecimal number less than FFFFFF(upper format only)\n");
				scanString(string,max);
				if(checkCorectHexadecimal(string))
					switch(switcher)
					{
						case 1: convertationIntToBinary(convertationHexadecimalToInt(string),string);
						printString(string);
						printString("\n");
							break;
						case 2:
							convertationIntToDecimal(convertationHexadecimalToInt(string),string);
						printString(string);
						printString("\n");
							break;
						case 3:
							convertationIntToOctal(convertationHexadecimalToInt(string),string);
						printString(string);
						printString("\n");
							break;
						case 4:
							convertationIntToHexadecimal(convertationHexadecimalToInt(string),string);
						printString(string);
						printString("\n");
							break;
						default:
							printString("Uncorect input\n");
							break;
					}
					}
					else
				{
					printString("Uncorect input\n");
				}
				break;
				}
		}
		}
			else
				{
					printString("Uncorect input\n");
				}
		printString("\nIf you want to end press 0, if you want to continue press another digit\n");
		scanString(string, max);
		if(checkCorectDecimal(string))
		{
			if(convertationDecimalToInt(string))
			{
				continue;
			}
		}
		else
		{
			break;
		}
	}
	return 0;
}


