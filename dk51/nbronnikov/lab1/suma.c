#include <stdio.h>
#include <math.h>

float suma(float A, float D) {
	float Q;
	for (; D <= A; D++);
	Q = (powf(2, (D + A)) - powf(2, A));

	return(Q);
}
