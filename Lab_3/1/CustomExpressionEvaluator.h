#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class CustomExpressionEvaluator : public ExpressionEvaluator
{
public:
	CustomExpressionEvaluator() : CustomExpressionEvaluator(20) {}

	CustomExpressionEvaluator(int n);

	virtual void shuffle();
	virtual void shuffle(int i, int j);

	virtual double calculate();

};

