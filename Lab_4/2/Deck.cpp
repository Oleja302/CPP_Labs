#include "Deck.h"

Deck::Deck()
{
	this->cards = nullptr;
	this->countCards = 0;
}

Deck::Deck(int countCards)
{
	this->cards = new Card[countCards];
	this->countCards = countCards;
}

Deck::Deck(Card* cards)
{
	this->cards = cards;
	cards = nullptr;
	this->countCards = 36;
	int i = 0, j = 10;

	for (; j >= 6; j--)
	{
		this->cards[i++] = Card(j, to_wstring(j) + L"\u2665");
		this->cards[i++] = Card(j, to_wstring(j) + L"\u2666");
		this->cards[i++] = Card(j, to_wstring(j) + L"\u2663");
		this->cards[i++] = Card(j, to_wstring(j) + L"\u2660");
	}

	this->cards[i++] = Card(j, L"\u2665");
	this->cards[i++] = Card(j, L"\u2666");
	this->cards[i++] = Card(j, L"\u2663");
	this->cards[i++] = Card(j, L"\u2660");
	j--;
	this->cards[i++] = Card(j, L"K\u2665");
	this->cards[i++] = Card(j, L"K\u2666");
	this->cards[i++] = Card(j, L"K\u2663");
	this->cards[i++] = Card(j, L"K\u2660");
	j--;
	this->cards[i++] = Card(j, L"Q\u2665");
	this->cards[i++] = Card(j, L"Q\u2666");
	this->cards[i++] = Card(j, L"Q\u2663");
	this->cards[i++] = Card(j, L"Q\u2660");
	j--;
	this->cards[i++] = Card(j, L"V\u2665");
	this->cards[i++] = Card(j, L"V\u2666");
	this->cards[i++] = Card(j, L"V\u2663");
	this->cards[i++] = Card(j, L"V\u2660");
}

Card* Deck::GetCards() { return this->cards; }

void Deck::SetCards(Card* newCards, int countCards)
{
	delete[] this->cards;
	this->cards = newCards;
	this->countCards = countCards;
}