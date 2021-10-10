#include "Conditioner.h"
#include <fstream>

Conditioner::Conditioner()
{
	firm = "Unknown";
	model = "Unknown";
	weight = 0;
	yearOfIssue = 0;
}

Conditioner::Conditioner(string firm, string model, double weight, int yearOfIssue)
{
	SetFirm(firm);
	SetModel(model);
	SetWeight(weight);
	SetYearOfIssue(yearOfIssue);
}

void Conditioner::serialize()
{
	ofstream outf("DataConditioner.txt");
	outf << this->firm << endl;
	outf << this->model << endl;
	outf << this->weight << endl;
	outf << this->temperature << endl;
	outf << this->mode << endl;
	outf << this->yearOfIssue << endl;
}

void Conditioner::deserialize()
{
	ifstream inf("DataConditioner.txt");

	while (inf)
	{
		inf >> this->firm;
		inf >> this->model;
		inf >> this->weight;
		inf >> this->temperature;
		inf >> this->mode;
		inf >> this->yearOfIssue;
	}
}

void Conditioner::serialize(const std::string& filename)
{
	ofstream outf(filename);
	outf << this->firm << endl;
	outf << this->model << endl;
	outf << this->weight << endl;
	outf << this->temperature << endl;
	outf << this->mode << endl;
	outf << this->yearOfIssue << endl;
}

void Conditioner::deserialize(const std::string& filename)
{
	ifstream inf(filename);

	while (inf)
	{
		inf >> this->firm;
		inf >> this->model;
		inf >> this->weight;
		inf >> this->temperature;
		inf >> this->mode;
		inf >> this->yearOfIssue;
	}
}

void Conditioner::SetFirm(string firm)
{
	this->firm = firm;
}

void Conditioner::SetModel(string model)
{
	this->model = model;
}

void Conditioner::SetWeight(double weight)
{
	this->weight = weight;
}

void Conditioner::SetTemperature(double temperature)
{
	this->temperature = temperature;
}

void Conditioner::SetMode(int mode)
{
	this->mode = mode;
}

void Conditioner::SetYearOfIssue(int yearOfIssue)
{
	this->yearOfIssue = yearOfIssue;
}

string Conditioner::GetFirm()
{
	return this->firm;
}

string Conditioner::GetModel()
{
	return this->model;
}

double Conditioner::GetWeight()
{
	return this->weight;
}

double Conditioner::GetTemperature()
{
	return this->temperature;
}

int Conditioner::GetMode()
{
	return this->mode;
}

int Conditioner::GetYearOfIssue()
{
	return this->yearOfIssue;
}
