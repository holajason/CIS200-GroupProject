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
		for (int numberOfCards = 0; numberOfCards < 2; ++numberOfCards)
		{
			for (int index = 0; index < players.size(); ++index)
			{

				players.at(index).addCardToHand(deck.drawCards());
			}
			dealer.addCardToHand(deck.drawCards());
		}
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
			
					return;
				}
				else if (hit == false)
				{
					players.at(index).setToStanding();
					return;
				}

		}
	}

	void showDealerCard() {
		cout << "Dealer: " << "|#| " << dealer.showOneCard() << " ";
		cout << endl;
	}

	friend ostream& operator <<(ostream& os, Table& table) {
		for (int index = 0; index < table.players.size(); index++) {
			os << "Player " << index +1 << ": " << table.players[index] <<" ";
			os << endl;
		}

		
		return os;
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
