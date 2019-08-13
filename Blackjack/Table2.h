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
		return players.at(playerIndex).getPlayerBalance();
	}

	void setPlayerBet(int playerIndex, int wager)
	{
		players.at(playerIndex).setBettingAmount(wager);
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

	bool playerCanHit(int playerIndex)
	{
		if (players.at(playerIndex).isBusted() || players.at(playerIndex).hasBlackJack() || players.at(playerIndex).isStanding()
			|| players.at(playerIndex).Has21())
                    return false;
        return true;
	}
	void playerHit(int playerIndex)
	{
		players.at(playerIndex).addCardToHand(deck.drawCards());
		players.at(playerIndex).updatePlayerTotal();
	}

	void playerStand(int playerIndex)
	{
		players.at(playerIndex).setToStanding();
	}
	void dealerTurn()
	{
		while (dealer.getPlayerHandTotal() < 17)
		{
			dealer.addCardToHand(deck.drawCards());
			dealer.updatePlayerTotal();
		}
		if (dealer.isBusted())
		{ 
			//remaining players on table get paid
			for (int index = 0; index < players.size(); ++index)
			{
				if (!(players.at(index).isBusted()) && !(players.at(index).hasBlackJack()))
					players.at(index).winBet();
			}
		}
		else
		{
			for (int index = 0; index < players.size(); ++index)
			{
				if (!(players.at(index).isBusted()) && !(players.at(index).hasBlackJack()))
				{
					if (players.at(index).isEqualHand(dealer.getPlayerHandTotal()))
					{
						//something to indicate draw
					}
					else if (players.at(index).playerWins(dealer.getPlayerHandTotal()))
					{
						//payout winning player
						players.at(index).winBet();
					}
					else
					{
						//player loses money
						players.at(index).loseBet();
					}
				}
			}
		}

	}

	string showDealerInitialHand() {
		string dealerCards;
		string symbol = "|#| ";
		dealerCards = "Dealer: " + symbol + dealer.showOneCard() + " " + "\n";
		return dealerCards;
	}

	string showPlayerCards(int playerIndex)
	{
		string playerCards;
		for (int index = 0; index < players.at(playerIndex).getPlayerHand().size(); index++)
		{
			playerCards += players.at(playerIndex).getPlayerHand().at(index) + " ";
		}

		return playerCards;
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
