#pragma once
#include "Player.h"
#include "NPCPlayer.h"

class BlackJackTable : Player
{
private:
	int numberOfPlayers;
	vector<Player> players;
	Player dealer;
	NPCPlayer npc;
	Deck deck;
public:
	BlackJackTable(int numPlayers) : Player(1)
	{
		this->numberOfPlayers = numPlayers;
		players.resize(numberOfPlayers);
		deck.createDeck();
	}
};