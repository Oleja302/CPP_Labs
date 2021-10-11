#pragma once
#include "ExpressionEvaluator.h"

class Multiplier : public ExpressionEvaluator
{
public:
	Multiplier() : ExpressionEvaluator(20) {} 

	Multiplier(int n) : ExpressionEvaluator(n) {};

	virtual double calculate();
};

