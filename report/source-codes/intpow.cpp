#include "intpow.h"

int intPow(int base, int exponent)
{
	int res = 1;
	if (base == 0)
		return 0;
	else if (exponent == 0)
		return 1;
	else if (exponent == 1)
		return base;
	else {
		for (int i = 0; i < exponent; ++i)
			res *= base;
	}
	return res;
}
