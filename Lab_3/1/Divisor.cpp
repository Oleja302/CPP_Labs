#include "Divisor.h"

void Divisor::shuffle()
{
	double tmp;

	for (int i = 1; i < countValue; i++)
		for (int j = i; j > 0 && pValue[j - 1] > pValue[j]; j--)
		{
			tmp = pValue[j - 1];
			pValue[j - 1] = pValue[j];
			pValue[j] = tmp;
		}
}

void Divisor::shuffle(int i, int j)
{
	double tmp;
	tmp = pValue[i];
	pValue[i] = pValue[j];
	pValue[j] = tmp;
}

double Divisor::calculate()
{
	double result = pValue[0];

	for (int i = 1; i < countValue; i++)
	{
		if (pValue[i] == 0) return 0;
		result /= pValue[i];
	}

	return result;
}
