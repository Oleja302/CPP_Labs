#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "ILoggable.h"
#include "IShuffle.h"

class ExpressionEvaluator : public ILoggable, public IShuffle
{
protected:
	int countValue = 0;
	double* pValue;

public:
	ExpressionEvaluator() : ExpressionEvaluator(20) {}

	ExpressionEvaluator(int n);

	virtual ~ExpressionEvaluator();
	
	void logToScreen();

	void logToFile(const std::string& filename);
	
	virtual double calculate() = 0;

	void setOperand(int pos, double value);

	void setOperands(double ops[], int n);
};
