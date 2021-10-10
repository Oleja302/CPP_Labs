#pragma once
#include "ExpressionEvaluator.h"

class Multiplier : public ExpressionEvaluator
{
public:
	Multiplier() : Multiplier(20) {}

	Multiplier(int n);

	virtual double calculate();

private:
	virtual void shuffle() {}
	virtual void shuffle(int i, int j) {}
};

