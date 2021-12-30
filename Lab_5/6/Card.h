#pragma once
#include <iostream>

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
	
	friend void operator << (wostream& out, const Card& card);
};

