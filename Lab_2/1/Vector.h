#pragma once
class Vector
{
private:
	int* vector_ = nullptr;
	int length_ = 0;

public:
	Vector(int length);
	~Vector();

	int GetLength();
	void InitializationVector();
	void PrintVector();

	const int* GetElement();
	Vector& operator++(int);
	Vector& operator++();
	Vector& operator--(int);
	Vector& operator--();
	int operator[](const int index);
};

