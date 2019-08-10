#pragma once
#include "Deck.h"

class Player
{
private:
	vector<string> hand;
	int playerBalance;
	int playerBet;
	int playerHandTotal;
    bool busted = false;
    bool blackJack = false;
    bool standing = false;

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
        return playerHandTotal;
    }
    

public:
	Player()
	{
		this->playerBalance = 100;
		this->playerBet = 0;
		this->playerHandTotal = 0;
	}

    bool isBusted()
    {
        return (playerHandTotal > 21);
        this->playerBalance -= playerBet;
    }
    
    //Pre: If the player first two cards is A and a 10 pts card, player will wins automatically
    //Pos: Player wins if the first two cards are A and a 10 pts card (10, J, Q, K)
    bool isBlackjack() {
        return (getBlackjack(hand[0], hand[1]));
        this->playerBalance += playerBet;
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
    bool playerWins( int dealerHandPts)
    {
        return ((playerHandTotal <= 21 && playerHandTotal > dealerHandPts) ||
                (playerHandTotal <= 21 && dealerHandPts > 21));
    }
    
    //Pre: Will check if both player and dealer have same amount of points
    //Pos: Draw round when dealer and player have same amount of points
    bool isEqualHand(int playerHandPts, int dealerHandPts)
    {
        return (playerHandPts == dealerHandPts);
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

	string showOneCard() {
		return hand.at(1);
	}
	
	friend ostream& operator <<(ostream& os, Player& table) {
		for (int index = 0; index < table.hand.size(); index++) {
			os << table.hand[index] << " ";
		}
		return os;
	}
};
