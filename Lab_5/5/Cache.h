#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Cache
{
private:
	vector<T> data;
public:
	void put(T value);
	void operator += (T value);
	bool contains(T elem);
};

template <typename T>
void Cache<T>::put(T value) { data.push_back(value); }

template <typename T>
void Cache<T>::operator += (T value) { put(value); }

template <typename T>
bool Cache<T>::contains(T elem) { return find(data.begin(), data.end(), elem) != data.end(); }

template <>
class Cache<string>
{
private:
	vector<string> data;
public:
	void put(string value);
	void operator += (string value);
	void add();	
	bool contains(string elem);
};

void Cache<string>::put(string value) { data.push_back(value); }
void Cache<string>::operator += (string value) { put(value); }
void Cache<string>::add()
{
	try { if (data.size() >= 100) throw "Более 100 строк"; }
	catch (const char* message) { cout << message; }
}
bool Cache<string>::contains(string elem)
{
	vector<string>::iterator iter = data.begin();
	while (iter != data.end())
	{
		if ((*iter)[0] == elem[0]) return true;
		iter++;
	}

	return false;
}

