#include "inputOutputString.h"

int checkCorectDecimal(char *string)
{
	if(*string == '0')
	{
		printString("Uncorect input");
		return 0;
	}
	int count = 0;
	while(*string)
	{	
		count++;	
		if((*string > '9') || (*string < '0'))
		{
			printString("Uncorect input\n");
			return 0;
		}
		if(count == 8)
		{
			if(*(string - 7) == '1')
			{
				if(*(string -6)=='6')
				{
					if(*(string - 5) =='7')
					{
						if(*(string - 4) =='7')
						{
							if(*(string -3) =='7')
							{
								if(*(string -2)=='2')
								{
									if(*(string -1) =='1')
									{
										if(*string <= '5')
										{
											;
										}
										else
										{
											printString("Uncorect input\n");
											return 0;
										}
									}
									else if(*(string -1) >='1')
									{
										printString("Uncorect input\n");
										return 0;
									}
								}
								else if(*(string -2) >='2')
								{
									printString("Uncorect input\n");
									return 0;
								}
							}
							else if(*(string -3) >='7')
							{
								printString("Uncorect input\n");
								return 0;
							}
						}
						else if(*(string -4) >='7')
						{
							printString("Uncorect input\n");
							return 0;
						}
					}
					else if(*(string -5) >='7')
					{
						printString("Uncorect input\n");
						return 0;
					}
				}
				else if(*(string -6) >='6')
				{
					printString("Uncorect input\n");
					return 0;
				}
				
			}
			else if(*string >='1')
			{
				printString("Uncorect input\n");
				return 0;
			}
		}
		
		if(count > 8 )
		{
			printString("Uncorect input\n");
			return 0;
		}
		string++;
	}
	return 1;
}

int checkCorectHexadecimal(char *string)
{
	if(*string == '0')
	{
		printString("Uncorect input\n");
		return 0;
	}
	int count = 0;
	while(*string)
	{	
		count++;
		if((((*string > '9') || (*string < '0')) && ((*string < 'A') || (*string > 'F')))&&(count > 6))
		{
			printString("Uncorect input\n");
			return 0;
		}
		string++;
	}
	return 1;
}

int checkCorectOctal(char *string)
{
	if(*string == '0')
	{
		printString("Uncorect input\n");
		return 0;
	}
	int count = 0;
	while(*string)
	{	
		count++;	
		if(((*string > '7') || (*string < '0'))&&(count > 8))
		{
			printString("Uncorect input\n");
			return 0;
		}
		string++;
	}
	return 1;
}

int checkCorectBinary(char *string)
{
	if(*string == '0')
	{
		printString("Uncorect input\n");
		return 0;
	}
	int count = 0;
	while(*string)
	{	
		count++;	
		if(((*string > '1') || (*string < '0'))&&count>24)
		{
			printString("Uncorect input\n");
			return 0;
		}
		string++;
	}
	return 1;
}
