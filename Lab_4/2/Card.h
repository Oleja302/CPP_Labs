#pragma once
#include <string>
using namespace std;

class Card
{
private:
	int power;
	wstring surface;

public:
	Card();
	Card(int newPower, wstring newSurface);
	void SetPower(int power);
	void SetSurface(wstring surface);
	int GetPower();
	wstring GetSurface();
};
