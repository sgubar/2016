//program when will calculate sqrt 
#include <stdio.h>
#include <math.h>



float suma(float a, float d) {
	float q;
	for (d;d<=a;d++)
	q = (powf(2, (d + a)) - powf(2, a));

	return q;
}
