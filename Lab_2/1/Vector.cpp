#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector(int length)
{
	length_ = length;
	vector_ = new int[length_];
}

Vector::~Vector()
{
	delete[] vector_;
}

int Vector::GetLength()
{
	return length_;
}

void Vector::InitializationVector()
{
	for (int i = 0; i < length_; i++)
	{
		*(vector_ + i) = i * i + 1;
		if (i % 2 == 0) *(vector_ + i) *= -1;
	}
}

void Vector::PrintVector()
{
	for (int i = 0; i < length_; i++)
	{
		cout << *(vector_ + i) << " ";
	}
}

const int* Vector::GetElement()
{
	const int* pointerElementVector = vector_;
	return pointerElementVector;
}

Vector& Vector::operator++(int)
{
	for (int i = 0; i < length_; i++)
	{
		*(vector_ + i) += 1;
	}

	return *this;
}

Vector& Vector::operator++()
{
	for (int i = 0; i < length_; i++)
	{
		*(vector_ + i) += 1;
	}	

	return *this;
}

Vector& Vector::operator--(int)
{
	for (int i = 0; i < length_; i++)
	{
		*(vector_ + i) -= 1;
	}

	return *this;
}

Vector& Vector::operator--()
{
	for (int i = 0; i < length_; i++)
	{
		*(vector_ + i) -= 1;
	}

	return *this;
}


int Vector::operator[](const int index)
{
	return *(vector_ + index);
}


