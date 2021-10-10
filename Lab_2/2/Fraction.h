#pragma once

class Fraction
{
public:
	

private:
	int _x;
	int _y;
	static int count;

public:
	Fraction();
	Fraction(int x, int y);

	Fraction operator+(Fraction f);
	Fraction operator-(Fraction f);
	Fraction operator/(Fraction f);
	Fraction operator*(Fraction f);

	void reduce();
	static int GetCount();

	static int gcd(int n, int m);
	static void printAsFraction(double decimal_fraction);
	static void printAsFraction(char* decimal_fraction);
	static void printAsFraction(Fraction f);
};