#pragma once
#include "Player.h"
#include "NPCPlayer.h"
class Table : Player
{
private:
	int numberOfPlayers;
	vector<Player> players;
	Player dealer;
	Deck deck;
	string card;
	Player npcPlayer;
	computerPlayer computerPlayer;
	int playerBets;
	int choice;
	void deckStatus()
	{
		if (deck.getNumberOfCards() <= 30)
		{
			deck.reshuffle();
		}
	}

public:
	Table(int numberOfPlayers)
	{
		this->numberOfPlayers = getNumberOfPlayers( numberOfPlayers);
		this->players.resize(numberOfPlayers);
		deck.createDeck();
	}

	void initRound()
	{
		for (int numberOfCards = 0; numberOfCards < 2; ++numberOfCards)
		{
			for (int index = 0; index < players.size(); ++index)
			{
				card = deck.drawCards();
				players[index].distributeCards(card);
			}
			card = deck.drawCards();
			dealer.distributeCards(card);
			card = deck.drawCards();
			npcPlayer.distributeCards(card);
		}
		deckStatus();
	}

	int getNumberOfPlayers(int numPlayers)
	{
		if (numPlayers <= 0 || numPlayers > 10)
		{
			throw invalid_argument("Invalid Number Of Players(1-10)");
		}
		return numPlayers;
	}

	void removeInsufficientFundPlayer() {
		for (int index = 0; index < players.size(); index++)
		{
			if (players[index].getBalance() <= 0) {
				players.erase(players.begin() + index); //Remove player
			}
			if (players.size() <= 0)
			{
				throw invalid_argument( "Not Enought Players. \n");
			}
		}
	}

	void restartGame() {
		for (int index = 0; index < players.size(); index++) {
			players[index].playAgain(); // reset player hand
			dealer.playAgain();			//reset dealer hand
			npcPlayer.playAgain();
			cout << "Player " << index + 1 << " Please Place Your Bet: ";
			cin >> playerBets;
			players[index].setPlayersBets(playerBets);	//get player bets
			players[index].getRemainingBalance();
		}
		npcPlayer.setPlayersBets(1);		//Computer player bet
		npcPlayer.getRemainingBalance();
	}


	void startGame() {
		for (int index = 0; index < players.size(); index++)
		{
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
						card = deck.drawCards();
						cout << "===================================" << endl;
						cout << "Player: " << index + 1 << " | ";
						players[index].distributeCards(card);
						cout << "Current hand: " << players[index] << endl;
						if (players[index].isBusted(players[index].playerCurrentHandValue())) //check if busted
						{
							cout << "*************" << endl;
							cout << "*  Busted!  *" << endl;
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

	void getDealerFaceUpcard() {
		cout << "DEALER Hand: |#| " << dealer.displayOneCard() << endl;	//One card face down, one card face up
	}

	void computerPlayerTurn() {
		string outstring;
		bool again = false;
		
		while (!again)
		{
			npcPlayer.playerCurrentHandValue();
			if (computerPlayer.HitOrStand(npcPlayer.getPlayerHandTotal(), dealer.displayOneCard()))
			{
				card = deck.drawCards();
				npcPlayer.distributeCards(card);
				again = false;
			}
			else
			{
				cout << "Computer Player Hand: " << npcPlayer << endl;
				again = true;
			}
		}
		cout << "Computer Hand Value : " << npcPlayer.getPlayerHandTotal() << endl;
		cout << "------------------------------------------" << endl;
	}

	void dealerTurn() {
		do
		{
			cout << "DEALER Hand: " << dealer << endl;
			dealer.playerCurrentHandValue();
			card = deck.drawCards();
			dealer.distributeCards(card);
		} while (!(dealer.getPlayerHandTotal() >= 17));	//draw another card until 17 or more
		cout << "Dealer Hand Total : " << dealer.getPlayerHandTotal() << endl;
		cout << "------------------------------------------" << endl;
	}

	void gameSummary() {
		cout <<  Player::gameSummary();
		for (int index = 0; index < players.size(); index++)
		{
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
				players[index].playerCurrentHandValue();

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
	
		deckStatus();
	}

	void computerPlayerSummary() {
		if (npcPlayer.isBlackjack())
		{
			npcPlayer.getWinningAmount();
		}
		else
		{
			npcPlayer.playerCurrentHandValue();
			//check if computer player is busted first
			if (npcPlayer.isBusted(npcPlayer.getPlayerHandTotal()))
			{
				cout << "Computer Player Bets: " << npcPlayer.getPlayerBets() << endl;
			}
			//If computer player and deale have the same pts, there's no winner
			else if (npcPlayer.isEqualHand(npcPlayer.getPlayerHandTotal(), dealer.getPlayerHandTotal()))
			{
				npcPlayer.drawRound();
			}
			//Players wins, if not busted and have more points than the dealer
			else if (npcPlayer.playerWins(npcPlayer.getPlayerHandTotal(), dealer.getPlayerHandTotal()))
			{
				npcPlayer.getWinningAmount();
			}
			else
			{
				cout << "NPC Player Bets: " << npcPlayer.getPlayerBets() << endl;
			}
		}
		cout << "Computer Player Balance: " << npcPlayer.getBalance() << endl;
		cout << "------------------------------------------" << endl;
	}

};