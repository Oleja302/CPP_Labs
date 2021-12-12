#pragma once
#include "HandDeck.h"

class Player
{
private:
	HandDeck hand[2]{};

	friend class Dealer;
};

