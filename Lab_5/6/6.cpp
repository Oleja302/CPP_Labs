#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
using namespace std;

#include "Card.h"
#include "Deck.h"
#include "HandDeck.h"
#include "Dealer.h"
#include "Game.h"

int main()
{
	setlocale(LC_ALL, "RU");
	_setmode(_fileno(stdout), _O_U16TEXT);
	srand((time(0)));

	vector<Card> cards1;
	vector<Card> cards2;
	vector<Card> cards3;
	vector<Card> cards4;

	Deck* deck1 = new Deck(cards1);
	Deck* deck2 = new Deck(cards2);
	Deck* deck3 = new Deck(cards3);
	Deck* deck4 = new Deck(cards4);

	Player* player = new Player();
	Dealer* dealer = new Dealer();

	Game game(deck1, deck2, deck3, deck4, player, dealer);
	game.Run();

	delete deck1;
	delete deck2;
	delete deck3;
	delete deck4;

	delete player;
	delete dealer;

	return 0;
}

