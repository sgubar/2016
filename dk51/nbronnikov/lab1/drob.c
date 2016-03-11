#include <stdio.h>


float drob(float A, float B, float C) {
	float F;
	F = ((A + B + C) / (100 - B - C));
	return (F);
}
