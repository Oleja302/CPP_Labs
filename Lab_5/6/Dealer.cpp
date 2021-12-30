#include "Dealer.h"

void Dealer::Mixing(Deck* Cards)
{
	int indexCard1, indexCard2;

	Card tmp;
	for (int i = 0; i < Cards->cards.size(); i++)
	{
		indexCard1 = rand() % Cards->cards.size();
		indexCard2 = rand() % Cards->cards.size();

		if (indexCard1 == indexCard2) continue;
		tmp = Cards->cards[indexCard1];

		Cards->SetCard(indexCard1, Cards->cards[indexCard2]);
		Cards->SetCard(indexCard2, tmp);
	}
}

bool Dealer::CheckBlackJack(HandDeck* handPlayer)
{
	if (handPlayer->GetCountCard() != 5) return false;

	for (int i = 0; i < handPlayer->GetCountCard(); i++)
		if (handPlayer->GetCard(i)->GetPower() > 5) return false;

	return true;
}

bool Dealer::CheckSplit(Player* player)
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

void Dealer::Split(HandDeck* playerDeck, Deck* gameDeck)
{
	Card* tmpCard = playerDeck[0].GetCard(1);
	playerDeck[1].AddCard(tmpCard);
	playerDeck[0].power -= tmpCard->GetPower();
	playerDeck[0].RemoveLastCard();

	playerDeck[0].AddCard(gameDeck->GetCard(gameDeck->GetCountCard() - 1));
	gameDeck->RemoveLastCard();

	playerDeck[1].AddCard(gameDeck->GetCard(gameDeck->GetCountCard() - 1));
	gameDeck->RemoveLastCard();
}

HandDeck* Dealer::GetPlayerDeck(Player* player) { return player->hand; }
HandDeck* Dealer::GetDeck() { return &this->hand; }
int Dealer::GetPowerDeck(HandDeck* handDeck) { return handDeck->power; }
