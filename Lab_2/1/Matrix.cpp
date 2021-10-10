#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix(int rows, int cols)
{
	rows_ = rows;
	cols_ = cols;

	matrix = new int* [rows_];

	for (int i = 0; i < rows_; i++)
	{
		matrix[i] = new int[cols];
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < rows_; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

void Matrix::PrintMatrix()
{
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}
}

Matrix& Matrix::operator++(int)
{
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			*(*(matrix + i)+j) += 1;
		}	
	}

	return *this;
}

Matrix& Matrix::operator++()
{
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			*(*(matrix + i) + j) += 1;
		}
	}

	return *this;
}

Matrix& Matrix::operator--(int)
{
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			*(*(matrix + i) + j) -= 1;
		}
	}

	return *this;
}

Matrix& Matrix::operator--()
{
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			*(*(matrix + i) + j) -= 1;
		}
	}

	return *this;
}

int const* const* Matrix::GetElement()
{
	int const* const* pointerElementMatrix = matrix;

	return pointerElementMatrix;
}

void Matrix::ConvertingVectorToMatrix(Vector& v)
{
	int arr[18]{};

	for (int i = 0; i < v.GetLength(); i++)
	{
		arr[i] = v.GetElement()[i];
	}

	//Sort
	for (int i = 1; i < v.GetLength(); i++)
		for (int j = i; j > 0 && *(arr + j - 1) < *(arr + j); j--)
			swap(*(arr + j - 1), *(arr + j));
	//

	//Converting
	int k = 0;
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			*(*(matrix + i) + j) = *(arr + k);
			k++;
		}
	}
}
