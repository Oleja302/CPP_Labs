#include <iostream>
#include <string>
#include <fcntl.h>
#include <corecrt_io.h>
using namespace std;

#include "Card.h"
#include "Deck.h"
#include "IFormattable.h"
#include "AdapterClass.h"
#include "AdapterObject.h"

void prettyPrint(const IFormattable& object)
{
	if (typeid(object) == typeid(AdapterClass))
	{
		IFormattable& tmpIF = const_cast<IFormattable&>(object);
		AdapterClass& tmpAC = dynamic_cast<AdapterClass&>(tmpIF);

		for (int i = 0; i < 36; i++)
			wcout << tmpAC.GetCards()[i].GetSurface() << L" ";
	}

	else if (typeid(object) == typeid(AdapterObject))
	{
		IFormattable& tmpIF = const_cast<IFormattable&>(object);
		AdapterObject& tmpAO = dynamic_cast<AdapterObject&>(tmpIF);
		for (int i = 0; i < 36; i++)
			wcout << tmpAO.GetCards()[i].GetSurface() << L" ";
	}
}

int main()
{
	setlocale(LC_ALL, "RU");
	_setmode(_fileno(stdout), _O_U16TEXT);

	Card* cards1 = new Card[36];
	Card* cards2 = new Card[36];

	Deck* deck1 = new Deck(cards1);
	Deck* deck2 = new Deck(cards2);

	AdapterClass adapterC(deck1);
	AdapterObject adapterO(deck2);

	adapterC.format();
	adapterO.format();

	prettyPrint(adapterC);
	wcout << endl;
	prettyPrint(adapterO);
	wcout << endl;

	delete[] cards1;
	delete[] cards2;

	delete deck1;
	delete deck2;
}


