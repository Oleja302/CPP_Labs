#include "AdapterObject.h"

AdapterObject::AdapterObject(Deck* newDeck) { this->deck = newDeck; }

Card* AdapterObject::GetCards() { return this->deck->GetCards(); }

wstring AdapterObject::format()
{
	for (int startIndex = 0; startIndex < 36; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < 36; ++currentIndex)
		{
			if (deck->GetCards()[currentIndex].GetPower() < deck->GetCards()[smallestIndex].GetPower())
				smallestIndex = currentIndex;
		}

		Card tmp(deck->GetCards()[startIndex].GetPower(), deck->GetCards()[startIndex].GetSurface());

		deck->GetCards()[startIndex].SetPower(deck->GetCards()[smallestIndex].GetPower());
		deck->GetCards()[startIndex].SetSurface(deck->GetCards()[smallestIndex].GetSurface());

		deck->GetCards()[smallestIndex].SetPower(tmp.GetPower());
		deck->GetCards()[smallestIndex].SetSurface(tmp.GetSurface());
	}

	wstring deckStr;

	for (int i = 0; i < 36; i++)
		deckStr += deck->GetCards()[i].GetSurface();

	return deckStr;
}