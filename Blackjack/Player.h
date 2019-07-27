#pragma once
#include <iostream>
#include <stdlib.h>
#include "Deck.h"
#include "Dealer.h"

class Players : public Dealer {
private:
	int numberOfPlayers;
	int startingAmountOfMoney;
    int remainMoney;
	int totalMoney;
	int playerBet;
	vector<string>hand;
public:
	Players(int numberOfPlayers)
	{
		this->startingAmountOfMoney = 100;
		this->totalMoney = 100;
		this->numberOfPlayers = numberOfPlayers;
	}

	virtual void distributeCards() {
		Deck deck;
		deck.createDeck();
		//Dealer card;
		//hand.push_back(card.distributeCard());
		hand.push_back(deck.drawCards());
	}

    int getHandTotal(string values){
        int value = 0;
        if(values == "2" ||values == "3" || values == "4" ||
            values == "5" || values== "6" || values == "7" ||
            values == "8" ||values == "9"){
            value = stoi(values);
        }
        else if(values == "J" ||values == "Q" || values == "K"){
            value = 10;
        }
        return value;
    }
    
	void print() {
		for (int i = 0; i < hand.size(); i++) {
			cout << hand[i] << " ";
		}
	}
    
    int getTotal(){
        int total = 0;
		char choice;
        for (int i = 0; i < hand.size(); i++) {
			if (hand[i] == "A") {
				cout << "\nDo You wany A to be 11 points(Y/N): ";
				cin >> choice;
				if (choice == 'Y' || choice == 'y') {
					total += 11;
				}
				else {
					total += 1;
				}
				break;
			}
            total += getHandTotal(hand[i]);
        }
        return total;
    }
    
	//int getCurrentPoint() {
	//	int total = 0;
	//	for (int index = 0; index < hand.size(); index++) {
	//		total += getHandTotal(hand[index]);
	//	}
	//	return total;
	//}

	int getBettingAMount(int amount) {
		playerBet = amount;
		getRemainingBalance();
		return this->playerBet;
	}
	int getBet() {
		return this->playerBet;
	}
	int getStartingBalance() {
		return this->startingAmountOfMoney;
	}

	int getRemainingBalance() {
		this->totalMoney -= this->playerBet;
		return this->totalMoney;
	}
    int getNumberPlayer() {
        return this->numberOfPlayers;
    }
    
    int getWinningMoney(){
		this->totalMoney += this->playerBet * 2;
		return totalMoney;
    }
	int getBalance() {
		return this->totalMoney;
	}
};
