#include "Deck.h"
#include "Player.h"

void menu() {
	bool valid = false;
	int choice;
	while (!valid) {
		cout << "1: Hit OR 2. Stand: ";
		cin >> choice;
		valid = true;
	}
    
}
int main() {
	srand(unsigned(time(0)));
	int numberOfPlayers;
	int playerBets, choice;
    bool valid = false;
	Deck deck;
	vector<Players> players;

	cout << "Number of Players: ";
	cin >> numberOfPlayers;
	for (int numPlayers = 0; numPlayers < numberOfPlayers; numPlayers++) {
		players.emplace_back(numPlayers);
	}
    

	for (int size = 0; size < players.size(); size++) {
		cout << "Player " << size + 1 << " Please Place Your Bet: ";
		cin >> playerBets;
		players[size].getBettingAMount(playerBets);
	}
       
	for (int cards = 0; cards < 2; cards++) {
		for (int index = 0; index < players.size(); index++) {
			players[index].distributeCards();
		}
	}

	for (int i = 0; i < players.size(); i++) {
		cout << "--------------------------" << endl;
		cout << "   Player: " << i + 1 << " | " << "$: " << players[i].getBalance() << endl;
		cout << "Current hand: ";
		players[i].print();
		cout << "\nTotal: " << players[i].getTotal();
		cout << "\n--------------------------" << endl;

		do {
			cout << "Player: " << i + 1 << " | Hit(1) OR Stand(2): ";
			cin >> choice;
			switch (choice) {
			case 1:
				cout << "--------------------------" << endl;
				cout << "Player: " << i + 1 << endl;
				players[i].distributeCards();
				cout << "Current hand: ";
				players[i].print();
			//	cout << "\nTotal: " << players[i].getTotal();
				cout << "\n--------------------------" << endl;
				break;
			case 2:
				players[i].getTotal();
				if (players[i].getTotal() > 15) {
					players[i].getWinningMoney();
				}
				cout << "\n=====================================================\n";
				cout << "Player: " << i + 1 << endl;
				players[i].print();
				cout << "\nBalance: " <<players[i].getBalance();
				cout << "\   |   Total Winning $: " << players[i].getBet();
				cout << "\n=====================================================\n";
				cout << endl;
				break;
			}
		} while (choice != 2);


	}
 

    cout << endl;
	system("pause");
	return 0;
}
