#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class Divisor : public ExpressionEvaluator, public IShuffle
{
public:
	Divisor() : ExpressionEvaluator(20) {}

	Divisor(int n) : ExpressionEvaluator(n) {};

	virtual void shuffle();

	virtual void shuffle(int i, int j);

	virtual double calculate();
};

