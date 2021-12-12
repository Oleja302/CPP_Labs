#pragma once
#include <string>
using namespace std;

class IFormattable
{
public:
	virtual wstring format() = 0;
};

