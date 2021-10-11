#include "CustomExpressionEvaluator.h"

void CustomExpressionEvaluator::shuffle()
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

void CustomExpressionEvaluator::shuffle(int i, int j)
{	
	double tmp;
	tmp = pValue[i];
	pValue[i] = pValue[j];
	pValue[j] = tmp;
}

double CustomExpressionEvaluator::calculate()
{
	double result = pValue[0];

	for (int i = 1; i < countValue; i += 2)
	{
		if (i + 1 >= countValue)
		{
			result += pValue[i];
			return result;
		}

		result += pValue[i] * pValue[i + 1];
	}

	return result;
}