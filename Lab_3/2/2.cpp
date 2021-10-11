#include <iostream>
#include <string>
#include "Appliances.h"
#include "Conditioner.h"
#include "Heater.h"

using namespace std;

int main()
{
	Appliances* appliances[3];

	appliances[0] = new Conditioner("Apple", "ARM M1", 15, 30.5, 2015, 50);
	appliances[1] = new Conditioner("Microsoft", "Windows11", 15, 30.5, 2021, 50);
	appliances[2] = new Heater("Jimbo", "T-1000", 15, 30.5, 2021, 50);

	for (int i = 0; i < 3; ++i)
	{
		if (typeid(*appliances[i]) == typeid(Conditioner)) appliances[i]->control(5);
		else if (typeid(*appliances[i]) == typeid(Heater)) appliances[i]->control(65);
	}

	for (int i = 0; i < 3; i++)
		delete appliances[i];

	return 0;
}

