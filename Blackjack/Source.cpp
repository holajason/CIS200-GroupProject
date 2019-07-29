#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

int main() {
	srand(unsigned(time(0)));
	int numberOfPlayers;
	int playerBets, choice;
	int menuOption = 0;
	bool valid = false;
	string card;
	Deck deck;
	vector<Players> players;
	Players dealer(1);

	deck.createDeck();
	while (!valid) {
		try {
			cout << "Number of Players: ";
			cin >> numberOfPlayers;
			dealer.getNumberOfPlayers(numberOfPlayers);
			for (int numPlayers = 0; numPlayers < numberOfPlayers; numPlayers++) {
				players.emplace_back(numPlayers);
			}
			do {
				for (int index = 0; index < players.size(); index++) {
					if (players[index].getBalance() <= 0) {
						players[index].playAgain(); //Reset player current hand
						players.erase(players.begin() + index); //Remove player
					}
					players[index].playAgain(); // reset player hand
					dealer.playAgain();			//reset dealer hand
					cout << "Player " << index + 1 << " Please Place Your Bet: ";
					cin >> playerBets;
					players[index].setPlayersBets(playerBets);	//get player bets
					players[index].getRemainingBalance();
				}
				for (int cards = 0; cards < 2; cards++) {	//Draw 2 cards for each player
					for (int index = 0; index < players.size(); index++) {
						card = deck.drawCards();	
						players[index].distributePlayerCards(card);
					}
					if (deck.getNumberOfCards() < 30) {	//reshuffle if less than 30 cards
						deck.reshuffle();
					}
				}

				for (int i = 0; i < 2; i++) {	//Dealer draw 2 cards
					card = deck.drawCards();
					dealer.distributePlayerCards(card);
				}

				cout << "===================================" << endl;
				cout << "DEALER Hand: |#| " << dealer.displayOneCard();	//One card face down, one card face up
				for (int index = 0; index < players.size(); index++) {
					cout << "\n-----------------------------------" << endl;
					cout << "Player: " << index + 1 << " | " << "Current Balance: " << players[index].getBalance() << endl;
					cout << "Current hand: " << players[index] << endl;	//display current hand
					cout << "===================================" << endl;
					do {
						if (players[index].isBlackjack()) {	//if player first two card is blackjack, automatically wins
							cout << "  ****************" << endl;
							cout << "  *  Blackjack!  *" << endl;
							cout << "  ****************" << endl;
							choice = 2;
							break;
						}
						else {
							cout << "Player: " << index + 1 << " | Hit(1) OR Stand(2): ";
							cin >> choice;
							switch (choice) {
							case 1:
								card = deck.drawCards();
								cout << "===================================" << endl;
								cout << "Player: " << index + 1 << endl;
								players[index].distributePlayerCards(card);
								cout << "Current hand: " << players[index] << endl;
								if (players[index].isBusted(players[index].getSoftHandTotalValue())) {	//check if busted
									cout << "  *************" << endl;
									cout << "  *  Busted!  *" << endl;
									cout << "  *************" << endl;
									choice = 2;
									break;
								}
								cout << "\n-----------------------------------" << endl;
								break;
							case 2:
								cout << "===================================" << endl;
								cout << "\n***********************************" << endl;
								cout << "  Player: " << index + 1 << " | Current Hand: " << players[index] << endl;
								cout << "***********************************" << endl;
								break;
							}
						}
					} while (choice != 2);
				}
				cout << "\n=====================================================\n";
				do {
					cout << "DEALER Hand: " << dealer << endl;
					dealer.getHandTotalValue();;
					card = deck.drawCards();
					dealer.distributePlayerCards(card);
				} while (!(dealer.getCurrentHandTotal() >= 17));	//draw another card until 17 or more
				cout << "DEALER Total Points: " << dealer.getCurrentHandTotal();
				for (int index = 0; index < players.size(); index++) {
					cout << "\n------------------------------------------" << endl;
					cout << "Player: " << index + 1 << " | Balance: " << players[index].getBalance() << endl;
					if (players[index].isBlackjack()) {	//blackjack
						players[index].getWinningAmount();
						cout << "Current Hand: " << players[index] << endl;
						cout << "Blackjack!!! Winning Amount: " << players[index].getPlayerBets() << endl;
					}
					else {
						cout << "Current Hand: " << players[index] << endl;
						players[index].getHandTotalValue();
						cout << "Player Hand Total: " << players[index].getCurrentHandTotal() << endl;
						//check if player is busted first
						if (players[index].isBusted(players[index].getCurrentHandTotal())) {	
							cout << "Player Bets: " << players[index].getPlayerBets() <<
								" | Total Loses: " << players[index].getPlayerBets() << endl;
						}
						//check if player and dealer have same amount of points, if its, there's no winner
						else if (players[index].equallyHandTotal(players[index].getCurrentHandTotal(), dealer.getCurrentHandTotal())) {
							cout << "Player Bets: " << players[index].getPlayerBets() << endl;
							cout << "*** No Winner ***" << endl;
							players[index].getDrawRoundMoney();
						}
						//Players wins, if not busted and have more points than the dealer
						else if (players[index].playerWins(players[index].getCurrentHandTotal(), dealer.getCurrentHandTotal())) {
							cout << "Player Bets: " << players[index].getPlayerBets() <<
								" | Total Winning : " << players[index].getPlayerBets() << endl;
							players[index].getWinningAmount();
						}
						else {
							cout << "Player Bets: " << players[index].getPlayerBets() << 
								" | Total Loses: " << players[index].getPlayerBets() << endl;
						}
					}
					cout << "Current Balance: " << players[index].getBalance() << endl;
				}
				cout << "\n=====================================================\n";
				//reshuffle if less than 30 cards
				if (deck.getNumberOfCards() < 30) {
					deck.reshuffle();
				}
				cout << "1. Play Again" << endl;
				cout << "2. Quit" << endl;
				cin >> menuOption;
				//players.clear();
				valid = true;
			} while (menuOption != 2);
		}
		catch (exception & e) {
			cout << e.what() << endl;
		}
	}
	system("pause");
	return 0;
}
