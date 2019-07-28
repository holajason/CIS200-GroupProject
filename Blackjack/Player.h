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
    int playerHandTotal;
	vector<string>hand;
public:
	Players(int numberOfPlayers)
	{
        playerHandTotal = 0;
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
                value = 1 ;
            }
        }
        return value;
    }
    
    int getHandTotal(){
        int total= 0;
        for(int index = 0; index < hand.size(); index++){
            total+= getAvalue(hand[index]);
            total += getHandValue(hand[index]);
        }
        playerHandTotal = total;
        return playerHandTotal;
    }
    
    int getPlayerHandTotal(){
        return this->playerHandTotal;
    }
	void print() {
		for (int i = 0; i < hand.size(); i++) {
			cout << hand[i] << " ";
            if(getBlackjack(hand[i])==true){
                cout << "Blackjack" <<endl;
            }
		}
	}
    
    bool getBlackjack(string card){
        return (card == "A" &&(card == "10" || card == "J" ||card == "Q" || card == "K"));
    }
	int getBettingAMount(int amount) {
		playerBet = amount;
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
