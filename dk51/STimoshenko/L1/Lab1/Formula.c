#include <stdio.h>
#include <stdlib.h>
#include "Formula.h"
#include "Function.h"

float Form();

float Form(float A, float B, float C)
{
	float Formula = ((A*A + B*B) / (B + doPWR(C))) + doFCTRL(B);//Формуля для кынцевого результату
	printf("3HA4EHH9 BUPA3Y=%.3f\n", Formula);


}
