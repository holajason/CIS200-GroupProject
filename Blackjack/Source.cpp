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
    //https://stackoverflow.com/questions/17618264/srand-time-null-causes-compiler-warning-implicit-conversion-loses-integer-p
	srand(static_cast<unsigned int>(time(NULL)));
	int numberOfPlayers;
	int bets;
	Deck deck;
	vector<Players> players;
	bool valid = false;
	int choice;
    int currentPots = 0;
	cout << "Number of Players: ";
	cin >> numberOfPlayers;


	for (int numPlayers = 0; numPlayers < numberOfPlayers; numPlayers++) {
		players.emplace_back(numPlayers);
	}

//    for (int round = 0; round < 5; round++) {
//        for (int i = 0; i < players.size(); i++) {
//            cout << "Player " << i + 1 << " betting: ";
//            cin >> bets;
//            currentPots += bets;
//        }
//    }
	do {
      
			for (int i = 0; i < players.size(); i++) {
                cout << "Current Pot: " << currentPots<< endl;
				cout << "Player: " << i + 1 << " | Hit(1) OR Stand(2): ";
				cin >> choice;

				switch (choice) {
				case 1:
                    cout << "-----------------------"<<endl;
                    cout << "|Player: " << i+ 1 << "|" << "$: " << players[i].placingBet(bets) <<endl;
					players[i].distributeCards();
					cout << "|Current hand: ";
					players[i].print();
                    cout << players[i].getTotal();
                    cout << "\n-----------------------"<<endl;
					cout << endl;
					break;
				case 2:
                    cout << "\n-----------------------"<<endl;
                    cout << "|Player: " << i+ 1 << "|" << "$: " << players[i].getRemainingMoney() <<endl;
					players[i].print();
                    cout << "\n-----------------------"<<endl;
					cout << endl;
					break;
                }
            valid = true;
    
            }
    
	} while (!valid);




	system("pause");
	return 0;
}
