#include "Multiplier.h"

double Multiplier::calculate()
{
	double result = 1;

	for (int i = 0; i < countValue; i++)
	{
		result *= pValue[i];
	}

	return result;
}