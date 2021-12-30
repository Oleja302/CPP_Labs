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

	while (static_cast<�hoice>(answer) != �hoice::Enough)
	{
		wcout << "[" << this->gameDeck[0]->GetCountCard() << "] ";
		wcout << "[" << this->gameDeck[1]->GetCountCard() << "] ";
		wcout << "[" << this->gameDeck[2]->GetCountCard() << "] ";
		wcout << "[" << this->gameDeck[3]->GetCountCard() << "] " << endl;

		wcout << endl;
		wcout << L"�����: ";

		dealer->GetDeck()->Print(dealer->GetDeck()->GetCountCard() - 1);
		wcout << L"??" << endl;
		wcout << endl;

		if (dealer->GetPlayerDeck(player)[1].GetCountCard() == 0)
		{
			wcout << L"��: ";
			dealer->GetPlayerDeck(player)[0].Print(dealer->GetPlayerDeck(player)[0].GetCards()->size());
			wcout << endl;
			wcout << endl;
		}
		else
		{
			wcout << L"��: ";
			dealer->GetPlayerDeck(player)[0].Print(dealer->GetPlayerDeck(player)[0].GetCards()->size());
			wcout << endl;
			dealer->GetPlayerDeck(player)[1].Print(dealer->GetPlayerDeck(player)[1].GetCards()->size());
			wcout << endl;
			wcout << endl;
		}

		if (split)	wcout << L"1. ������" << endl << L"2. ���" << endl << L"3. �����?" << endl;
		else wcout << L"1. ������" << endl << L"2. ���" << endl;

		wcin >> answer;
		wcout << endl;

		switch (answer)
		{
		case (int)�hoice::Enough:

			if (dealer->GetPlayerDeck(player)[1].GetCountCard() != 0)
			{
				wcout << L"�����: ";
				dealer->GetDeck()->Print(dealer->GetDeck()->GetCards()->size());
				wcout << endl;
				wcout << endl;
				wcout << L"��: ";
				dealer->GetPlayerDeck(player)[0].Print(dealer->GetPlayerDeck(player)[0].GetCards()->size());
				wcout << endl;
				dealer->GetPlayerDeck(player)[1].Print(dealer->GetPlayerDeck(player)[1].GetCards()->size());
				wcout << endl;
				wcout << endl;

				wcout << L"������ ������: ";

				try
				{
					if (dealer->CheckBlackJack(&dealer->GetPlayerDeck(player)[0]))
						wcout << L"��������!" << endl;

					else if ((dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) <= 21) && (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) > dealer->GetPowerDeck(dealer->GetDeck())))
						wcout << L"�� ��������!" << endl;

					else if (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) == dealer->GetPowerDeck(dealer->GetDeck()))
						wcout << L"�����!" << endl;

					else if (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) > 21)
						throw L"�������!";

					else wcout << L"�� ���������!" << endl;
				}

				catch (const wchar_t* exeption)
				{
					wcout << exeption << endl;
				}

				wcout << L"������ ������: ";

				try
				{
					if (dealer->CheckBlackJack(&dealer->GetPlayerDeck(player)[1]))
						wcout << L"��������!" << endl;

					else if ((dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[1]) <= 21) && (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[1]) > dealer->GetPowerDeck(dealer->GetDeck())))
						wcout << L"�� ��������!" << endl;

					else if (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[1]) == dealer->GetPowerDeck(dealer->GetDeck()))
						wcout << L"�����!" << endl;

					else if (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[1]) > 21)
						throw L"�������!";

					else wcout << L"�� ���������!" << endl;
				}

				catch (const wchar_t* exeption)
				{
					wcout << exeption << endl;
				}
			}

			else
			{
				wcout << L"�����: ";
				dealer->GetDeck()->Print(dealer->GetDeck()->GetCards()->size());
				wcout << endl;
				wcout << endl;
				wcout << L"��: ";
				dealer->GetPlayerDeck(player)[0].Print(dealer->GetPlayerDeck(player)[0].GetCards()->size());
				wcout << endl;
				wcout << endl;

				try
				{
					if (dealer->CheckBlackJack(&dealer->GetPlayerDeck(player)[0]))
						wcout << L"��������!" << endl;

					else if ((dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) <= 21) && (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) > dealer->GetPowerDeck(dealer->GetDeck())))
						wcout << L"�� ��������!" << endl;

					else if (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) == dealer->GetPowerDeck(dealer->GetDeck()))
						wcout << L"�����!" << endl;

					else if (dealer->GetPowerDeck(&dealer->GetPlayerDeck(player)[0]) > 21)
						throw L"�������!";

					else wcout << L"�� ���������!" << endl;
				}
				catch (const wchar_t* exeption)
				{
					wcout << exeption << endl;
				}
			}

			break;

		case (int)�hoice::More:
			if (dealer->GetPlayerDeck(player)[1].GetCountCard() == 0)
			{
				deck = this->gameDeck[rand() % 4];
				this->dealer->GetPlayerDeck(this->player)[0].AddCard(deck->GetCard(deck->GetCountCard() - 1));
				deck->RemoveLastCard();
			}

			else
			{
				wcout << L"������� ����� �����: ";
				int numberHand;
				wcin >> numberHand;
				wcout << endl;

				deck = this->gameDeck[rand() % 4];
				this->dealer->GetPlayerDeck(this->player)[numberHand].AddCard(deck->GetCard(deck->GetCountCard() - 1));
				deck->RemoveLastCard();
			}

			split = false;
			break;

		case (int)�hoice::Split:
			if (split) dealer->Split(dealer->GetPlayerDeck(player), deck);
			split = false;
			break;

		default:
			break;
		}
	}
}