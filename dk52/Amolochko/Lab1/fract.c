#include <stdio.h>
#include <math.h>

int dofract(float B, float C)
{
	float frac;
	frac = (sqrt(B+C))/B;
	return frac;
}
