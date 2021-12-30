#pragma once
#include "Book.h"

class BookSorter
{
public:
	bool operator() (Book* book1, Book* book2);
};

