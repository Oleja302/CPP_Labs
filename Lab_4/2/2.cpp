#include <iostream>
#include <string>
#include <fcntl.h>
#include <corecrt_io.h>
using namespace std;

class Card
{
private:
	int power;
	wstring surface;

public:
	Card() : Card(0, L"??") {}
	Card(int newPower, wstring newSurface) : power(newPower), surface(newSurface) {}
	void SetPower(int power) { this->power = power; }
	void SetSurface(wstring surface) { this->surface = surface; }
	int GetPower() { return this->power; }
	wstring GetSurface() { return this->surface; }
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

	Card* GetCards() { return this->cards; }

	void SetCards(Card* newCards, int countCards)
	{
		delete[] this->cards;
		this->cards = newCards;
		this->countCards = countCards;
	}
};

class IFormattable
{
public:
	virtual wstring format() = 0;
};

class AdapterClass : public Deck, public IFormattable
{
public:
	AdapterClass(Deck *deck)
	{
		this->SetCards(deck->GetCards(),36);
	}

	wstring format() override
	{
		for (int startIndex = 0; startIndex < 36; ++startIndex)
		{
			int smallestIndex = startIndex;
			for (int currentIndex = startIndex + 1; currentIndex < 36; ++currentIndex)
			{
				if (this->GetCards()[currentIndex].GetPower() < this->GetCards()[smallestIndex].GetPower())
					smallestIndex = currentIndex;
			}

			Card tmp(this->GetCards()[startIndex].GetPower(), this->GetCards()[startIndex].GetSurface());

			this->GetCards()[startIndex].SetPower(this->GetCards()[smallestIndex].GetPower());
			this->GetCards()[startIndex].SetSurface(this->GetCards()[smallestIndex].GetSurface());

			this->GetCards()[smallestIndex].SetPower(tmp.GetPower());
			this->GetCards()[smallestIndex].SetSurface(tmp.GetSurface());
		}

		wstring deckStr;

		for (int i = 0; i < 36; i++)
			deckStr += this->GetCards()[i].GetSurface();

		return deckStr;
	}
};

class AdapterObject :public IFormattable
{
private:
	Deck* deck;

public:
	AdapterObject(Deck* newDeck) { this->deck = newDeck; }

	Card* GetCards() { return this->deck->GetCards(); }

	wstring format() override
	{
		for (int startIndex = 0; startIndex < 36; ++startIndex)
		{
			int smallestIndex = startIndex;
			for (int currentIndex = startIndex + 1; currentIndex < 36; ++currentIndex)
			{
				if (deck->GetCards()[currentIndex].GetPower() < deck->GetCards()[smallestIndex].GetPower())
					smallestIndex = currentIndex;
			}

			Card tmp(deck->GetCards()[startIndex].GetPower(), deck->GetCards()[startIndex].GetSurface());

			deck->GetCards()[startIndex].SetPower(deck->GetCards()[smallestIndex].GetPower());
			deck->GetCards()[startIndex].SetSurface(deck->GetCards()[smallestIndex].GetSurface());

			deck->GetCards()[smallestIndex].SetPower(tmp.GetPower());
			deck->GetCards()[smallestIndex].SetSurface(tmp.GetSurface());
		}

		wstring deckStr;

		for (int i = 0; i < 36; i++)
			deckStr += deck->GetCards()[i].GetSurface();

		return deckStr;
	}
};

void prettyPrint(const IFormattable& object)
{
	if (typeid(object) == typeid(AdapterClass))
	{
		IFormattable& tmpIF = const_cast<IFormattable&>(object);
		AdapterClass& tmpAC = dynamic_cast<AdapterClass&>(tmpIF);

		for (int i = 0; i < 36; i++)
			wcout << tmpAC.GetCards()[i].GetSurface() << L" ";
	}

	else if (typeid(object) == typeid(AdapterObject))
	{
		IFormattable& tmpIF = const_cast<IFormattable&>(object);
		AdapterObject& tmpAO = dynamic_cast<AdapterObject&>(tmpIF);
		for (int i = 0; i < 36; i++)
			wcout << tmpAO.GetCards()[i].GetSurface() << L" ";
	}
}

int main()
{
	setlocale(LC_ALL, "RU");
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	Card* cards1 = new Card[36];
	Card* cards2 = new Card[36];

	Deck* deck1 = new Deck(cards1);
	Deck* deck2 = new Deck(cards2);

	AdapterClass adapterC(deck1);
	AdapterObject adapterO(deck2);

	adapterC.format();
	adapterO.format();

	prettyPrint(adapterC);
	wcout << endl;
	prettyPrint(adapterO);
	wcout << endl;

	delete[] cards1;
	delete[] cards2;
	delete deck1;
	delete deck2;
}


