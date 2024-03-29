#pragma once
#include <stdlib.h>
#include "Deck.h"

class Player {
private:
	int playerBalance;
	int playerBet;
    int playerHandTotal;
	bool removed;
	vector<string>playerHand;

	int getCardValue(string card)
	{
		int cardValue = 0;
		if (card == "J" || card == "Q" || card == "K") {
			cardValue = 10;
		}
		else if (card == "A") {
			cardValue = 0;
		}
		else {
			cardValue = stoi(card);
		}
		return cardValue;
	}

public:
	Player()
	{
		this->playerBalance = 100;
		this->playerBet = 0;
        this->playerHandTotal = 0;
		this->removed = false;
	}

	//Pre: Function that will hand pthe player a card
	//Pos: Hand a card to the player
	void addOneCardToHand(string card)
	{
		playerHand.emplace_back(card);
	}
  

	//Pre: Function that will track the player hand total after receiving a card from the dealer
	//Pos: Function that tracks the current hand-value of the player
    void updatePlayerHandTotal()
	{
        int currentPts= 0;
		//First iteration that will add all cards value except A's
        for(int index = 0; index < playerHand.size(); index++)
		{
            currentPts += this->getCardValue(playerHand[index]);
        }
		//2nd iteration that only add A's value
		for (int index = 0; index < playerHand.size(); index++)
		{
			if (playerHand[index] == "A") {
				if (currentPts >= 11) {
					currentPts += 1;
				}
				else {
					currentPts += 11;
				}
			}
		}
        playerHandTotal = currentPts;
    }
    
	//Pre: If the player first two cards is A and a 10 pts card, player will wins automatically
	//Pos: Player wins if the first two cards are A and a 10 pts card (10, J, Q, K)
	bool isBlackjack() {
		return (getBlackjack(playerHand[0], playerHand[1]));
		this->playerBalance += playerBet;
	}

	//Pre: Player will lose if total points more than 21
	//Pos: Player lose when total point exceeed 21
	bool isBusted(int playerHandTotal)
	{
		return (playerHandTotal > 21);
		this->playerBalance -= playerBet;
	}

	//Pre: Helper function that check the first two cards
	//Pos: Check first two cards
    bool getBlackjack(string cardOne, string cardTwo)
	{
        return ((cardOne == "A" && (cardTwo == "10" || cardTwo == "J" ||cardTwo == "Q" ||  cardTwo == "K"))
			|| (cardTwo == "A" && (cardOne == "10" || cardOne == "J" || cardOne == "Q" || cardOne == "K")));
    }

	//Pre: Player wins if total point are less than 21 and greater than dealer's hand
	//Pos: Player wins by not busted and have more points than the dealer
	bool playerWins(int playerHandPts, int dealerHandPts) 
	{
		return ((playerHandPts <= 21 && playerHandPts > dealerHandPts) ||
			(playerHandPts <= 21 && dealerHandPts > 21));
	}

	//Pre: Will check if both player and dealer have same amount of points
	//Pos: Draw round when dealer and player have same amount of points
	bool isEqualHand(int playerHandPts, int dealerHandPts)
	{
		return (playerHandPts == dealerHandPts);
	}

	//Pre: Will display one card
	//Pos: Dealer showing one card up
	string displayOneCard() 
	{
		return playerHand.at(1);
	}

	int getPlayerHandTotal()
	{
		return this->playerHandTotal;
	}

	void setPlayersBets(int amount)
	{
		playerBet = amount;
	}
    
	int getPlayerBets()
	{
		return this->playerBet;
	}

	int getRemainingBalance() 
	{
		this->playerBalance -= this->playerBet;
		return this->playerBalance;
	}

	int drawRound()
	{
		this->playerBalance += this->playerBet;
		return playerBalance;
	}
    
    int getWinningAmount()
	{
		this->playerBalance += this->playerBet * 2;
		return playerBalance;
    }

	int getBalance() 
	{
		return this->playerBalance;
	}

	void playAgain()
	{
		playerHand.clear();
	}

	bool isBroke()
	{
		return this->playerBalance <= 0;
	}

	void removePlayer()
	{
		this->removed = true;
	}

	bool isRemoved()
	{
		return removed;
	}
	friend ostream& operator << (ostream& os, Player& player) 
	{
		for (int index = 0; index < player.playerHand.size(); index++) 
		{
			os << player.playerHand[index] << " ";
		}
		return os;
	}
};

