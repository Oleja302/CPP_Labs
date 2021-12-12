#pragma once
#include "IFormattable.h"
#include "Deck.h"

class AdapterObject :public IFormattable
{
private:
	Deck* deck;

public:
	AdapterObject(Deck* newDeck);

	Card* GetCards();

	wstring format() override;
};

