#pragma once
#include "Deck.h"

class HandDeck : public Deck
{
private:
	int power;

public:
	HandDeck();


	HandDeck(int countCards);

	void AddCard(Card* card);

	friend class Dealer;
};

