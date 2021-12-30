#pragma once
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

class Game
{
private:
	Deck** gameDeck;
	Player* player;
	Dealer* dealer;

	enum class Ñhoice
	{
		Enough = 1,
		More,
		Split
	};

public:
	Game(Deck* deck1, Deck* deck2, Deck* deck3, Deck* deck4, Player* player, Dealer* dealer);
	void Run();
};

