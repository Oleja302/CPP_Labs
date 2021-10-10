#include "Multiplier.h"

Multiplier::Multiplier(int n) :ExpressionEvaluator(n) {}

double Multiplier::calculate()
{
	double result = 1;

	for (int i = 0; i < countValue; i++)
	{
		result *= pValue[i];
	}

	return result;
}