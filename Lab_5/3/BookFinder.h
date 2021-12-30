#pragma once
#include "Book.h"
class BookFinder
{
private:
	int _start;
	int _end;

public:
	BookFinder();
	BookFinder(int start, int end);
	bool operator() (Book* book);
};

