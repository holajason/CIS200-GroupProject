#include "Table.h"
using namespace std;

int main()
{
	int numPlayers;
	cout << "Number Of Players: ";
	cin >> numPlayers;
	Table table(numPlayers);

	char userSelect = ' ';

	while (toupper(userSelect) != 'N')
	{
		
		int playerBet;
		for (int index = 0; index < table.getNumberOfPlayers(); ++index)
		{
			cout << "Player " << index + 1 << " bet? ";
			cin >> playerBet;
			table.setPlayerBet(index, playerBet);
		}
		
		table.initRound();
		cout << table.showDealerInitialHand();
		cout << table << endl;

		int hitOrStand;
		for (int index = 0; index < table.getNumberOfPlayers(); ++index)
		{
			cout << "Player	" << index + 1 << ": " << table.showPlayerCards(index) << endl;
			
			while (table.playerCanHit(index))
			{
				cout << "Hit(1) or stand?(0)" << endl;
				cin >> hitOrStand;
				if (hitOrStand) 
				{
					table.playerHit(index);
					cout << table.showPlayerCards(index) << endl;
				}
				else
					table.playerStand(index);
			}

			cout << endl << endl;
		}
		
		table.dealerTurn();
		cout << table << endl;

		table.reset();
		cout << "Play again?(y/n)" << endl;
		cin >> userSelect;
	}
	system("pause");
	return 0;
}