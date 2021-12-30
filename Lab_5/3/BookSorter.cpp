#include "BookSorter.h"

bool BookSorter::operator() (Book* book1, Book* book2)
{
	bool result = false;

	for (int i = 0, j = 0, k = 0, l = 0; ;)
	{
		if (i >= (int)book1->getAuthor().length() || j >= (int)book2->getAuthor().length()) break;

		if (ispunct(book1->getAuthor()[i]))
		{
			i++;
			continue;
		}

		else if (ispunct(book2->getAuthor()[j]))
		{
			j++;
			continue;
		}

		else if (tolower(book1->getAuthor()[i]) == tolower(book2->getAuthor()[j]))
		{
			if (k >= (int)book1->getName().length() || l >= (int)book2->getName().length()) break;

			if (ispunct(book1->getName()[k]))
			{
				k++;
				continue;
			}

			else if (ispunct(book2->getName()[l]))
			{
				l++;
				continue;
			}

			if (tolower(book1->getName()[k]) == tolower(book2->getName()[l]))
			{
				i++;
				j++;
				k++;
				l++;
				continue;
			}

			result = (int)book1->getName()[k] < (int)book2->getName()[l] ? true : false;
			break;
		}

		result = (int)book1->getAuthor()[i] < (int)book2->getAuthor()[j] ? true : false;
		break;
	}

	return result;
}