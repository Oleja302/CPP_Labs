#include "BookFinder.h"

BookFinder::BookFinder() :BookFinder(0, 0) {};
BookFinder::BookFinder(int start, int end) :_start(start), _end(end) {}
bool BookFinder::operator() (Book* book)
{
	if (book->getYear() >= _start && book->getYear() <= _end) return true;
	else return false;
}