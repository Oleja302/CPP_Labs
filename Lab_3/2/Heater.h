#pragma once
#include "Appliances.h"

class Heater : public Appliances
{
public:
	enum class HeaterMode
	{
		Dry = 30,
		Warm = 45
	};

protected:
	double temperature;
	HeaterMode mode;
	double power;
	bool powerOnTheDevice;

public:
	Heater(string firm, string model, double temperature, double weight, int yearOfIssue, HeaterMode mode, double power);
	
	virtual void control(double temperature);
};

