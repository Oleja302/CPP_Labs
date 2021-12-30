#include "Deck.h"
#include <string>
using namespace std;

Deck::Deck(int countElem)
{
	cards.resize(countElem);
}

Deck::Deck(vector<Card> cards)
{
	this->cards = cards;
	int j = 2;

	this->cards.push_back(Card(j, L"V\u2665"));
	this->cards.push_back(Card(j, L"V\u2666"));
	this->cards.push_back(Card(j, L"V\u2663"));
	this->cards.push_back(Card(j, L"V\u2660"));
	j++;
	this->cards.push_back(Card(j, L"Q\u2665"));
	this->cards.push_back(Card(j, L"Q\u2666"));
	this->cards.push_back(Card(j, L"Q\u2663"));
	this->cards.push_back(Card(j, L"Q\u2660"));
	j++;
	this->cards.push_back(Card(j, L"K\u2665"));
	this->cards.push_back(Card(j, L"K\u2666"));
	this->cards.push_back(Card(j, L"K\u2663"));
	this->cards.push_back(Card(j, L"K\u2660"));
	j++;
	this->cards.push_back(Card(j, L"\u2665"));
	this->cards.push_back(Card(j, L"\u2666"));
	this->cards.push_back(Card(j, L"\u2663"));
	this->cards.push_back(Card(j, L"\u2660"));
	j++;

	for (int i = 6; j <= 10; j++)
	{
		this->cards.push_back(Card(j, to_wstring(j) + L"\u2665"));
		this->cards.push_back(Card(j, to_wstring(j) + L"\u2666"));
		this->cards.push_back(Card(j, to_wstring(j) + L"\u2663"));
		this->cards.push_back(Card(j, to_wstring(j) + L"\u2660"));
		i += 4;
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
vector<Card>* Deck::GetCards() { return &this->cards; }
void Deck::SetCards(vector<Card> newCards)
{
	this->cards = newCards;
}
int Deck::GetCountCard() { return this->cards.size(); }
void Deck::SetCard(int index, Card tmp) { this->cards[index] = tmp; }
void Deck::RemoveLastCard() { this->cards.pop_back(); }