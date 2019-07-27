#pragma once
#include "Player.h"
#include "Deck.h"

class Dealer : public Deck {
private:
	vector<string> hand;
public:
	Dealer() {

	}

	virtual void distributeCards() {
		Deck deck;
		deck.createDeck();
		//Dealer card;
		//hand.push_back(card.distributeCard());
		hand.push_back(deck.drawCards());
	}


	int getHandTotal(string values) {
		int value = 0;
		if (values == "2" || values == "3" || values == "4" ||
			values == "5" || values == "6" || values == "7" ||
			values == "8" || values == "9") {
			value = stoi(values);
		}
		else if (values == "J" || values == "Q" || values == "K") {
			value = 10;
		}
		return value;
	}

	int getCurrentPoint() {
		int total = 0;
		for (int index = 0; index < hand.size(); index++) {
			total = getHandTotal(hand[index]);
		}
		return total;
	}


};
