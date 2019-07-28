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
        players[size].getRemainingBalance();
	}
       
	for (int cards = 0; cards < 2; cards++) {
		for (int index = 0; index < players.size(); index++) {
			players[index].distributeCards();
		}
	}

	for (int i = 0; i < players.size(); i++) {
		cout << "\n-------------------------------" << endl;
		cout << "Player: " << i + 1 << " | " << "Current Balance: " << players[i].getBalance() << endl;
		cout << "Current hand: ";
		players[i].print();
		//cout << "\nTotal: " << players[i].getHandTotal();
		cout << "\n-------------------------------" << endl;

		do {
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
                    players[i].getHandTotal();
                 cout << "-------------------------------" << endl;
                    cout << "Player: " << i + 1 <<  " | Current Hand: ";
                    players[i].print();
                    cout << "\nTotal Points: " << players[i].getPlayerHandTotal()<<endl;
                        cout << "-------------------------------" << endl;
//                if (players[i].getHandTotal() > 15) {
//                    players[i].getWinningMoney();
//                }
//                cout << "\n=====================================================\n";
//                cout << "Player: " << i + 1 << " | Current Balance: " << players[i].getBalance() << endl;
//                cout << "Current Hand: ";
//                players[i].print();
//                cout << "\nTotal Points: " << players[i].getPlayerHandTotal();
//                cout << "\n=====================================================\n";
//                cout << endl;
				break;
			}
		} while (choice != 2);
    }
    
    cout << "\n=====================================================\n";
    Players dealer(1);
    cout << "Dealer Hand: ";
    do{
        dealer.distributeCards();
        dealer.getHandTotal();
    }
    while(!(dealer.getPlayerHandTotal() >= 17));
    dealer.print();
    cout << "\nDealer Total Points: " << dealer.getPlayerHandTotal() ;
    cout << "\n--------------------------------------------------" << endl;
    for(int index = 0; index < players.size(); index++){
        cout << "Player: " << index + 1 << " | Current Balance: " << players[index].getBalance() << endl;
        cout << "Current Hand: ";
        players[index].print();
        cout << " | Player Hand Total: " << players[index].getPlayerHandTotal()<< endl;
        if(players[index].getPlayerHandTotal()  <= 21 && players[index].getPlayerHandTotal() >= dealer.getPlayerHandTotal() || dealer.getHandTotal() > 21){
            players[index].getWinningMoney();
        }
        cout << "Current Balance: " << players[index].getBalance() << endl;
          cout << "=============================" <<endl;
    }

 cout << "\n=====================================================\n";
	system("pause");
	return 0;
}
