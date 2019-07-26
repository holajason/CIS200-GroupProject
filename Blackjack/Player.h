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
		for (int i = 0; i < 1; i++) {
			cout << deck.drawCards() << " ";
		}
		cout << endl;
	}

	int getNumberPlayer() {
		return this->numberOfPlayers;
	}

	int getAmountOfMoney() {
		return this->startingAmountOfMoney;
	}
};