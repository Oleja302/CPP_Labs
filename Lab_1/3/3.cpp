#include <cstring>
#include <cstdio>
#pragma warning(disable : 4996)

namespace function
{
	char* strcpy(char* dest, const char* src)
	{
		if (sizeof(src) > sizeof(dest)) return dest;
		for (char i = 0; i < strlen(src); i++)
		{
			dest[i] = src[i];
		}

		return dest;
	}
}

int main()
{
	//My function
	const char src1[] = "Hello World!";
	char dest1[sizeof(src1)] = "Test1";

	printf_s("My function\n");
	printf_s("src: %s dest: %s\n", src1, dest1);

	function::strcpy(dest1, src1);
	printf_s("src: %s dest: %s\n\n", src1, dest1);

	//Original function
	const char src2[] = "Hello World!";
	char dest2[sizeof(src2)] = "Test2";

	printf_s("Original function\n");
	printf_s("src: %s dest: %s\n", src2, dest2);

	std::strcpy(dest2, src2);
	printf_s("src: %s dest: %s\n\n", src2, dest2);
}
