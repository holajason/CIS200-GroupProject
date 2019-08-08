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
	//Pre: A method that will generate six decks of cards and shuffle the deck before loading
	// it to the stack of cards
	//Pos: Create a stack of cards
	void createDeck()
	{
		for (int set = 0; set < 24; set++)
		{
			//https://codereview.stackexchange.com/questions/167680/merge-sort-implementation-with-vectors
			copy(cards.begin(), cards.end(), back_inserter(cardDeck));
		}
		random_shuffle(cardDeck.begin(), cardDeck.end());
	/*	for (int index = 0; index < cardDeck.size(); index++) 
		{
			stackOfDeck.push(cardDeck[index]);
		}*/
		copy(cardDeck.begin(), cardDeck.end(), back_inserter(stackOfDeck));
	}

	void print() {
		for (int index = 0; index < cardDeck.size(); index++)
		{
			cout << cardDeck[index] << " ";
		}
	}
	//Pre: Method that will draw a card from the top of the stack
	//Pos: Drawing a card
	string drawCards()
	{
		string card = stackOfDeck.top();
		stackOfDeck.pop();
		return card;
	}

	//Pre: A method that will create a new stack of card if there are less than 30 cards
	//Pos: Create a new stack of card when less than 30 cards remaining
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
