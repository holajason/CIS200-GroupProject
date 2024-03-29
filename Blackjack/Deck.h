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
	stack<string>stackOfDeck;
public:
	//Pre: Will combine six decks of card into one and shuffle the deck before loading it to the stack of cards
	//Pos: Create a stack of cards, shuffle the deck and load to the stack
	void createDeck()
	{
		for (int set = 0; set < 24; set++)
		{
			//https://codereview.stackexchange.com/questions/167680/merge-sort-implementation-with-vectors
			copy(cards.begin(), cards.end(), back_inserter(cardDeck));
		}
		random_shuffle(cardDeck.begin(), cardDeck.end());
		for (int index = 0; index < cardDeck.size(); index++) 
		{
			stackOfDeck.push(cardDeck[index]);
		}
	}

	//Pre: Method that will draw a card from the top of the stack and reshuffle is size less than 30
	//Pos: Drawing a card and reshuffle deck when less than 30
	string drawCard()
	{
		string card = stackOfDeck.top();
		stackOfDeck.pop();
		if (stackOfDeck.size() < 30) {
			reshuffle();
		}
		return card;
	}

	//Pre: A method that will remove the remaining cards and create a new stack of card
	//Pos: Remove remaining cards and create a new stack of card
	void reshuffle()
	{
		while (!stackOfDeck.empty()) 
		{
			stackOfDeck.pop();
		}
		cardDeck.clear(); // Remove remaining cards from the deck
		createDeck();
	}

	int getNumberOfCards() 
	{
		return this->stackOfDeck.size();
	}


};
