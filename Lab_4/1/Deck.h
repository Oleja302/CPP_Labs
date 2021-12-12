#pragma once
#include "Card.h"

class Deck
{
private:
	Card* cards;
	int countCards;

public:
	Deck();
	~Deck();
	Deck(int countCards);
	Deck(Card* cards);

	void Print(int countCards);

	Card* GetCard(int index);
	Card* GetCards();
	void SetCards(Card* newCards, int countCards);

	int GetCountCard();
	void SetCard(int index, Card tmp);
	void RemoveLastCard();

	friend class Dealer;
};

