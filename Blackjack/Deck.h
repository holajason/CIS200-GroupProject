#pragma once
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

class Deck {
private:
	vector<string>cards{ "2","3","4","5","6","7","8","9","10","J","Q","K","A" };
	vector<string>cardDeck;
	stack<string>stackOfDeck;
	int currentCardCount;
public:
	Deck() {
		currentCardCount = 0;
	}
	void createDeck() {
		for (int set = 0; set < 24; set++) {
			for (int counts = 0; counts < cards.size(); counts++) {
				cardDeck.push_back(cards[counts]);
				random_shuffle(cardDeck.begin(), cardDeck.end());
			}
		}
		for (int index = 0; index < cardDeck.size(); index++) {
			stackOfDeck.push(cardDeck[index]);

		}
	}

	string drawCards() {
		string card;
		card = stackOfDeck.top();
		stackOfDeck.pop();
		currentCardCount--;
		return card;
	}

	void print() {
		cout << "Stack Size: " << stackOfDeck.size();
	}

	int getNumberOfCards() {
		return this->currentCardCount;
	}
};