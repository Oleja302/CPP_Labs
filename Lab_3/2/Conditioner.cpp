#include "Conditioner.h"
#include <iostream>

Conditioner::Conditioner(string firm, string model, double temperature ,double weight, int yearOfIssue, ConditionerMode mode, double power) :
		Appliances(firm, model, weight, yearOfIssue)
	{
		this->mode = mode;
		this->power = power;
		this->powerOnTheDevice = true;
		control(temperature);
	}

	void Conditioner::control(double temperature)
	{
		if (temperature < 10)
		{
			cout << "Power off" << endl;
			powerOnTheDevice = false;
		}

		else
		{
			this->temperature = temperature;
			mode = (ConditionerMode)temperature;
		}
	}