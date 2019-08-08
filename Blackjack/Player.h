#pragma once
#include <stdlib.h>
#include "Deck.h"


class Players {
private:
	int numberOfPlayers;
	int playerBalance;
	int playerBet;
    int playerHandTotal;
	vector<string>playerHand;
public:
	Players(int numberOfPlayers){
		this->playerBalance = 100;
		this->playerBet = 0;
        this->playerHandTotal = 0;
		this->numberOfPlayers = getNumberOfPlayers(numberOfPlayers);
	}

	int getNumberOfPlayers(int numPlayers) {
		if (numPlayers < 0 || numPlayers > 10) {
			throw invalid_argument("Invalid Number Of Players(0-10)");
		}
		return numPlayers;
	}

	void distributeCards(string card) {
		playerHand.emplace_back(card);
	}

    int getCardValue(string card){
        int cardValue = 0;
        if(card == "2" || card == "3" || card == "4" ||
           card == "5" || card == "6" || card == "7" ||
           card == "8" || card == "9"){
           cardValue = stoi(card);
        }
        else if(card == "10" || card == "J" || card == "Q" || card == "K"){
            cardValue = 10;
        }
        //Needs to be modify
		else if(card == "A") {
			cardValue = 11;
		}
        return cardValue;
    }
    
    int getHandValue(){
        int total= 0;
        for(int index = 0; index < playerHand.size(); index++){
            total += this->getCardValue(playerHand[index]);
        }
        playerHandTotal = total;
        return playerHandTotal;
    }
    
	bool isBlackjack() {
		for (int firstCard = 0;  firstCard < playerHand.size(); firstCard++) {
			for (int secondCard = firstCard + 1; secondCard < playerHand.size(); secondCard++) {
				return (getBlackjack(playerHand[firstCard], playerHand[secondCard]));
			}
		}
        return false;
		this->playerBalance += playerBet;
	}

	bool isBusted(int playerHandTotal) {
		return (playerHandTotal > 21);
		this->playerBalance -= playerBet;
	}

    bool getBlackjack(string cardOne, string cardTwo) {
        return ((cardOne == "A" && (cardTwo == "10" || cardTwo == "J" ||cardTwo == "Q" ||  cardTwo == "K"))
			|| (cardTwo == "A" && (cardOne == "10" || cardOne == "J" || cardOne == "Q" || cardOne == "K")));
    }

	bool playerWins(int playerHandPts, int dealerHandPts) {
		return ((playerHandPts <= 21 && playerHandPts > dealerHandPts) 
			|| (playerHandPts <= 21 && dealerHandPts > 21));
	}

	bool isEqualHand(int playerHandPts, int dealerHandPts) {
		return (playerHandPts == dealerHandPts);
	}

	string displayOneCard() {
		return playerHand.at(1);
	}

	int getCurrentHandTotal() {
		return this->playerHandTotal;
	}

	void setPlayersBets(int amount) {
		playerBet = amount;
	}
    
	int getPlayerBets() {
		return this->playerBet;
	}

	int getRemainingBalance() {
		this->playerBalance -= this->playerBet;
		return this->playerBalance;
	}

	int drawRound() {
		this->playerBalance += this->playerBet;
		return playerBalance;
	}
    
    int getWinningAmount(){
		this->playerBalance += this->playerBet * 2;
		return playerBalance;
    }
	int getBalance() {
		return this->playerBalance;
	}

	void playAgain() {
		playerHand.clear();
	}

	friend ostream& operator << (ostream& os, Players& player) {
		for (int index = 0; index < player.playerHand.size(); index++) {
			os << player.playerHand[index] << " ";
		}
		return os;
	}
};
