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
	int bets, choice;
    int currentPots = 0;
    bool valid = false;
	Deck deck;
	vector<Players> players;
	cout << "Number of Players: ";
	cin >> numberOfPlayers;


	for (int numPlayers = 0; numPlayers < numberOfPlayers; numPlayers++) {
		players.emplace_back(numPlayers);
	}
    
    

        for (int i = 0; i < players.size(); i++) {
            cout << "Player " << i + 1 << " Please Place Your Bet: ";
            cin >> bets;
            players[i].placingBet(bets);
            currentPots += bets;
        }
       
        for(int k = 0; k < 2; k++){
            for (int i = 0; i < players.size(); i++) {
                players[i].distributeCards();
//                cout << "-----------------------"<<endl;
//                cout << "   Player: " << i+ 1 << " | " << "$: " << players[i].getRemainingMoney() <<endl;
//                cout << "Current hand: ";
//                players[i].print();
//                cout << "\n-----------------------"<<endl;
            }
        }

        for (int i = 0; i < players.size(); i++) {
            cout << "=========================" <<endl;
            cout << "   Current Pot: " << currentPots << endl;
            cout << "=========================" <<endl;
            cout << "-----------------------"<<endl;
            cout << "   Player: " << i+ 1 << " | " << "$: " << players[i].getRemainingMoney() <<endl;
            cout << "Current hand: ";
            players[i].print();
            cout << "\n-----------------------"<<endl;

            do{
            cout << "Player: " << i + 1 << " | Hit(1) OR Stand(2): ";
            cin >> choice;
            switch (choice) {        
            case 1:
                cout << "-----------------------"<<endl;
                cout << "   Player: " << i+ 1 << "|" << "$: " << players[i].getRemainingMoney() <<endl;
                players[i].distributeCards();
                cout << "Current hand: ";
                players[i].print();
				cout << "\nTotal: " << players[i].getTotal();
                cout << "\n-----------------------"<<endl;
                cout << endl;
                break;
            case 2:
                cout << "\n-----------------------"<<endl;
                cout << "   Player: " << i+ 1 << "|" << "$: " << players[i].getRemainingMoney() <<endl;
                players[i].print();
                cout << "\n-----------------------"<<endl;
                cout << endl;
                break;
            }
            }while(choice!=2);
            

        }
 

    cout << endl;
	system("pause");
	return 0;
}
