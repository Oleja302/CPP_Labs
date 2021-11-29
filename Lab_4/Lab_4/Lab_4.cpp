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
private:
	Card* cards;
	int countCards;

public:
	Deck()
	{
		this->cards = nullptr;
		this->countCards = 0;
	}

	Deck(int countCards)
	{
		this->cards = new Card[countCards];
		this->countCards = countCards;
	}

	Deck(Card* cards)
	{
		this->cards = cards;
		this->countCards = 36;
		int i = 0, j = 6;
		for (; j <= 10; j++)
		{
			this->cards[i++] = Card(j, to_wstring(j) + L"\u2665");
			this->cards[i++] = Card(j, to_wstring(j) + L"\u2660");
			this->cards[i++] = Card(j, to_wstring(j) + L"\u2666");
			this->cards[i++] = Card(j, to_wstring(j) + L"\u2663");
		}

		this->cards[i++] = Card(j, L"V\u2665");
		this->cards[i++] = Card(j, L"V\u2660");
		this->cards[i++] = Card(j, L"V\u2666");
		this->cards[i++] = Card(j, L"V\u2663");
		j++;
		this->cards[i++] = Card(j, L"Q\u2665");
		this->cards[i++] = Card(j, L"Q\u2660");
		this->cards[i++] = Card(j, L"Q\u2666");
		this->cards[i++] = Card(j, L"Q\u2663");
		j++;
		this->cards[i++] = Card(j, L"K\u2665");
		this->cards[i++] = Card(j, L"K\u2660");
		this->cards[i++] = Card(j, L"K\u2666");
		this->cards[i++] = Card(j, L"K\u2663");
		j++;
		this->cards[i++] = Card(j, L"\u2665");
		this->cards[i++] = Card(j, L"\u2660");
		this->cards[i++] = Card(j, L"\u2666");
		this->cards[i++] = Card(j, L"\u2663");
	}
	~Deck() {
		delete[] cards;
	}
	void Print()
	{
		for (int i = 0; i < 36; i++)
		{
			wcout << this->cards[i]._surface << endl;
		}
	}

	Card* GetCards() { return this->cards; }

	int GetCountCards() { return this->countCards; }
	void ChangeCountCards(int value) { this->countCards += value; }
	Card GetCard(int index) { return cards[index]; }
	void SetCard(int index, Card tmp) { cards[index] = tmp; }

	friend class Dealer;
};

class Player
{
protected:
	Deck hand;
};

class Dealer : public Player
{
public:
	Card TakeAddCard(Deck* gameDeck, Deck* playerCard)
	{
		Card tmp = gameDeck->cards[gameDeck->countCards - 1];
		Deck *tmpDeck = new Deck(gameDeck->countCards - 1);

		for (int i = 0; i < gameDeck->countCards - 1; i++)
			tmpDeck->cards[i] = gameDeck->cards[i];

		delete gameDeck;
		gameDeck = nullptr;

		gameDeck = tmpDeck;
		delete tmpDeck;
		tmpDeck = nullptr;
	}

	void Mixing(Deck* Cards)
	{
		srand(time(NULL));
		int indexCard1, indexCard2, size = Cards->countCards;

		Card tmp;
		for (int i = 0; i < size; i++)
		{
			indexCard1 = rand() % 36;
			indexCard2 = rand() % 36;

			if (indexCard1 == indexCard2) continue;
			tmp = Cards->cards[indexCard1];
			Cards->SetCard(indexCard1, Cards->cards[indexCard2]);
			Cards->SetCard(indexCard2, tmp);
		}
	}
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
	Dealer d;
	d.Mixing(&deck);

	deck.Print();
}

