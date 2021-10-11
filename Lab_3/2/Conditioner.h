#pragma once
#include "Appliances.h"

class Conditioner : public Appliances
{
public:
	enum class ConditionerMode
	{
		Turbo = 10,
		Cool = 15,
		Fan = 25,
		Heat = 35
	};

protected:
	double temperature;
	ConditionerMode mode;
	double power;
	bool powerOnTheDevice;

public:
	Conditioner(string firm, string model, double temperature, double weight, int yearOfIssue, double power);
	virtual void control(double temperature);
};

