#include "ExpressionEvaluator.h"
#include "Divisor.h"
#include "Multiplier.h"
#include "CustomExpressionEvaluator.h"

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

ExpressionEvaluator::ExpressionEvaluator(int n)
{
	countValue = n;
	pValue = new double[countValue] {};
}

ExpressionEvaluator::~ExpressionEvaluator()
{
	delete pValue;
};

void ExpressionEvaluator::logToScreen()
{
	string result = "";
	string integer = "";
	bool flag = true;

	for (int i = 0; i < countValue; i++)
	{
		if (i == countValue - 1)
		{
			if (pValue[i] < 0)
			{
				integer = to_string(pValue[i]);
				integer.erase(integer.find_last_not_of('0') + 2, std::string::npos);
				result += "(" + integer + ")";
			}
			else
			{
				integer = to_string(pValue[i]);
				integer.erase(integer.find_last_not_of('0') + 2, std::string::npos);
				result += integer;
			}

			break;
		}

		if (pValue[i] < 0)
		{
			integer = to_string(pValue[i]);
			integer.erase(integer.find_last_not_of('0') + 2, std::string::npos);
			result += "(" + integer + ")";
		}
		else
		{
			integer = to_string(pValue[i]);
			integer.erase(integer.find_last_not_of('0') + 2, std::string::npos);
			result += integer;
		}

		if (typeid(*this) == typeid(CustomExpressionEvaluator))
		{
			if (flag) result += "+";
			else result += "*";
			flag = !flag;
		}

		if (typeid(*this) == typeid(Divisor)) result += "/";
		if (typeid(*this) == typeid(Multiplier)) result += "*";
	}

	result += " <Total " + to_string(countValue) + "> ";

	integer = to_string(calculate());
	integer.erase(integer.find_last_not_of('0') + 2, std::string::npos);

	result += "<Result " + integer + "> ";

	cout << result << endl;
}

void ExpressionEvaluator::logToFile(const string& filename)
{
	string result = "";
	string integer = "";
	bool flag = true;

	for (int i = 0; i < countValue; i++)
	{
		if (i == countValue - 1)
		{
			if (pValue[i] < 0)
			{
				integer = to_string(pValue[i]);
				integer.erase(integer.find_last_not_of('0') + 2, std::string::npos);
				result += "(" + integer + ")";
			}
			else
			{
				integer = to_string(pValue[i]);
				integer.erase(integer.find_last_not_of('0') + 2, std::string::npos);
				result += integer;
			}

			break;
		}

		if (pValue[i] < 0)
		{
			integer = to_string(pValue[i]);
			integer.erase(integer.find_last_not_of('0') + 2, std::string::npos);
			result += "(" + integer + ")";
		}
		else
		{
			integer = to_string(pValue[i]);
			integer.erase(integer.find_last_not_of('0') + 2, std::string::npos);
			result += integer;
		}

		if (typeid(*this) == typeid(CustomExpressionEvaluator))
		{
			if (flag) result += "+";
			else result += "*";
			flag = !flag;
		}

		if (typeid(*this) == typeid(Divisor)) result += "/";
		if (typeid(*this) == typeid(Multiplier)) result += "*";
	}

	result += " <Total " + to_string(countValue) + "> ";

	integer = to_string(calculate());
	integer.erase(integer.find_last_not_of('0') + 2, std::string::npos);

	result += "<Result " + integer + "> ";

	std::ofstream log(filename, std::ios_base::app | std::ios_base::out);
	log << result + "\n"; 
}

void ExpressionEvaluator::setOperand(int pos, double value)
{
	pValue[pos] = value;
}

void ExpressionEvaluator::setOperands(double ops[], int n)
{
	for (int i = 0; i < n; i++)
	{
		pValue[i] = ops[i];
	}
}