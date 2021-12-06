#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
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

	~Deck() {
		delete[] cards;
	}

	void Print(int countCards)
	{
		for (int i = 0; i < countCards; i++)
			wcout << this->cards[i].GetSurface() << " ";
	}

	Card* GetCard(int index) { return &cards[index]; }
	Card* GetCards() { return this->cards; }
	void SetCards(Card* newCards, int countCards)
	{
		delete[] this->cards;
		this->cards = newCards;
		this->countCards = countCards;
	}
	int GetCountCard() { return this->countCards; }
	void SetCard(int index, Card tmp) { this->cards[index] = tmp; }
	void RemoveCard(int index)
	{
		Deck* tmpDeck = new Deck(this->countCards - 1);

		for (int i = 0; i < this->countCards - 1; i++)
			tmpDeck->cards[i] = this->cards[i];

		delete[] this->cards;
		this->cards = tmpDeck->cards;
		this->countCards--;
		tmpDeck = nullptr;
	}

	friend class Dealer;
};

class HandDeck : public Deck
{
private:
	int power;

public:
	HandDeck() : Deck()
	{
		this->power = 0;
	}

	HandDeck(int countCards) : Deck(countCards)
	{
		this->power = 0;
	}

	void AddCard(Card* card)
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

	friend class Dealer;
};

class Player
{
private:
	HandDeck hand[2]{};

	friend class Dealer;
};

class Dealer
{
private:
	HandDeck hand;

public:
	void Mixing(Deck* Cards)
	{
		int indexCard1, indexCard2;

		Card tmp;
		for (int i = 0; i < Cards->countCards; i++)
		{
			indexCard1 = rand() % Cards->countCards;
			indexCard2 = rand() % Cards->countCards;

			if (indexCard1 == indexCard2) continue;
			tmp = Cards->cards[indexCard1];

			Cards->SetCard(indexCard1, Cards->cards[indexCard2]);
			Cards->SetCard(indexCard2, tmp);
		}
	}

	bool CheckBlackJack(HandDeck* handPlayer)
	{
		if (handPlayer->GetCountCard() != 5) return false;

		for (int i = 0; i < handPlayer->GetCountCard(); i++)
			if (handPlayer->GetCard(i)->GetPower() > 5) return false;

		return true;
	}

	bool CheckSplit(Player* player)
	{
		for (int i = 0; i < GetPlayerDeck(player)[0].GetCountCard(); i++)
		{
			for (int j = 0; j < GetPlayerDeck(player)[0].GetCountCard(); j++)
			{
				if (i == j) continue;

				if (GetPlayerDeck(player)[0].GetCard(i)->GetPower() == GetPlayerDeck(player)[0].GetCard(j)->GetPower())
					return true;
				else if (GetPlayerDeck(player)[0].GetCard(i)->GetPower() <= 5 && GetPlayerDeck(player)[0].GetCard(j)->GetPower() <= 5)
					return true;
			}
		}

		return false;
	}

	void Split(HandDeck* playerDeck, Deck* gameDeck)
	{
		Card* tmpCard = playerDeck[0].GetCard(1);
		playerDeck[1].AddCard(tmpCard);
		playerDeck[0].power -= tmpCard->GetPower();
		playerDeck[0].RemoveCard(1);

		playerDeck[0].AddCard(gameDeck->GetCard(gameDeck->GetCountCard() - 1));
		gameDeck->RemoveCard(gameDeck->GetCountCard() - 1);

		playerDeck[1].AddCard(gameDeck->GetCard(gameDeck->GetCountCard() - 1));
		gameDeck->RemoveCard(gameDeck->GetCountCard() - 1);
	}

	HandDeck* GetPlayerDeck(Player* player) { return player->hand; }
	HandDeck* GetDeck() { return &this->hand; }
	int GetPowerDeck(HandDeck* handDeck) { return handDeck->power; }
};

class Game
{
	Deck** gameDeck;
	Player* player;
	Dealer* dealer;

	enum class Сhoice
	{
		Enough = 1,
		More,
		Split
	};

public:
	Game(Deck* deck1, Deck* deck2, Deck* deck3, Deck* deck4, Player* player, Dealer* dealer)
	{
		this->gameDeck = new Deck * [4];

		dealer->Mixing(deck1);
		dealer->Mixing(deck2);
		dealer->Mixing(deck3);
		dealer->Mixing(deck4);

		this->gameDeck[0] = deck1;
		this->gameDeck[1] = deck2;
		this->gameDeck[2] = deck3;
		this->gameDeck[3] = deck4;

		this->player = player;
		this->dealer = dealer;
	}

