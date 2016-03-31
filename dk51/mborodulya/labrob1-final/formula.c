
#include "formula.h"
#include "factorial.h"
#include "abs.h"

float formula(int a, float b) {

	return factorial(a) / abs(a * 2 + b);

}
