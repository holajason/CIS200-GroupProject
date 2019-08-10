#pragma once
#include "Player(new).h"

class Table
{
private:
	int numberOfPlayers;
	vector<Player> players;
	Player dealer;
	Deck deck;

	void deckStatus()
	{
		if (deck.getNumberOfCards() <= 30)
		{
			deck.reshuffle();
		}
	}

public:
	Table(int numberOfPlayers)
	{
		this->numberOfPlayers = numberOfPlayers;
		this->players.resize(numberOfPlayers);
		deck.createDeck();
	}

	int getNumberOfPlayers()
	{
		return numberOfPlayers;
	}

	int getPlayerBalance(int playerIndex)
	{
        int balance = 0;
		for (int index = 0; index < players.size(); ++index)
		{
			if (playerIndex == index)
				balance = players.at(index).getPlayerBalance();
		}
        return balance;
	}

	vector<string> getPlayerHand(int playerIndex) const
	{
        int total;
		for (int index = 0; index < players.size(); ++index)
		{
			if (playerIndex == index)
				total = players.at(index).getPlayerHand());
		}
        return temp;
	}

	void setPlayerBets(int wager)
	{
		for (int index = 0; index < players.size(); ++index)
		{
			if (players.at(index).getBettingAmount() == 0)
			{
				players.at(index).setBettingAmount(wager);
				break;
			}
		}
	}

	void initRound()
	{
		for (int index = 0; index < players.size(); ++index)
		{
			for (int numberOfCards = 0; numberOfCards < 2; ++numberOfCards)
			{
				players.at(index).addCardToHand(deck.drawCards());
			}

			players.at(index).playerStatus();
		}

		dealer.addCardToHand(deck.drawCards());
		dealer.addCardToHand(deck.drawCards());
		dealer.playerStatus();
	}

	bool playerAbleToHit(int playerIndex)
	{
		for (int index = 0; index < players.size(); ++index)
		{
			if (playerIndex == index)
			{
				if (players.at(index).isBusted() || players.at(index).hasBlackJack() || players.at(index).isStanding())
                    return false;
			}
		}
        return true;
	}
	void playerTurn(int playerIndex, bool hit)
	{
		for (int index = 0; index < players.size(); ++index)
		{
			if (playerIndex == index)
				if (hit == true)
				{
					players.at(index).addCardToHand(deck.drawCards());
					players.at(index).playerStatus();
					return;
				}
				else if (hit == false)
				{
					players.at(index).setToStanding();
					return;
				}

		}
	}

	void reset()
	{
		for (int index = 0; index < players.size(); ++index)
		{
			if (players.at(index).emptyPockets())
			{
				players.erase(players.begin() + index);
				--numberOfPlayers;
			}
			else
				players.at(index).playerReset();
		}
		dealer.playerReset();
		this->deckStatus();
	}

};
