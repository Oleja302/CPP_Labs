#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
	char* charF = new char[256]{ "0.123" };
	Fraction::printAsFraction(charF);

	Fraction f(1, 5);
	Fraction d(2, 5);
	Fraction res1(1,1);

	res1 = f / d;
	Fraction::printAsFraction(res1);

	res1 = f * d;
	Fraction::printAsFraction(res1);

	res1 = f - d;
	Fraction::printAsFraction(res1);

	res1 = f + d;
	Fraction::printAsFraction(res1);

	cout << "gcd(84, 90) = " << Fraction::gcd(84, 90) << endl;

	cout << "count: " << Fraction::GetCount();
}
