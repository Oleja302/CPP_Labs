#include "Deck.h"
#include <string>
using namespace std;

	Deck::Deck()
	{
		this->cards = nullptr;
		this->countCards = 0;
	}

	Deck::~Deck()
	{
		if (this->countCards != 36) delete[] this->cards;
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
		int i = 0, j = 2;

		this->cards[i++] = Card(j, L"V\u2665");
		this->cards[i++] = Card(j, L"V\u2666");
		this->cards[i++] = Card(j, L"V\u2663");
		this->cards[i++] = Card(j, L"V\u2660");
		j++;
		this->cards[i++] = Card(j, L"Q\u2665");
		this->cards[i++] = Card(j, L"Q\u2666");
		this->cards[i++] = Card(j, L"Q\u2663");
		this->cards[i++] = Card(j, L"Q\u2660");
		j++;
		this->cards[i++] = Card(j, L"K\u2665");
		this->cards[i++] = Card(j, L"K\u2666");
		this->cards[i++] = Card(j, L"K\u2663");
		this->cards[i++] = Card(j, L"K\u2660");
		j++;
		this->cards[i++] = Card(j, L"\u2665");
		this->cards[i++] = Card(j, L"\u2666");
		this->cards[i++] = Card(j, L"\u2663");
		this->cards[i++] = Card(j, L"\u2660");
		j++;

		for (; j <= 10; j++)
		{
			this->cards[i++] = Card(j, to_wstring(j) + L"\u2665");
			this->cards[i++] = Card(j, to_wstring(j) + L"\u2666");
			this->cards[i++] = Card(j, to_wstring(j) + L"\u2663");
			this->cards[i++] = Card(j, to_wstring(j) + L"\u2660");
		}
	}

	void Deck::Print(int countCards)
	{
		for (int i = 0; i < countCards; i++)
		{
			wcout << this->cards[i];
			wcout << L" ";
		}
	}

	Card* Deck::GetCard(int index) { return &cards[index]; }
	Card* Deck::GetCards() { return this->cards; }
	void Deck::SetCards(Card* newCards, int countCards)
	{
		delete[] this->cards;
		this->cards = newCards;
		this->countCards = countCards;
	}
	int Deck::GetCountCard() { return this->countCards; }
	void Deck::SetCard(int index, Card tmp) { this->cards[index] = tmp; }
	void Deck::RemoveLastCard()
	{
		Deck* tmpDeck = new Deck(this->countCards - 1);

		for (int i = 0; i < tmpDeck->countCards; i++)
			tmpDeck->cards[i] = this->cards[i];

		if (this->countCards == 36) this->cards = nullptr;
		else delete[] this->cards;

		this->cards = tmpDeck->cards;
		this->countCards--;
		tmpDeck = nullptr;
	}