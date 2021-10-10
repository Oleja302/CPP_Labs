#include <cstdio>
using namespace std;

int processArray(int arr[], int* resultArr)
{
	int powerOfTwo = 2;
	int powerOfThree = 3;
	int count = 0;

	//Filling an array with powers of two and three
	for (int i = 0, j = 0; i < 16; i++)
	{
		if (i % 2 == 0)
		{
			arr[i] = powerOfTwo;
			powerOfTwo *= 2;
		}

		else
		{
			arr[i] = powerOfThree;
			powerOfThree *= 3;
		}

		//Counting and filling the number of two-digit numbers
		if (arr[i] % 100 == arr[i] && arr[i] % 10 != arr[i])
		{
			resultArr[j] = arr[i];
			j++;

			count++;
		}
	}

	return count;
}

int main()
{
	int count = 0;

	int arr[16]{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int resultArr[5];

	count = processArray(arr, resultArr);

	//Console output
	printf_s("Count two-digit numbers: ");
	printf_s("%d", count);

	printf_s("\n\n");

	printf_s("Start array: ");

	for (int i = 0; i < 16; i++)
		printf_s("%d ", arr[i]);

	printf_s("\n\n");

	printf_s("Result array: ");

	for (int i = 0; i < count; i++)
		printf_s("%d ", resultArr[i]);

	printf_s("\n");
}