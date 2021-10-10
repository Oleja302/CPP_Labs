#pragma once
#include <string>
#include "IControllable.h"
using namespace std;

class Appliances : public IControllable
{
protected:
	string firm;
	string model;
	double weight;
	int yearOfIssue;

public:
	Appliances(string firm, string model, double weight, int yearOfIssue);
};


