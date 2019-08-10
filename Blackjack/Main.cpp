#include "Table.h"
#include "Player.h"
#include "Deck.h"
using namespace std;

int main()
{
    Player player;
    Deck deck;
	int numPlayers;
    cout << "How many players at the table?";
    cin >> numPlayers;
    Table table(numPlayers);

	
//    for (int index = 0; index < table.getNumberOfPlayers(); ++index)
//    {
//        cout << "Player " << index + 1 << " betting amount?";
//        cin >> playerBet;
//        table.setPlayerBets(playerBet);
//    }

        table.initRound();
		cout  << table<< endl;
    
        
//        while (table.playerAbleToHit(index))
//        {
//            cout << "Hit(1) or stand?(0)" << endl;
//            cin >> playerDecision;
//            table.playerTurn(index, playerDecision);
//        }
//
//        cout << endl << endl;
	


	system("pause");
	return 0;
}
