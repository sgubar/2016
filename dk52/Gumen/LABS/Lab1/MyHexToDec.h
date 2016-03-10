#include <stdio.h>

int NumOfDigits(char num []);
int MyDecimal (int numberOFdigits, char characters[]);

//Input:an hexadecimal number (8 bits max)
//Output:number of digits in the number
int NumOfDigits(char num[])
{
	int i;
	while (num[i]!='\0')
		++i;
	return i;	
}

//Input: the number of digits in the hex (nd) and the hex number itself (ch)
//Output: the number converted from hex to decimal
int MyDecimal (int nd, char ch[]){
	int f=0,d1,d2;
	//printf("%d\n",nd);
	//printf("%c",ch[0]);
	if (nd==1||nd==2)
	{	
	if (nd==1)
	{
		switch(ch[0])
		{
		case '0':f=0;break;
		case '1':f=1;break;
		case '2':f=2;break;
		case '3':f=3;break;
		case '4':f=4;break;
		case '5':f=5;break;
		case '6':f=6;break;
		case '7':f=7;break;
		case '8':f=8;break;
		case '9':f=9;break;
		case 'A':f=10;break;
		case 'B':f=11;break;
		case 'C':f=12;break;
		case 'D':f=13;break;
		case 'E':f=14;break;
		case 'F':f=15;break;
		default: printf("Error:hex number not recognised.F=0.\n");
		
		}
	}
	if (nd==2)
	{
		switch(ch[0])
		{
		case '0':d1=0;break;
		case '1':d1=1;break;
		case '2':d1=2;break;
		case '3':d1=3;break;
		case '4':d1=4;break;
		case '5':d1=5;break;
		case '6':d1=6;break;
		case '7':d1=7;break;
		case '8':d1=8;break;
		case '9':d1=9;break;
		case 'A':d1=10;break;
		case 'B':d1=11;break;
		case 'C':d1=12;break;
		case 'D':d1=13;break;
		case 'E':d1=14;break;
		case 'F':d1=15;break;
		default: printf("Error:hex number not recognised. F=0.\n");	
		}
		switch(ch[1])
		{
		case '0':d2=0;break;
		case '1':d2=16*1;break;
		case '2':d2=16*2;break;
		case '3':d2=16*3;break;
		case '4':d2=16*4;break;
		case '5':d2=16*5;break;
		case '6':d2=16*6;break;
		case '7':d2=16*7;break;
		case '8':d2=16*8;break;
		case '9':d2=16*9;break;
		case 'A':d2=16*10;break;
		case 'B':d2=16*11;break;
		case 'C':d2=16*12;break;
		case 'D':d2=16*13;break;
		case 'E':d2=16*14;break;
		case 'F':d2=16*15;break;
		default: printf("Error:hex number not recognised. F=0.\n");
		}
		f=d1+d2;
	}
	}
	else
	printf("Error:hex number exceeds 8 bits. F=0.\n");
		
	return f;
}
