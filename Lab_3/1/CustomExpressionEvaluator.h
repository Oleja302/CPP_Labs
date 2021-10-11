#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class CustomExpressionEvaluator : public ExpressionEvaluator, public IShuffle
{
public:
	CustomExpressionEvaluator() : ExpressionEvaluator(20) {}
	CustomExpressionEvaluator(int n) : ExpressionEvaluator(n) {};

	virtual void shuffle();
	virtual void shuffle(int i, int j);

	virtual double calculate();
};

