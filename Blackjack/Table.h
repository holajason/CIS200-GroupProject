#pragma once
#include "Player.h"
#include "NPCPlayer.h"


class Table
{
private:
	int numberOfPlayers;
	vector<Player> players;
	Player dealer;
	NPCPlayer computerPlayer;
	Deck deck;
	void deckStatus()
	{
		/*
		cout << "Deck Size: " << deck.getNumberOfCards();
		if (stackOfDeck.size() < 30) {
			reshuffle();
		}
		*/
	}

public:
	Table(int numberOfPlayers)
	{
        setNumberOfPlayers( numberOfPlayers);
		this->players.resize(numberOfPlayers);
		deck.createDeck();
	}

	void initRound()
	{
		for (int numberOfCards = 0; numberOfCards < 2; ++numberOfCards)
		{
			for (int index = 0; index < players.size(); ++index)
			{
				if (players[index].isRemoved())
					continue;
				players[index].addOneCardToHand(deck.drawCard());
			}
			dealer.addOneCardToHand(deck.drawCard());
			computerPlayer.addOneCardToHand(deck.drawCard());
		}
		//deckStatus();
	}

	int setNumberOfPlayers(int numPlayers)
	{
		if (numPlayers <= 0 || numPlayers > 10)
		{
			throw invalid_argument("Invalid Number Of Players(1-10)");
		}
		return this-> numberOfPlayers = numPlayers;
	}

	void removeInsufficientFundPlayer()
	{
		int numberOfRemovedPlayers = 0;
		for (int index = 0; index < players.size(); ++index)
		{
			if (players[index].isBroke())
			{
				players[index].removePlayer();
				numberOfRemovedPlayers++;
			}
		}
		if (numberOfRemovedPlayers == players.size())
		{
			throw invalid_argument("No more players at table\n");
		}
	}

	void getPlayersBet() {
		int playerBets;
		for (int index = 0; index < players.size(); index++) {
			if (players[index].isRemoved())
				continue;
			players[index].playAgain(); // reset player hand
			dealer.playAgain();			//reset dealer hand
			computerPlayer.playAgain();
			cout << "Player " << index + 1 << " Please Place Your Bet: ";
			cin >> playerBets;
			players[index].setPlayersBets(playerBets);	//get player bets
			players[index].getRemainingBalance();
		}
		computerPlayer.setPlayersBets(1);		//Computer player bet
		computerPlayer.getRemainingBalance();
	}


	void playerTurn() {
		int choice;
		for (int index = 0; index < players.size(); index++)
		{
			if (players[index].isRemoved())
				continue;
			cout << "\n-----------------------------------" << endl;
			cout << "Player: " << index + 1 << " | " << "Current Balance: " << players[index].getBalance() << endl;
			cout << "Current hand: " << players[index] << endl;	//display current hand
			cout << "===================================" << endl;
			do
			{
				if (players[index].isBlackjack()) 	//if player first two card is blackjack, automatically wins
				{
					cout << "****************" << endl;
					cout << "*  Blackjack!  *" << endl;
					cout << "****************" << endl;
					choice = 2;
					break;
				}
				else
				{
					cout << "Player: " << index + 1 << " | Hit(1) OR Stand(2): ";
					cin >> choice;
					switch (choice) {
					case 1:
						cout << "===================================" << endl;
						cout << "Player: " << index + 1 << " | ";
						players[index].addOneCardToHand(deck.drawCard());
						cout << "Current hand: " << players[index] << endl;
						players[index].updatePlayerHandTotal();
						if (players[index].isBusted(players[index].getPlayerHandTotal())) //check if busted
						{
							cout << "*************" << endl;
							cout << "*  Bust!  *" << endl;
							cout << "*************" << endl;
							choice = 2;
							break;
						}
						cout << "===================================" << endl;
						break;
					case 2:
						cout << "***********************************" << endl;
						cout << "  Player: " << index + 1 << " | Current Hand: " << players[index] << endl;
						cout << "***********************************" << endl;
						break;
					}
				}
			} while (choice != 2);
		}
	}

