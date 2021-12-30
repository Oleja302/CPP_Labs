#pragma once
#include "Card.h"
#include <vector>

class Deck
{
private:
	vector<Card> cards;

public:
	Deck() {};
	Deck(int countElem);
	Deck(vector<Card> cards);

	void Print(int countCards);

	Card* GetCard(int index);
	vector<Card>* GetCards();
	void SetCards(vector<Card> cards);

	int GetCountCard();
	void SetCard(int index, Card tmp);
	void RemoveLastCard();

	friend class Dealer;
};

