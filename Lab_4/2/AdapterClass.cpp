#include "AdapterClass.h"

AdapterClass::AdapterClass(Deck* deck)
{
	this->SetCards(deck->GetCards(), 36);
}

wstring AdapterClass::format()
{
	for (int startIndex = 0; startIndex < 36; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < 36; ++currentIndex)
		{
			if (this->GetCards()[currentIndex].GetPower() < this->GetCards()[smallestIndex].GetPower())
				smallestIndex = currentIndex;
		}

		Card tmp(this->GetCards()[startIndex].GetPower(), this->GetCards()[startIndex].GetSurface());

		this->GetCards()[startIndex].SetPower(this->GetCards()[smallestIndex].GetPower());
		this->GetCards()[startIndex].SetSurface(this->GetCards()[smallestIndex].GetSurface());

		this->GetCards()[smallestIndex].SetPower(tmp.GetPower());
		this->GetCards()[smallestIndex].SetSurface(tmp.GetSurface());
	}

	wstring deckStr;

	for (int i = 0; i < 36; i++)
		deckStr += this->GetCards()[i].GetSurface();

	return deckStr;
}