	void Run()
	{
		Deck* deck = this->gameDeck[rand() % 4];
		this->dealer->GetPlayerDeck(this->player)[0].AddCard(deck->GetCard(deck->GetCountCard() - 1));
		deck->RemoveCard(deck->GetCountCard() - 1);

		deck = this->gameDeck[rand() % 4];
		this->dealer->GetPlayerDeck(this->player)[0].AddCard(deck->GetCard(deck->GetCountCard() - 1));
		deck->RemoveCard(deck->GetCountCard() - 1);

		deck = this->gameDeck[rand() % 4];
		this->dealer->GetDeck()->AddCard(deck->GetCard(deck->GetCountCard() - 1));
		deck->RemoveCard(deck->GetCountCard() - 1);

		deck = this->gameDeck[rand() % 4];
		this->dealer->GetDeck()->AddCard(deck->GetCard(deck->GetCountCard() - 1));
		deck->RemoveCard(deck->GetCountCard() - 1);

		int answer = 0;
		bool split = dealer->CheckSplit(player);

		while (static_cast<Сhoice>(answer) != Сhoice::Enough)
		{
			wcout << "[" << this->gameDeck[0]->GetCountCard() << "] ";
			wcout << "[" << this->gameDeck[1]->GetCountCard() << "] ";
			wcout << "[" << this->gameDeck[2]->GetCountCard() << "] ";
			wcout << "[" << this->gameDeck[3]->GetCountCard() << "] " << endl;

			wcout << endl;
			wcout << L"Дилер: ";
			dealer->GetDeck()->Print(dealer->GetDeck()->GetCountCard() - 1);
			wcout << L"??" << endl;
			wcout << endl;

			if (dealer->GetPlayerDeck(player)[1].GetCountCard() == 0)
			{
				wcout << L"Вы: ";
				dealer->GetPlayerDeck(player)[0].Print(dealer->GetPlayerDeck(player)[0].GetCountCard());
				wcout << endl;
				wcout << endl;
			}
			else
			{
				wcout << L"Вы: ";
				dealer->GetPlayerDeck(player)[0].Print(dealer->GetPlayerDeck(player)[0].GetCountCard());
				wcout << endl;
				dealer->GetPlayerDeck(player)[1].Print(dealer->GetPlayerDeck(player)[1].GetCountCard());
				wcout << endl;
				wcout << endl;
			}

			if (split)	wcout << L"1. Хватит" << endl << L"2. Еще" << endl << L"3. Сплит?" << endl;
			else wcout << L"1. Хватит" << endl << L"2. Еще" << endl;

			wcin >> answer;
			wcout << endl;

			switch (answer)
			{
			case (int)Сhoice::Enough:

				if (dealer->GetPlayerDeck(player)[1].GetCountCard() != 0)
				{
					wcout << L"Дилер: ";
					dealer->GetDeck()->Print(dealer->GetDeck()->GetCountCard());
					wcout << endl;
					wcout << endl;
					wcout << L"Вы: ";
					dealer->GetPlayerDeck(player)[0].Print(dealer->GetPlayerDeck(player)[0].GetCountCard());
					wcout << endl;
					dealer->GetPlayerDeck(player)[1].Print(dealer->GetPlayerDeck(player)[1].GetCountCard());
					wcout << endl;
					wcout << endl;

					wcout << L"Первая ставка: ";
					if (dealer->CheckBlackJack(&dealer->GetPlayerDeck(player)[0]))
						wcout << L"Блэкджек!" << endl;
					else if ((dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) <= 21) && (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) > dealer->GetPowerDeck(dealer->GetDeck())))
						wcout << L"Вы выиграли!" << endl;
					else if (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) == dealer->GetPowerDeck(dealer->GetDeck()))
						wcout << L"Ничья!" << endl;
					else wcout << L"Вы проиграли!" << endl;

					wcout << L"Вторая ставка: ";
					if (dealer->CheckBlackJack(&dealer->GetPlayerDeck(player)[1]))
						wcout << L"Блэкджек!" << endl;
					else if ((dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[1]) <= 21) && (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[1]) > dealer->GetPowerDeck(dealer->GetDeck())))
						wcout << L"Вы выиграли!" << endl;
					else if (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[1]) == dealer->GetPowerDeck(dealer->GetDeck()))
						wcout << L"Ничья!" << endl;
					else wcout << L"Вы проиграли!" << endl;
				}

				else
				{
					wcout << L"Дилер: ";
					dealer->GetDeck()->Print(dealer->GetDeck()->GetCountCard());
					wcout << endl;
					wcout << endl;
					wcout << L"Вы: ";
					dealer->GetPlayerDeck(player)[0].Print(dealer->GetPlayerDeck(player)[0].GetCountCard());
					wcout << endl;
					wcout << endl;

					if (dealer->CheckBlackJack(&dealer->GetPlayerDeck(player)[0]))
						wcout << L"Блэкджек!" << endl;
					else if ((dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) <= 21) && (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) > dealer->GetPowerDeck(dealer->GetDeck())))
						wcout << L"Вы выиграли!" << endl;
					else if (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) == dealer->GetPowerDeck(dealer->GetDeck()))
						wcout << L"Ничья!" << endl;
					else wcout << L"Вы проиграли!" << endl;
				}
				break;

			case (int)Сhoice::More:
				if (dealer->GetPlayerDeck(player)[1].GetCountCard() == 0)
				{
					deck = this->gameDeck[rand() % 4];
					this->dealer->GetPlayerDeck(this->player)[0].AddCard(deck->GetCard(deck->GetCountCard() - 1));
					deck->RemoveCard(deck->GetCountCard() - 1);
				}

				else
				{
					wcout << L"Введите номер бокса: ";
					int numberHand;
					wcin >> numberHand;
					wcout << endl;

					deck = this->gameDeck[rand() % 4];
					this->dealer->GetPlayerDeck(this->player)[numberHand].AddCard(deck->GetCard(deck->GetCountCard() - 1));
					deck->RemoveCard(deck->GetCountCard() - 1);
				}

				split = false;
				break;

			case (int)Сhoice::Split:
				if (split) dealer->Split(dealer->GetPlayerDeck(player), deck);
				split = false;
				break;

			default:
				break;
			}
		}
	}
};

int main()
{
	setlocale(LC_ALL, "RU");
	_setmode(_fileno(stdout), _O_U16TEXT);
	srand((time(0)));

	Deck* deck1 = new Deck(new Card[36]);
	Deck* deck2 = new Deck(new Card[36]);
	Deck* deck3 = new Deck(new Card[36]);
	Deck* deck4 = new Deck(new Card[36]);

	Player* player = new Player();
	Dealer* dealer = new Dealer();

	Game game(deck1, deck2, deck3, deck4, player, dealer);
	game.Run();

	return 0;
}

