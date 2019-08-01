#pragma once
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class Deck {
private:
	vector<string>cards{ "2","3","4","5","6","7","8","9","10","J","Q","K","A" };
	vector<string>cardDeck;

public:
	stack<string>stackOfDeck;
	void createDeck() {
		for (int set = 0; set < 24; set++) {
			for (int counts = 0; counts < cards.size(); counts++) {
				cardDeck.push_back(cards[counts]);
			}
		}
		random_shuffle(cardDeck.begin(), cardDeck.end());
		for (int index = 0; index < cardDeck.size(); index++) {
			stackOfDeck.push(cardDeck[index]);
		}
	}

	string drawCards() {
		string card = stackOfDeck.top();
		stackOfDeck.pop();
		return card;
	}

	void reshuffle() {
		while (!stackOfDeck.empty()) {
			stackOfDeck.pop();
		}
		cardDeck.clear(); // Remove remaining cards from the deck
		createDeck();
	}

	int getNumberOfCards() {
		return this->stackOfDeck.size();
	}


};
