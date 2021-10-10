#pragma once
#include <string>
using namespace std;

enum Mode
{
	Cool = 0,
	Heat,
	Dry,
	Fan,
	Turbo,
	Quiet,
	Auto
};

static const char* EnumStrings[] { "Cool", "Heat", "Dry", "Fan", "Turbo", "Quiet", "Auto" };

class Conditioner
{
private:
	string firm;
	string model;
	double weight;
	double temperature;
	int mode;
	int yearOfIssue;

public:
	Conditioner();
	Conditioner(string firm, string model, double weight, int yearOfIssue);

	void serialize();
	void deserialize();
	void serialize(const std::string& filename);
	void deserialize(const std::string& filename);

	void SetFirm(string firm);
	void SetModel(string model);
	void SetWeight(double weight);
	void SetTemperature(double temperature);
	void SetMode(int mode);
	void SetYearOfIssue(int yearOfIssue);

	string GetFirm();
	string GetModel();
	double GetWeight();
	double GetTemperature();
	int GetMode();
	int GetYearOfIssue();
};
