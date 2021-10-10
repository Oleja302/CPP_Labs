#include <iostream>
#include <string>
#include "Appliances.h"
#include "Conditioner.h"
#include "Heater.h"

using namespace std;

int main()
{
	Appliances* appliances[3];

	appliances[0] = new Conditioner("Apple", "ARM M1", 15, 30.5, 2015, Conditioner::ConditionerMode::Cool, 50);
	appliances[1] = new Conditioner("Microsoft", "Windows11", 15, 30.5, 2021, Conditioner::ConditionerMode::Fan, 50);
	appliances[2] = new Heater("Jimbo", "T-1000", 15, 30.5, 2021, Heater::HeaterMode::Dry, 50);

	for (int i = 0; i < 3; ++i)
	{
		if (typeid(*appliances[0]) == typeid(Conditioner)) appliances[0]->control(5);
		else if (typeid(*appliances[0]) == typeid(Heater)) appliances[0]->control(65);
	}

	delete appliances[0];
	delete appliances[1];
	delete appliances[2];
}

