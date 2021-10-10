#include "Fraction.h"
#include <iostream>
using namespace std;

int Fraction::count = 0;

Fraction::Fraction() : _x(1), _y(1)
{
	count++;
}

Fraction::Fraction(int x, int y) : _x(x), _y(y)
{
	if (y == 0) throw;
	count++;
}

Fraction Fraction::operator+(Fraction f)
{
	int tmp = _y;

	_x *= f._y;
	_y *= f._y;

	f._x *= tmp;
	f._y *= tmp;

	Fraction result(_x + f._x, _y);
	count--;
	result.reduce();

	return result;
}

Fraction Fraction::operator-(Fraction f)
{
	int tmp = _y;

	_x *= f._y;
	_y *= f._y;

	f._x *= tmp;
	f._y *= tmp;

	Fraction result(_x - f._x, _y);
	count--;
	result.reduce();

	return result;
}

Fraction Fraction::operator/(Fraction f)
{
	int tmp = f._x;
	f._x = f._y;
	f._y = tmp;

	Fraction result(_x * f._x, _y * f._y);
	count--;
	result.reduce();

	return result;
}

Fraction Fraction::operator*(Fraction f)
{
	Fraction result(_x * f._x, _y * f._y);
	count--;
	result.reduce();

	return result;
}

void Fraction::reduce()
{
	//Первый вариант
	int length = Fraction::_x <= Fraction::_y ? Fraction::_x : Fraction::_y;

	for (int i = 2; i <= length; i++)
	{
		if (Fraction::_x % i == 0 && Fraction::_y % i == 0)
		{
			Fraction::_x /= i;
			Fraction::_y /= i;

			i = 1;
		}
	}

	//Второй вариант
	/*int gcd = Fraction::gcd(_x,_y);

	_x /= gcd;
	_y /= gcd;*/
}

int Fraction::GetCount()
{
	return count;
}

int Fraction::gcd(int n, int m)
{
	if (n % m == 0)
		return m;
	if (m % n == 0)
		return n;
	if (n > m)
		return gcd(n % m, m);
	return gcd(n, m % n);
}

void Fraction::printAsFraction(double decimal_fraction)
{
	int integerPart = (int)decimal_fraction;
	double fractionPart = decimal_fraction - integerPart;
	int count = 0;

	decimal_fraction -= integerPart;
	while ((int)decimal_fraction / pow(10, count) != fractionPart)
	{
		decimal_fraction *= 10;
		count++;
	}

	fractionPart = decimal_fraction;

	if (integerPart != 0)
		std::cout << integerPart << "*" << fractionPart << "/" << pow(10, count) << std::endl;
	else
		std::cout << fractionPart << "/" << pow(10, count) << std::endl;
}

void Fraction::printAsFraction(char* decimal_fraction)
{
	string integerPart = "";
	string fractionPart = "";
	int count = 0;
	bool dot = false;

	for (int i = 0; i < strlen(decimal_fraction); i++)
	{
		if (decimal_fraction[i] == '.')
		{
			dot = true;
			i++;
		}

		if (!dot)
		{
			integerPart += decimal_fraction[i];
		}
		else
		{
			fractionPart += decimal_fraction[i];
			count++;
		}
	}

	if (integerPart != "0")
		std::cout << integerPart << "*" << fractionPart << "/" << pow(10, count) << std::endl;
	else
		std::cout << fractionPart << "/" << pow(10, count) << std::endl;
}

void Fraction::printAsFraction(Fraction f)
{
	std::cout << f._x << "/" << f._y << std::endl;
}