#include <iostream>
#include <iomanip>
using namespace std;

void InitializationArr(int* arr)
{
	for (int i = 0; i < 18; i++)
	{
		*(arr + i) = i * i + 1;
		if (i % 2 == 0) *(arr + i) *= -1;
	}
}

int** ConvertingArr(int* arr)
{
	//Sort
	for (int i = 1; i < 18; i++)
		for (int j = i; j > 0 && *(arr + j - 1) < *(arr + j); j--)
			swap(*(arr + j - 1), *(arr + j));
	//

	int** resultArr = new int* [9];

	for (int i = 0; i < 9; i++)
	{
		*(resultArr + i) = new int[2];
	}

	//Converting
	int k = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			*(*(resultArr + i) + j) = *(arr+k);
			k++;
		}
	}

	return resultArr;
}

void PrintArr(int** arr)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << setw(5) << *(*(arr + i) + j);
		}

		cout << endl;
	}
}

int main()
{
	int* arr = new int[18];
	InitializationArr(arr);
	
	for (int i = 0; i < 18; i++)
	{
		cout << setw(5) <<*(arr + i);
	}
	cout << "\n\n";

	int** resultArr = ConvertingArr(arr);
	PrintArr(resultArr);

	delete[] arr;

	for (int i = 0; i < 9; i++)
	{
		delete[] resultArr[i];
	}

	delete[] resultArr;
}
