#pragma once
#include "HandDeck.h"
#include "Player.h"

class Dealer
{
private:
	HandDeck hand;

public:
	void Mixing(Deck* Cards);
	bool CheckBlackJack(HandDeck* handPlayer);
	bool CheckSplit(Player* player);
	void Split(HandDeck* playerDeck, Deck* gameDeck);
	HandDeck* GetPlayerDeck(Player* player);
	HandDeck* GetDeck();
	int GetPowerDeck(HandDeck* handDeck);
};

