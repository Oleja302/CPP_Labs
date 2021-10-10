#pragma once
#include <string>
#include <iostream>
#include <fstream>

class ILoggable
{
public:
	virtual void logToScreen() = 0;
	virtual void logToFile(const std::string& filename) = 0;
	virtual ~ILoggable() {};
};

