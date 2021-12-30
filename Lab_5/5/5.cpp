#include <iostream>
#include <vector>
using namespace std;

#include "Cache.h"

int main()
{
	setlocale(LC_ALL, "RUS");

	Cache<int> cache;
	cache.put(1);
	cache.put(2);
	cache.put(3);
	cache += 5;

	Cache<std::string> voc;
	voc.put("OK");

	std::cout << voc.contains("Only") << std::endl; // 1
	std::cout << cache.contains(5) << std::endl; // 1
	return 0;
}