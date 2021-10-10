#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class Divisor : public ExpressionEvaluator
{
public:
	Divisor() : Divisor(20) {}

	Divisor(int n);

	virtual void shuffle();

	virtual void shuffle(int i, int j);

	virtual double calculate();
};

