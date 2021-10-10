#include <iostream>
#include <string>
#include "Conditioner.h"
using namespace std;

int main()
{
	Conditioner* c1 = new Conditioner("Samsung", "A95", 35, 2015);
	Conditioner* c2 = new Conditioner("Xiaomi", "X-103", 45, 2013);
	Conditioner c3;
	c3.SetFirm("Microsoft");
	c3.SetModel("B25");
	c3.SetWeight(50);
	c3.SetYearOfIssue(2019);

	double sumTemperature = 0;

	//First setting
	c1->SetMode(Fan);
	c2->SetMode(Cool);
	c2->SetTemperature(15);
	c3.SetMode(Quiet);

	cout << c1->GetModel() << ": " << "mode = " << EnumStrings[c1->GetMode()] << endl;
	cout << c2->GetModel() << ": " << "mode = " << EnumStrings[c2->GetMode()] << endl;
	cout << c3.GetModel() << ": " << "mode = " << EnumStrings[c3.GetMode()] << endl << endl;

	sumTemperature += c2->GetTemperature();

	//Second setting
	c1->SetMode(Cool);
	c1->SetTemperature(10);
	c2->SetMode(Fan);
	c3.SetMode(Heat);

	cout << c1->GetModel() << ": " << "mode = " << EnumStrings[c1->GetMode()] << endl;
	cout << c2->GetModel() << ": " << "mode = " << EnumStrings[c2->GetMode()] << endl;
	cout << c3.GetModel() << ": " << "mode = " << EnumStrings[c3.GetMode()] << endl << endl;

	sumTemperature += c1->GetTemperature();

	//Thirs setting
	c1->SetMode(Dry);
	c2->SetMode(Cool);
	c2->SetTemperature(5);
	c3.SetMode(Auto);

	cout << c1->GetModel() << ": " << "mode = " << EnumStrings[c1->GetMode()] << endl;
	cout << c2->GetModel() << ": " << "mode = " << EnumStrings[c2->GetMode()] << endl;
	cout << c3.GetModel() << ": " << "mode = " << EnumStrings[c3.GetMode()] << endl << endl;

	sumTemperature += c2->GetTemperature();

	cout << "Average temperature = " << sumTemperature / 3 << endl;

	delete c1;
	delete c2;
}

