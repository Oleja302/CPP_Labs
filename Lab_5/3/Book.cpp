#include "Book.h"

Book::Book(string name, string author, int year) : _name(name), _author(author), _year(year) {}
string Book::getName() { return _name; }
string Book::getAuthor() { return _author; }
int Book::getYear() { return _year; }