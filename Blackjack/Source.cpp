#include "Deck.h"
#include "Player.h"

int main() {
	srand(unsigned(time(0)));
	int numberOfPlayers;
	int playerBets, choice;
    bool valid = false;
	Deck deck;
	string card;
	vector<Players> players;
	stack<string>hiddenCard;
	Players dealer(1);

	cout << "Number of Players: ";
	cin >> numberOfPlayers;
	for (int numPlayers = 0; numPlayers < numberOfPlayers; numPlayers++) {
		players.emplace_back(numPlayers);
	}
    
	for (int size = 0; size < players.size(); size++) {
		cout << "Player " << size + 1 << " Please Place Your Bet: ";
		cin >> playerBets;
		players[size].getBettingAMount(playerBets);
        players[size].getRemainingBalance();
	}
       
	for (int cards = 0; cards < 2; cards++) {
		for (int index = 0; index < players.size(); index++) {
			players[index].distributeCards();
		}
		dealer.distributeCards();
	}

	cout << "=======================" << endl;
	cout << "DEALER Hand: |#| " << dealer.showOneCard();

	for (int i = 0; i < players.size(); i++) {
		cout << "\n-------------------------------" << endl;
		cout << "Player: " << i + 1 << " | " << "Current Balance: " << players[i].getBalance() << endl;
		cout << "Current hand: ";
		players[i].print();
		cout << endl;
		do {
			if (players[i].isBlackjack()) {
				cout << "Blackjack!";
				choice = 2;
				break;
			}
			else {
				cout << "Player: " << i + 1 << " | Hit(1) OR Stand(2): ";
				cin >> choice;
				switch (choice) {
				case 1:
					cout << "------------------------------------" << endl;
					cout << "Player: " << i + 1 << endl;
					players[i].distributeCards();
					cout << "Current hand: ";
					players[i].print();
					cout << "\n-----------------------------------" << endl;
					break;
				case 2:
					cout << "-------------------------------" << endl;
					cout << "Player: " << i + 1 << " | Current Hand: ";
					players[i].print();
					cout << "\n-------------------------------" << endl;
					break;
				}
			}
		} while (choice != 2);
    }
    
    cout << "\n=====================================================\n";
    do{
		cout << "DEALER Hand: ";
		dealer.print();
		cout << endl;
		dealer.getHandTotal();;
        dealer.distributeCards();
    }
    while(!(dealer.getPlayerHandTotal() >= 17));

    cout << "\nDEALER Total Points: " << dealer.getPlayerHandTotal() ;
    cout << "\n--------------------------------------------------" << endl;
    for(int index = 0; index < players.size(); index++){
        cout << "Player: " << index + 1 << " | Balance: " << players[index].getBalance() << endl;
		if (players[index].isBlackjack()) {
			players[index].getWinningMoney();
			players[index].print();
			cout << "\nBlackjack!!! Winning Amount: "<< players[index].getBet() << endl;
		}
		else {
			cout << "Current Hand: ";
			players[index].print();
			cout << endl;
			players[index].getHandTotal();
			cout << "\nPlayer Hand Total: " << players[index].getPlayerHandTotal() << endl;
		/*	if (players[index].getPlayerHandTotal() <= 21 && players[index].getPlayerHandTotal() >= dealer.getPlayerHandTotal() || dealer.getHandTotal() > 21) {
				players[index].getWinningMoney();
			}*/
			if (players[index].getBusting(players[index].getPlayerHandTotal(), dealer.getPlayerHandTotal())) {
				cout << "Winning Amount : " << players[index].getBet() << endl;
				players[index].getWinningMoney();
			}
		}
        cout << "Current Balance: " << players[index].getBalance() << endl;
         cout << "===================================" <<endl;
    }

	cout << "\n=====================================================\n";
	system("pause");
	return 0;
}