	void showDealerFaceupCard() {
		cout << "\nDEALER Hand: |#| " << dealer.displayOneCard() << endl;	
	}

	void computerPlayerTurn() 
	{
		bool again = false;
		while (!again)
		{
			computerPlayer.updatePlayerHandTotal();
			if (computerPlayer.HitOrStand(computerPlayer.getPlayerHandTotal(), dealer.displayOneCard()))
			{
				computerPlayer.addOneCardToHand(deck.drawCard());
				again = false;
			}
			else
			{
				cout << "\nComputer Player Hand: " << computerPlayer << endl;
				again = true;
			}
		}
		cout << "Computer Hand Value : " << computerPlayer.getPlayerHandTotal() << endl;
		cout << "------------------------------------------" << endl;
	}

	void dealerTurn() {
		do
		{
			cout << "DEALER Hand: " << dealer << endl;
			dealer.updatePlayerHandTotal();
			dealer.addOneCardToHand(deck.drawCard());
		} while (!(dealer.getPlayerHandTotal() >= 17));	//draw another card until 17 or more

		cout << "Dealer Hand Total : " << dealer.getPlayerHandTotal() << endl;
		cout << "------------------------------------------" << endl;
	}
	
	void computerPlayerSummary() {
		if (computerPlayer.isBlackjack())
		{
			computerPlayer.getWinningAmount();
		}
		else
		{
			computerPlayer.updatePlayerHandTotal();
			//check if computer player is busted first
			if (computerPlayer.isBusted(computerPlayer.getPlayerHandTotal())){}
			//If computer player and deale have the same pts, there's no winner
			else if (computerPlayer.isEqualHand(computerPlayer.getPlayerHandTotal(), dealer.getPlayerHandTotal()))
			{
				computerPlayer.drawRound();
			}
			//Players wins, if not busted and have more points than the dealer
			else if (computerPlayer.playerWins(computerPlayer.getPlayerHandTotal(), dealer.getPlayerHandTotal()))
			{
				computerPlayer.getWinningAmount();
			}
		}
		cout << "Computer Player Balance: " << computerPlayer.getBalance() << endl;
		cout << "------------------------------------------" << endl;
	}

	void gameSummary() {
		
		for (int index = 0; index < players.size(); index++)
		{
			if (players[index].isRemoved())
				continue;
			cout << "Player: " << index + 1 << " | Balance: " << players[index].getBalance() << endl;
			if (players[index].isBlackjack())
			{
				players[index].getWinningAmount();
				cout << "Current Hand: " << players[index] << endl;
				cout << "Blackjack!!! " << endl;
			}
			else
			{
				cout << "Current Hand: " << players[index] << endl;
				players[index].updatePlayerHandTotal();
				//check if player has busted first
				if (players[index].isBusted(players[index].getPlayerHandTotal()))
				{
					cout << "Player Bets: " << players[index].getPlayerBets() << endl;
			
				}

				//check if player and dealer have same amount of points, if so, there's no winner
				else if (players[index].isEqualHand(players[index].getPlayerHandTotal(), dealer.getPlayerHandTotal()))
				{
					cout << "Player Bets: " << players[index].getPlayerBets() << endl;
					cout << "*** No Winner ***" << endl;
					players[index].drawRound();
				}

				//Players wins, if not busted and have more points than the dealer
				else if (players[index].playerWins(players[index].getPlayerHandTotal(), dealer.getPlayerHandTotal()))
				{
					cout << "Player Bets: " << players[index].getPlayerBets() << endl;
					players[index].getWinningAmount();
				}
				else
				{
					cout << "Player Bets: " << players[index].getPlayerBets() << endl;
				}
			}
			cout << "Player Hand Total: " << players[index].getPlayerHandTotal() << endl;
			cout << "Current Balance: " << players[index].getBalance() << endl;
			cout << "------------------------------------------" << endl;
		}
		computerPlayerSummary();
	
	}

};
