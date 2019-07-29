#pragma once
#include <iostream>
#include <stdlib.h>
#include "Deck.h"
#include "Dealer.h"

class Players : public Dealer {
private:
	int numberOfPlayers;
	int totalBalance;
	int playerBet;
    int playerHandTotal;
	vector<string>hand;
public:
	Players(int numberOfPlayers)
	{
		this->totalBalance = 100;
		this->playerBet = 0;
        this->playerHandTotal = 0;
		getNumberOfPlayers(numberOfPlayers);
	}

	void distributePlayerCards(string card) {
		hand.emplace_back(card);
	}

    int getHandValue(string values){
        int value = 0;
        if(values == "2" ||values == "3" || values == "4" ||
            values == "5" || values== "6" || values == "7" ||
            values == "8" ||values == "9"){
            value = stoi(values);
        }
        else if(values == "10" || values == "J" ||values == "Q" || values == "K"){
            value = 10;
        }
        return value;
    }
    
    int getAvalue(string values){
        int value = 0;
        char choice;
        if (values == "A") {
            cout << "Do You want A to be 11 points(Y/N): ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                value = 11;
            }
            else{
                value = 1;
            }
        }
        return value;
    }
    
	void playAgain() {
		hand.clear();
	}

    int getHandTotalValue(){
        int total= 0;
        for(int index = 0; index < hand.size(); index++){
            total+= getAvalue(hand[index]);
            total += getHandValue(hand[index]);
        }
        playerHandTotal = total;
        return playerHandTotal;
    }

	int getSoftHandTotalValue() {
		int total = 0;
		for (int index = 0; index < hand.size(); index++) {
			total += getHandValue(hand[index]);
		}
		return total;
	}
    
	bool isBlackjack() {
		for (int i = 0; i < hand.size(); i++) {
			for (int j = i + 1; j < hand.size(); j++) {
				return (getBlackjack(hand[i], hand[j]));
			}
		}
		this->totalBalance += playerBet;
	}

	bool isBusted(int playerHandTotal) {
		return (playerHandTotal > 21);
		this->totalBalance -= playerBet;
	}

    bool getBlackjack(string cardOne, string cardTwo) {
        return ((cardOne == "A" && (cardTwo == "10" || cardTwo == "J" ||cardTwo == "Q" ||  cardTwo == "K"))
			|| (cardTwo == "A" && (cardOne == "10" || cardOne == "J" || cardOne == "Q" || cardOne == "K")));
    }

	bool playerWins(int playerHandPts, int dealerHandPts) {
		return ((playerHandPts <= 21 && playerHandPts > dealerHandPts) 
			|| (playerHandPts <= 21 && dealerHandPts > 21));
	}

	bool equallyHandTotal(int playerHandPts, int dealerHandPts) {
		return (playerHandPts == dealerHandPts);
	}

	int getNumberOfPlayers(int numPlayers) {
		if (numPlayers > 10 || numPlayers < 0) {
			throw invalid_argument("Invalid Number Of Players(0-10)");
		}
		else {
			this->numberOfPlayers = numPlayers;
		}
		return this->numberOfPlayers;
	}

	string displayOneCard() {
		return hand.at(1);
	}

	int getCurrentHandTotal() {
		return this->playerHandTotal;
	}

	int setPlayersBets(int amount) {
		playerBet = amount;
		return this->playerBet;
	}
    
	int getPlayerBets() {
		return this->playerBet;
	}

	int getRemainingBalance() {
		this->totalBalance -= this->playerBet;
		return this->totalBalance;
	}

	int getDrawRoundMoney() {
		this->totalBalance += this->playerBet;
		return totalBalance;
	}
    
    int getWinningAmount(){
		this->totalBalance += this->playerBet * 2;
		return totalBalance;
    }
	int getBalance() {
		return this->totalBalance;
	}

	friend ostream& operator << (ostream& os, Players& player) {
		for (int index = 0; index < player.hand.size(); index++) {
			os << player.hand[index] << " ";
		}
		return os;
	}
};
