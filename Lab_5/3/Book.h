#pragma once
#include <string>
using namespace std;

class Book
{
private:
	string _name;
	string _author;
	int _year;

public:
	Book(string name, string author, int year);
	string getName() ;
	string getAuthor();
	int getYear();
};

