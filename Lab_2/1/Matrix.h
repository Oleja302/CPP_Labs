#pragma once
#include "Vector.h"

class Matrix
{
private:
	int** matrix = nullptr;
	int rows_ = 0;
	int cols_ = 0;

public:
	Matrix(int rows, int cols);
	~Matrix();

	void PrintMatrix();
	Matrix& operator++(int);
	Matrix& operator++();
	Matrix& operator--(int);
	Matrix& operator--();
	int const* const* GetElement();
	void ConvertingVectorToMatrix(Vector& v);
};

