#pragma once
#include "Deck.h"

class Player
{
private:
	vector<string> hand;
	int playerBalance;
	int playerBet;
	int playerHandTotal;
    bool standing = false;

    int getCardValue(string card){
        int cardValue = 0;
		if (card == "J" || card == "Q" || card == "K") {
			cardValue = 10;
		}
		//this is just so "A" doesn't get passed to stoi
		else if (card == "A")
			cardValue = 0;
         else{
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
	}

	void updatePlayerTotal() {
		int currPts = 0;
		for (int index = 0; index < hand.size(); index++) {
			currPts += this->getCardValue(hand[index]);
		}
		for (int index = 0; index < hand.size(); index++) {
			if (hand[index] == "A") {
				if (currPts >= 11) {
					currPts += 1;
				}
				else {
					currPts += 11;
				}
			}
		}
		playerHandTotal = currPts;
	}

    bool isBusted()
    {
        return (playerHandTotal > 21);
    }
    
    //Pre: If the player first two cards is A and a 10 pts card, player will wins automatically
    //Pos: Player wins if the first two cards are A and a 10 pts card (10, J, Q, K)
    bool hasBlackJack() {
        return blackJack(hand[0], hand[1]);
    }
    //Pre: Helper function that check the first two cards
    //Pos: Check first two cards
    bool blackJack(string cardOne, string cardTwo)
    {
        return ((cardOne == "A" && (cardTwo == "10" || cardTwo == "J" ||cardTwo == "Q" ||  cardTwo == "K"))
                || (cardTwo == "A" && (cardOne == "10" || cardOne == "J" || cardOne == "Q" || cardOne == "K")));
    }

	bool Has21()
	{
		return this->playerHandTotal == 21;
	}

    //Pre: Player wins if total point are less than 21 and greater than dealer's hand
    //Pos: Player wins by not busted and have more points than the dealer
    bool playerWins(int dealerHandPts)
    {
		return (this->playerHandTotal > dealerHandPts);
    }
    
    //Pre: Will check if both player and dealer have same amount of points
    //Pos: Draw round when dealer and player have same amount of points
    bool isEqualHand(int dealerHandPts)
    {
        return (this->playerHandTotal == dealerHandPts);
    }

	void playerReset()
	{
		playerBet = 0;
		hand.clear();
		this->standing = false;
	}

	void setBettingAmount(int wager)
	{
		this->playerBet = wager;
	}

	int getBettingAmount() const
	{
		return playerBet;
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
