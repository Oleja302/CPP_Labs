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
		HandDeck* tmpHandDeck = new HandDeck(GetCountCard() + 1);
		tmpHandDeck->power = this->power + card->GetPower();

		for (int i = 0; i < GetCountCard(); i++)
			tmpHandDeck->SetCard(i, GetCards()[i]);

		tmpHandDeck->GetCards()[tmpHandDeck->GetCountCard() - 1] = *card;

		this->power = tmpHandDeck->power;
		SetCards(tmpHandDeck->GetCards(), tmpHandDeck->GetCountCard());
		tmpHandDeck = nullptr;
	}