#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h> 
using namespace std;

class Card
{
public:
	int _power;
	wstring _surface;

public:
	Card() : Card(0, L"??") {}
	Card(int power, wstring surface) : _power(power), _surface(surface) {}
};

class Deck
{
public:
	Card* cards;
	int countCards;

public:
	Deck()
	{
		this->cards = nullptr;
		this->countCards = 0;
	}

	Deck(Card* cards)
	{
		this->cards = cards;
		int countCards = 36;

		for (int i = 0, j = 6; i < countCards; )
		{
			switch (j)
			{
			case 10:

				this->cards[i++] = Card(j, L"V\u2665");
				this->cards[i++] = Card(j, L"V\u2660");
				this->cards[i++] = Card(j, L"V\u2666");
				this->cards[i++] = Card(j, L"V\u2663");

				this->cards[i++] = Card(j, L"Q\u2665");
				this->cards[i++] = Card(j, L"Q\u2660");
				this->cards[i++] = Card(j, L"Q\u2666");
				this->cards[i++] = Card(j, L"Q\u2663");

				this->cards[i++] = Card(j, L"K\u2665");
				this->cards[i++] = Card(j, L"K\u2660");
				this->cards[i++] = Card(j, L"K\u2666");
				this->cards[i++] = Card(j, L"K\u2663");

				j++;
				break;

			case 11:

				this->cards[i++] = Card(j, L"\u2665");
				this->cards[i++] = Card(j, L"\u2660");
				this->cards[i++] = Card(j, L"\u2666");
				this->cards[i++] = Card(j, L"\u2663");

				break;

			default:
				this->cards[i++] = Card(j, to_wstring(j) + L"\u2665");
				this->cards[i++] = Card(j, to_wstring(j) + L"\u2660");
				this->cards[i++] = Card(j, to_wstring(j) + L"\u2666");
				this->cards[i++] = Card(j, to_wstring(j) + L"\u2663");

				j++;
				break;
			}
		}

		Mixing(countCards);
	}

	~Deck()
	{
		delete[] cards;
	}

	void AddCard(Card card)
	{
		countCards++;

		Card *newCards = new Card[countCards];

		for (int i = 0; i < countCards - 1; i++)		
			newCards[i] = this->cards[i];
		
		delete[] this->cards;

		newCards[countCards - 1] = card;

		this->cards = newCards;
		newCards = nullptr;
	}

	Card TakeCard()
	{
		countCards++;

		Card* newCards = new Card[countCards];

		for (int i = 0; i < countCards - 1; i++)
			newCards[i] = this->cards[i];

		delete[] this->cards;

		newCards[countCards - 1] = card;

		this->cards = newCards;
		newCards = nullptr;
	}

	void Print()
	{
		for (int i = 0; i < 36; i++)
		{
			wcout << this->cards[i]._surface << endl;
		}
	}

	void Mixing(int countCards)
	{
		srand(time(NULL));
		int indexCard1, indexCard2;
		Card tmp;
		for (int i = 0; i < countCards; i++)
		{
			indexCard1 = rand() % 36;
			indexCard2 = rand() % 36;

			if (indexCard1 == indexCard2) continue;
			tmp = this->cards[indexCard1];
			this->cards[indexCard1] = this->cards[indexCard2];
			this->cards[indexCard2] = tmp;
		}
	}
};

class Player
{
	Deck hand;
};

class Dealer : Player
{

};

class Game
{
	Deck* deck1;
	Deck* deck2;
	Deck* deck3;
	Deck* deck4;

	Player* player;
	Dealer* dealer;
};

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);

	Card* cards = new Card[36];
	Deck deck(cards);

	deck.Print();
}

