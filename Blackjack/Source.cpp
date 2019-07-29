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
	Dealer cardDealer;
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
						players[index].playAgain();
						players.erase(players.begin() + index);
					}
					players[index].playAgain();
					dealer.playAgain();
					cout << "Player " << index + 1 << " Please Place Your Bet: ";
					cin >> playerBets;
					players[index].getPlayersBets(playerBets);
					players[index].getRemainingBalance();
				}
				for (int cards = 0; cards < 2; cards++) {
					for (int index = 0; index < players.size(); index++) {
						card = deck.drawCards();
						players[index].distributePlayerCards(card);
					}
					if (deck.getNumberOfCards() < 30) {
						deck.reshuffle();
					}
				}

				for (int i = 0; i < 2; i++) {
					card = deck.drawCards();
					dealer.distributePlayerCards(card);
				}

				cout << "===================================" << endl;
				cout << "DEALER Hand: |#| " << dealer.displayOneCard();
				for (int index = 0; index < players.size(); index++) {
					cout << "\n-----------------------------------" << endl;
					cout << "Player: " << index + 1 << " | " << "Current Balance: " << players[index].getBalance() << endl;
					cout << "Current hand: " << players[index] << endl;
					cout << "===================================" << endl;
					do {
						if (players[index].isBlackjack()) {
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
								//players[index].distributeCards();
								players[index].distributePlayerCards(card);
								cout << "Current hand: " << players[index] << endl;
								if (players[index].isBusted(players[index].getSoftHandTotalValue())) {
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
					cout << "DEALER Hand: ";
					//dealer.print();
					cout << dealer << endl;
					dealer.getHandTotalValue();;
					card = deck.drawCards();
					dealer.distributePlayerCards(card);
				} while (!(dealer.getCurrentHandTotal() >= 17));
				cout << "DEALER Total Points: " << dealer.getCurrentHandTotal();
				for (int index = 0; index < players.size(); index++) {
					cout << "\n------------------------------------------" << endl;
					cout << "Player: " << index + 1 << " | Balance: " << players[index].getBalance() << endl;
					if (players[index].isBlackjack()) {
						players[index].getWinningAmount();
						cout << "Current Hand: " << players[index] << endl;
						cout << "Blackjack!!! Winning Amount: " << players[index].getPlayerBets() << endl;
					}
					else {
						cout << "Current Hand: " << players[index] << endl;
						players[index].getHandTotalValue();
						cout << "Player Hand Total: " << players[index].getCurrentHandTotal() << endl;
						if (players[index].isBusted(players[index].getCurrentHandTotal())) {
							cout << "Player Bets: " << players[index].getPlayerBets() <<
								" | Total Loses: " << players[index].getPlayerBets() << endl;
						}
						else if (players[index].equallyHandTotal(players[index].getCurrentHandTotal(), dealer.getCurrentHandTotal())) {
							cout << "Player Bets: " << players[index].getPlayerBets() << endl;
							cout << "*** No Winner ***" << endl;
							players[index].getMoneyBack();
						}
						else if (players[index].getBusted(players[index].getCurrentHandTotal(), dealer.getCurrentHandTotal())) {
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
