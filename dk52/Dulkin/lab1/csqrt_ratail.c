#include <stdio.h>


float drob(float a, float b, float c) {
	float f;
	f = ((a + b + c) / (100 - b - c));
	return (f);
}
