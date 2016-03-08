#include <stdio.h>
#include <stdlib.h>

#include"InputHEX.h"
#include"Input.h"
#include"Math.h"

int doInputHEX();

int main()
{
	printf("Enter a number B\n");
	int numberB = doInput();
	printf("Enter a number D\n");
	int numberD = doInput();
	
	
	Sub(numberB);
	Sum(Sub(numberB), numberD);
	
	system("pause");
}
