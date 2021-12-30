#pragma once
#include<fstream>
#include <iterator>
using namespace std;

template<typename T>
class DataManager
{
private:
	T _data[64]{};
	int _size;
	int _countElem;

public:
	DataManager();
	void Push(T elem);
	void Push(T elems[], int n);
	T Peek();
	T Pop();
	void WriteToDump();
};

template <typename T>
DataManager<T>::DataManager()
{
	_size = 64;
	_countElem = 0;
}

template <typename T>
void DataManager<T>::Push(T elem)
{
	if (_countElem >= _size) WriteToDump();

	_countElem++;
	for (int i = _countElem - 2; i >= 0; i--)
		_data[i + 1] = _data[i];

	_data[0] = elem;
}

template <typename T>
void DataManager<T>::Push(T elems[], int n)
{
	for (int i = 0; i < n; i++)
		Push(elems[i]);
}

template <typename T>
T DataManager<T>::Peek()
{
	if (_countElem % 2 == 0) return 0;
	else return _data[_countElem / 2];
}

template <typename T>
T DataManager<T>::Pop()
{
	//Get element
	int index;
	if (_countElem % 2 != 0) index = _countElem / 2;
	else index = _countElem / 2 - 1;
	T resElem = _data[index];

	//Read dump.dat
	if (_countElem - 1 == 0)
	{
		ifstream in("dump.dat");
		if (in.is_open() && in.peek() != std::ifstream::traits_type::eof())
		{
			for (int i = 0; i < _size; i++)
				in >> _data[i];

			_countElem = _size;
		}

		in.close();
	}

	//Left shift
	else
	{
		for (int i = index; i < _countElem; i++)
			_data[i] = _data[i + 1];
		_data[_countElem - 1] = 0;

		_countElem--;
	}

	return resElem;
}

template <typename T>
void DataManager<T>::WriteToDump()
{
	ofstream fout("dump.dat");
	for (int i = 0; i < _size; i++)
	{
		fout << _data[i];
		fout << endl;
	}

	fout.close();

	memset(_data, 0, sizeof(T) * _countElem);
	_countElem = 0;
}


template<>
class DataManager<char>
{
private:
	char _data[64]{};
	int _size;
	int _countElem;

public:
	DataManager();
	void Push(char elem);
	void Push(char elems[], int n);
	char Peek();
	char Pop();	
	char PopUpper();
	char PopLower();
	void WriteToDump();
};

DataManager<char>::DataManager()
{
	_size = 64;
	_countElem = 0;
}

void DataManager<char>::Push(char elem)
{
	if (_countElem >= _size) WriteToDump();

	_countElem++;
	for (int i = _countElem - 2; i >= 0; i--)
		_data[i + 1] = _data[i];

	if (ispunct(elem)) _data[0] = '_';
	else _data[0] = elem;
}

void DataManager<char>::Push(char elems[], int n)
{
	for (int i = 0; i < n; i++)
		Push(elems[i]);
}

char DataManager<char>::Peek()
{
	if (_countElem % 2 == 0) return 0;
	else return _data[_countElem / 2];
}

char DataManager<char>::Pop()
{
	//Get element
	int index;
	if (_countElem % 2 != 0) index = _countElem / 2;
	else index = _countElem / 2 - 1;
	char resElem = _data[index];

	//Read dump.dat
	if (_countElem - 1 == 0)
	{
		ifstream in("dump.dat");
		if (in.is_open() && in.peek() != std::ifstream::traits_type::eof())
		{
			for (int i = 0; i < _size; i++)
				in >> _data[i];

			_countElem = _size;
		}

		in.close();
	}

	//Left shift
	else
	{
		for (int i = index; i < _countElem; i++)
			_data[i] = _data[i + 1];
		_data[_countElem - 1] = 0;

		_countElem--;
	}

	return resElem;
}

char DataManager<char>::PopUpper()
{
	//Get element
	int index;
	if (_countElem % 2 != 0) index = _countElem / 2;
	else index = _countElem / 2 - 1;
	char resElem = toupper(_data[index]);

	//Read dump.dat
	if (_countElem - 1 == 0)
	{
		ifstream in("dump.dat");
		if (in.is_open() && in.peek() != std::ifstream::traits_type::eof())
		{
			for (int i = 0; i < _size; i++)
				in >> _data[i];

			_countElem = _size;
		}

		in.close();
	}

	//Left shift
	else
	{
		for (int i = index; i < _countElem; i++)
			_data[i] = _data[i + 1];
		_data[_countElem - 1] = 0;

		_countElem--;
	}

	return resElem;
}

char DataManager<char>::PopLower()
{
	//Get element
	int index;
	if (_countElem % 2 != 0) index = _countElem / 2;
	else index = _countElem / 2 - 1;
	char resElem = tolower(_data[index]);

	//Read dump.dat
	if (_countElem - 1 == 0)
	{
		ifstream in("dump.dat");
		if (in.is_open() && in.peek() != std::ifstream::traits_type::eof())
		{
			for (int i = 0; i < _size; i++)
				in >> _data[i];

			_countElem = _size;
		}

		in.close();
	}

	//Left shift
	else
	{
		for (int i = index; i < _countElem; i++)
			_data[i] = _data[i + 1];
		_data[_countElem - 1] = 0;

		_countElem--;
	}

	return resElem;
}

void DataManager<char>::WriteToDump()
{
	ofstream fout("dump.dat");
	for (int i = 0; i < _size; i++)
	{
		fout << _data[i];
		fout << endl;
	}

	fout.close();

	memset(_data, 0, sizeof(char) * _countElem);
	_countElem = 0;
}