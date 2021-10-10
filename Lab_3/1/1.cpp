#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "ExpressionEvaluator.h"
#include "IShuffle.h"
#include "Divisor.h"
#include "Multiplier.h"
#include "CustomExpressionEvaluator.h"

int main()
{
	ExpressionEvaluator* evaluators[3];

	evaluators[0] = new CustomExpressionEvaluator(5);
	evaluators[0]->setOperand(0, 5);
	evaluators[0]->setOperand(1, 16);
	evaluators[0]->setOperand(2, -3);
	evaluators[0]->setOperand(3, 10);
	evaluators[0]->setOperand(4, 12);

	evaluators[1] = new Multiplier(5);
	double mul_operands[] = { 1.5, 4, -2.5, - 8, -15 };
	evaluators[1]->setOperands(mul_operands, 5);

	evaluators[2] = new Divisor(3);
	double div_operands[] = { 150, -3, 10, -2.5 };
	evaluators[2]->setOperands(div_operands, 3);

	for (int i = 0; i < 3; ++i) 
	{
		evaluators[i]->logToFile("Lab3.log");
		evaluators[i]->logToScreen();
		std::cout << evaluators[i]->calculate() << std::endl;
	}

	cout << "\n" << endl;

	for (int i = 0; i < 3; i++) 
	{
		if (typeid(*evaluators[i]) == typeid(Divisor) || typeid(*evaluators[i]) == typeid(CustomExpressionEvaluator))
		{
			evaluators[i]->shuffle();			
			evaluators[i]->logToScreen();
			cout << evaluators[i]->calculate() << std::endl;
		}	
	}

	delete evaluators[0];
	delete evaluators[1];
	delete evaluators[2];

	return 0;
}