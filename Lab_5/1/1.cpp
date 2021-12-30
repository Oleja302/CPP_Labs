#include <iostream>
#include<fstream>
#include <iterator>
using namespace std;

#include "DataManager.h"

int main()
{
	DataManager<int> manager;
	manager.Push(-9);
	int a[60] = { 0 };
	manager.Push(a, 60);
	int x = manager.Peek();
	for (int i = 1; i < 15; ++i)
		manager.Push(i);

	x = manager.Pop();

	DataManager<char> char_manager;
	char_manager.Push('h');
	char_manager.Push('e');
	char_manager.Push('l');
	char_manager.Push('l');
	char_manager.Push('o');
	char ch = char_manager.PopUpper();
	
	ostream_iterator<int> intOut(cout, " ");
	ostream_iterator<char> charOut(cout, " ");

	for (int i = 0; i < 64; i++)	
		*intOut = manager.Pop();

	cout << endl;

	for (int i = 0; i < 64; i++)
		*charOut = char_manager.Pop();
}