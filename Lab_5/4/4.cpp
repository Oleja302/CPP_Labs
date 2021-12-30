#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	vector<int> books;

	books.push_back(2010);
	books.push_back(2004);
	books.push_back(2010);
	books.push_back(1999);
	books.push_back(2011);
	books.push_back(2009);
	books.push_back(2001);
	books.push_back(2010);
	books.push_back(1998);

	cout << count_if(books.begin(), books.end(), bind2nd(greater<int>(), 2009)) << endl;
}
