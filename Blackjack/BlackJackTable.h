#pragma once
#include "Player.h"
#include "NPCPlayer.h"

class BlackJackTable
{
private:
	int numberOfPlayers;
	vector<Player> players;
	Player dealer;
	NPCPlayer npc;
	Deck deck;
public:
	BlackJackTable(int numPlayers)
	{
		this->numberOfPlayers = numPlayers;
		players.resize(numberOfPlayers);
		deck.createDeck();
	}
};