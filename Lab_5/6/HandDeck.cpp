#include "HandDeck.h"

	HandDeck::HandDeck() : Deck()
	{
		this->power = 0;
	}

	HandDeck::HandDeck(int countCards) : Deck(countCards) 
	{
		this->power = 0;
	}

	void HandDeck::AddCard(Card* card)
	{
		this->GetCards()->push_back(*card);
		this->power += card->GetPower();
	}