#pragma once
#include "Deck.h"

class Player
{
private:

	vector<string> hand;
	int playerBalance;
	int playerBet;
	int playerHandTotal;
	bool busted;
	bool blackJack;
	bool standing;

	void updatePlayerHandTotal()
	{
		playerHandTotal = 0;
		for (int index = 0; index < hand.size(); index++)
		{
			if (hand.at(index) == "Q" || hand.at(index) == "K" || hand.at(index) == "J")
				playerHandTotal += 10;
			else if (hand.at(index) == "A")
				playerHandTotal += 11;
			else
			{
				int card = stoi(hand.at(index));
				playerHandTotal += card;
			}
		}
	}

public:

	Player()
	{
		this->playerBalance = 100;
		this->playerBet = 0;
		this->playerHandTotal = 0;
		busted = false;
		blackJack = false;
		standing = false;
	}

	void playerStatus()
	{
		this->updatePlayerHandTotal();

		if (playerHandTotal > 21)
		{
			busted = true;
		}
		if (playerHandTotal == 21)
		{
			blackJack = true;
		}
	}

	void playerReset()
	{
		busted = false;
		blackJack = false;
		playerBet = 0;
		hand.clear();
	}

	void setBettingAmount(int wager)
	{
		this->playerBet = wager;
	}

	int getBettingAmount() const
	{
		return playerBet;
	}

	bool isBusted()
	{
		return busted;
	}

	bool hasBlackJack()
	{
		return blackJack;
	}

	bool isStanding()
	{
		return standing;
	}

	void setToStanding()
	{
		standing = true;
	}

	void addCardToHand(string card)
	{
		hand.push_back(card);
	}

	int getPlayerHandTotal() const
	{
		return playerHandTotal;
	}
	void winBet()
	{
		playerBalance += playerBet;
	}
	void loseBet()
	{
		playerBalance -= playerBet;
	}

	int getPlayerBalance() const
	{
		return playerBalance;
	}

	bool emptyPockets()
	{
		return (playerBalance <= 0);
	}

	vector<string> getPlayerHand() const
	{
		return hand;
	}
};