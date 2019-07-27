#pragma once
#include <iostream>
#include <stdlib.h>
#include "Deck.h"

class Players : public Deck {
private:
	int numberOfPlayers;
	int startingAmountOfMoney;
    int remainMoney;
    int playerHandCards;
	vector<string>hand;
public:
	Players(int numberOfPlayers)
	{
		this->startingAmountOfMoney = 100;
		this->numberOfPlayers = numberOfPlayers;
	}

	virtual void distributeCards() {
		Deck deck;
		deck.createDeck();
		hand.push_back(deck.drawCards());
        playerHandCards++;
		
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
        for (int i = 0; i < hand.size(); i++) {
            total += getHandTotal(hand[i]);
        }
        return total;
    }
    
    void getCount(){
        for(int i = 0; i < 2; i++){
            distributeCards();
    }
    }
    
    
    int getNumberPlayer() {
        return this->numberOfPlayers;
    }
    
    int getAmountOfMoney() {
        return this->startingAmountOfMoney;
    }
    
    int getRemainingMoney(){
        return this->remainMoney;
    }
    int placingBet(int amount){
        remainMoney = startingAmountOfMoney - amount;
        return remainMoney;
    }
    
    int getPlayerHandCount(){
        return this->playerHandCards;
    }
};
