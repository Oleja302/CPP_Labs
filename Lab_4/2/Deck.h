#pragma once
#include "Card.h"

class Deck
{
private:
	Card* cards;
	int countCards;

public:
	Deck();

	Deck(int countCards);

	Deck(Card* cards);

	Card* GetCards();

	void SetCards(Card* newCards, int countCards);

};

