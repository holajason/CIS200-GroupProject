#pragma once
#include <iostream>
#include "Deck.h"

class Players : public Deck {
private:
	int numberOfPlayers;
	int startingAmountOfMoney;
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
		
	}

	int getNumberPlayer() {
		return this->numberOfPlayers;
	}

	int getAmountOfMoney() {
		return this->startingAmountOfMoney;
	}

	void print() {
		for (int i = 0; i < hand.size(); i++) {
			cout << hand[i] << " ";
		}
	}
};