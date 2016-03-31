#include "factorial.h"

float factorial(int a) {

	if (a == 1) return 1;
	return a*factorial(a - 1);

}
