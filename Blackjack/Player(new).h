#pragma once
#include "Deck.h"

class Player
{
private:
	vector<string> hand;
	int playerBalance;
	int playerBet;
	int playerHandTotal;
    busted = false;
    blackJack = false;
    standing = false;

    int getCardValue(string card){
        int cardValue = 0;
         if(card == "J" || card == "Q" || card == "K"){
            cardValue = 10;
        }
         else{
             cardValue = stoi(card);
         }
        return cardValue;
    }
    
    int updatePlayerTotal(){
        int currPts = 0;
        for(int index = 0; index < hand.size(); index++){
            currPts += this->getCardValue(hand[index]);
        }
        for(int index = 0; index < hand.size(); index++){
            if(hand[index] == "A"){
                if(currPts >= 11){
                    currPts +=1;
                }
                else{
                    currPts += 11;
                }
            }
        }
        playerHandTotal = currPts;
        return pslayerHandTotal;
    }
    

public:
	Player()
	{
		this->playerBalance = 100;
		this->playerBet = 0;
		this->playerHandTotal = 0;
	}

	void playerStatus()
	{
        this->updatePlayerTotal();
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
