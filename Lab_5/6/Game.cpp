#include "Game.h"

Game::Game(Deck* deck1, Deck* deck2, Deck* deck3, Deck* deck4, Player* player, Dealer* dealer)
{
	this->gameDeck = new Deck * [4];

	this->gameDeck[0] = new Deck(36);
	for (int i = 0; i < 36; i++)
		gameDeck[0]->SetCard(i, *deck1->GetCard(i));

	this->gameDeck[1] = new Deck(36);
	for (int i = 0; i < 36; i++)
		gameDeck[1]->SetCard(i, *deck2->GetCard(i));

	this->gameDeck[2] = new Deck(36);
	for (int i = 0; i < 36; i++)
		gameDeck[2]->SetCard(i, *deck3->GetCard(i));

	this->gameDeck[3] = new Deck(36);
	for (int i = 0; i < 36; i++)
		gameDeck[3]->SetCard(i, *deck4->GetCard(i));

	dealer->Mixing(gameDeck[0]);
	dealer->Mixing(gameDeck[1]);
	dealer->Mixing(gameDeck[2]);
	dealer->Mixing(gameDeck[3]);

	this->player = player;
	this->dealer = dealer;
}

void Game::Run()
{
	Deck* deck = this->gameDeck[rand() % 4];
	this->dealer->GetPlayerDeck(this->player)[0].AddCard(deck->GetCard(deck->GetCountCard() - 1));
	deck->RemoveLastCard();

	deck = this->gameDeck[rand() % 4];
	this->dealer->GetPlayerDeck(this->player)[0].AddCard(deck->GetCard(deck->GetCountCard() - 1));
	deck->RemoveLastCard();

	deck = this->gameDeck[rand() % 4];
	this->dealer->GetDeck()->AddCard(deck->GetCard(deck->GetCountCard() - 1));
	deck->RemoveLastCard();

	deck = this->gameDeck[rand() % 4];
	this->dealer->GetDeck()->AddCard(deck->GetCard(deck->GetCountCard() - 1));
	deck->RemoveLastCard();

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
			dealer->GetPlayerDeck(player)[0].Print(dealer->GetPlayerDeck(player)[0].GetCards()->size());
			wcout << endl;
			wcout << endl;
		}
		else
		{
			wcout << L"Вы: ";
			dealer->GetPlayerDeck(player)[0].Print(dealer->GetPlayerDeck(player)[0].GetCards()->size());
			wcout << endl;
			dealer->GetPlayerDeck(player)[1].Print(dealer->GetPlayerDeck(player)[1].GetCards()->size());
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
				dealer->GetDeck()->Print(dealer->GetDeck()->GetCards()->size());
				wcout << endl;
				wcout << endl;
				wcout << L"Вы: ";
				dealer->GetPlayerDeck(player)[0].Print(dealer->GetPlayerDeck(player)[0].GetCards()->size());
				wcout << endl;
				dealer->GetPlayerDeck(player)[1].Print(dealer->GetPlayerDeck(player)[1].GetCards()->size());
				wcout << endl;
				wcout << endl;

				wcout << L"Первая ставка: ";

				try
				{
					if (dealer->CheckBlackJack(&dealer->GetPlayerDeck(player)[0]))
						wcout << L"Блэкджек!" << endl;

					else if ((dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) <= 21) && (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) > dealer->GetPowerDeck(dealer->GetDeck())))
						wcout << L"Вы выиграли!" << endl;

					else if (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) == dealer->GetPowerDeck(dealer->GetDeck()))
						wcout << L"Ничья!" << endl;

					else if (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) > 21)
						throw L"Перебор!";

					else wcout << L"Вы проиграли!" << endl;
				}

				catch (const wchar_t* exeption)
				{
					wcout << exeption << endl;
				}

				wcout << L"Вторая ставка: ";

				try
				{
					if (dealer->CheckBlackJack(&dealer->GetPlayerDeck(player)[1]))
						wcout << L"Блэкджек!" << endl;

					else if ((dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[1]) <= 21) && (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[1]) > dealer->GetPowerDeck(dealer->GetDeck())))
						wcout << L"Вы выиграли!" << endl;

					else if (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[1]) == dealer->GetPowerDeck(dealer->GetDeck()))
						wcout << L"Ничья!" << endl;

					else if (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[1]) > 21)
						throw L"Перебор!";

					else wcout << L"Вы проиграли!" << endl;
				}

				catch (const wchar_t* exeption)
				{
					wcout << exeption << endl;
				}
			}

			else
			{
				wcout << L"Дилер: ";
				dealer->GetDeck()->Print(dealer->GetDeck()->GetCards()->size());
				wcout << endl;
				wcout << endl;
				wcout << L"Вы: ";
				dealer->GetPlayerDeck(player)[0].Print(dealer->GetPlayerDeck(player)[0].GetCards()->size());
				wcout << endl;
				wcout << endl;

				try
				{
					if (dealer->CheckBlackJack(&dealer->GetPlayerDeck(player)[0]))
						wcout << L"Блэкджек!" << endl;

					else if ((dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) <= 21) && (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) > dealer->GetPowerDeck(dealer->GetDeck())))
						wcout << L"Вы выиграли!" << endl;

					else if (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) == dealer->GetPowerDeck(dealer->GetDeck()))
						wcout << L"Ничья!" << endl;

					else if (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) > 21)
						throw L"Перебор!";

					else wcout << L"Вы проиграли!" << endl;
				}
				catch (const wchar_t* exeption)
				{
					wcout << exeption << endl;
				}
			}

			break;

		case (int)Сhoice::More:
			if (dealer->GetPlayerDeck(player)[1].GetCountCard() == 0)
			{
				deck = this->gameDeck[rand() % 4];
				this->dealer->GetPlayerDeck(this->player)[0].AddCard(deck->GetCard(deck->GetCountCard() - 1));
				deck->RemoveLastCard();
			}

			else
			{
				wcout << L"Введите номер бокса: ";
				int numberHand;
				wcin >> numberHand;
				wcout << endl;

				deck = this->gameDeck[rand() % 4];
				this->dealer->GetPlayerDeck(this->player)[numberHand].AddCard(deck->GetCard(deck->GetCountCard() - 1));
				deck->RemoveLastCard();
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