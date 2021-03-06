#include "Heater.h"
#include <iostream>

Heater::Heater(string firm, string model, double temperature, double weight, int yearOfIssue, double power) :
	Appliances(firm, model, weight, yearOfIssue)
{
	this->power = power;
	this->powerOnTheDevice = true;
	control(temperature);
}

void Heater::control(double temperature)
{
	if (temperature > 45)
	{
		cout << "Power off" << endl;
		powerOnTheDevice = false;
	}

	else
	{
		this->temperature = temperature;
		this->mode = (HeaterMode)temperature;
	}
}