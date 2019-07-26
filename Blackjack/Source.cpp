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
	srand(time(NULL));
	int numberOfPlayers;
	int bets;
	Deck deck;
	vector<Players> players;
	bool valid = false;
	int choice;

	cout << "Number of Players: ";
	cin >> numberOfPlayers;


	for (int numPlayers = 0; numPlayers < numberOfPlayers; numPlayers++) {
		players.emplace_back(numPlayers);
	}

	//for (int i = 0; i < players.size(); i++) {
	//	//menu();
	//	cout << "Player " << i + 1 << " betting: ";
	//	cin >> bets;
	//	//players[i].distributeCards();
	//}

	do {
		for (int i = 0; i < players.size(); i++) {
			cout << "Player: " << i + 1 << endl;
			cout << "Hit(1) OR Stand(2): ";
			cin >> choice;

			switch (choice) {
			case 1:
				players[i].distributeCards();
				break;
			case 2:
				break;
			}
			valid = true;
		}
	} while (!valid);




	system("pause");
	return 0;
}