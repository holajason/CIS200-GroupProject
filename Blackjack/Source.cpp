#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

int main() {
	srand(unsigned(time(0)));
	int numberOfPlayers;
	int playerBets, choice;
	int menuOption = 0;
	string card;
	Deck deck;
	Dealer cardDealer;
	vector<Players> players;
	Players dealer(1);
	
	deck.createDeck();
	
		cout << "Number of Players: ";
		cin >> numberOfPlayers;
		for (int numPlayers = 0; numPlayers < numberOfPlayers; numPlayers++) {
			players.emplace_back(numPlayers);
		}
		do {
			for (int index = 0; index < players.size(); index++) {
				if (players[index].getBalance() <= 0) {
					players.erase(players.begin() + index);
				}
				else {
					players[index].playAgain();
					dealer.playAgain();
					cout << "Player " << index + 1 << " Please Place Your Bet: ";
					cin >> playerBets;
					players[index].getBettingAMount(playerBets);
					players[index].getRemainingBalance();
				}
			}
			for (int cards = 0; cards < 2; cards++) {
				for (int index = 0; index < players.size(); index++) {
					card = deck.drawCards();
					players[index].distributePlayerCards(card);
				}
				if (deck.getNumberOfCards() <= 30) {
					deck.reShuffle();
				}
			}

			for (int i = 0; i < 2; i++) {
				card = deck.drawCards();
				dealer.distributePlayerCards(card);
			}

			cout << "=======================" << endl;
			cout << "DEALER Hand: |#| " << dealer.showOneCard();
			for (int index = 0; index < players.size(); index++) {
				cout << "\n-------------------------------" << endl;
				cout << "Player: " << index + 1 << " | " << "Current Balance: " << players[index].getBalance() << endl;
				cout << "Current hand: ";
				players[index].print();
				cout << endl;
				do {
					if (players[index].isBlackjack()) {
						cout << "Blackjack!";
						choice = 2;
						break;
					}
					else {
						cout << "Player: " << index + 1 << " | Hit(1) OR Stand(2): ";
						cin >> choice;
						switch (choice) {
						case 1:
							card = deck.drawCards();
							cout << "------------------------------------" << endl;
							cout << "Player: " << index + 1 << endl;
							//players[index].distributeCards();
							players[index].distributePlayerCards(card);
							cout << "Current hand: ";
							players[index].print();
							if (players[index].isBusted(players[index].getSoftHandTotal())) {
								cout << "\nBusted!";
								choice = 2;
								break;
							}
							cout << "\n-----------------------------------" << endl;
							break;
						case 2:
							cout << "-------------------------------" << endl;
							cout << "Player: " << index + 1 << " | Current Hand: ";
							players[index].print();
							cout << "\n-------------------------------" << endl;
							break;
						}
					}
				} while (choice != 2);
			}

			cout << "\n=====================================================\n";
			do {
				cout << "DEALER Hand: ";
				dealer.print();
				cout << endl;
				dealer.getHandTotal();;
				card = deck.drawCards();
				dealer.distributePlayerCards(card);
			} while (!(dealer.getPlayerHandTotal() >= 17));

			cout << "\nDEALER Total Points: " << dealer.getPlayerHandTotal();
			cout << "\n------------------------------------------" << endl;
			for (int index = 0; index < players.size(); index++) {
				cout << "Player: " << index + 1 << " | Balance: " << players[index].getBalance() << endl;
				if (players[index].isBlackjack()) {
					players[index].getWinningAmount();
					players[index].print();
					cout << "\nBlackjack!!! Winning Amount: " << players[index].getPlayerBets() << endl;
				}
				else {
					cout << "Current Hand: ";
					players[index].print();
					cout << endl;
					players[index].getHandTotal();
					cout << "\nPlayer Hand Total: " << players[index].getPlayerHandTotal() << endl;
					if (players[index].getBusting(players[index].getPlayerHandTotal(), dealer.getPlayerHandTotal())) {
						cout << "Total Winning : " << players[index].getPlayerBets() << endl;
						players[index].getWinningAmount();
					}
				}
				cout << "Current Balance: " << players[index].getBalance() << endl;
				cout << "================================" << endl;
			}
			cout << "\n=====================================================\n";
			if (deck.getNumberOfCards() <= 30) {
				deck.reShuffle();
			}
			cout << "1. Play Again" << endl;
			cout << "2. Quit" << endl;
			cin >> menuOption;
			//players.clear();
		} while (menuOption != 2 && numberOfPlayers > 0);

	system("pause");
	return 0;
}
