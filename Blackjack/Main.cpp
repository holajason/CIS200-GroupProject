#include "Table.h"
using namespace std;

int main()
{
	int numPlayers;
	cout << "How many players at the table?";
	cin >> numPlayers;
	Table table(numPlayers);

	int playerBet;
	for (int index = 0; index < table.getNumberOfPlayers(); ++index)
	{
		cout << "Player " << index + 1 << " betting amount?";
		cin >> playerBet;
		table.setPlayerBets(playerBet);
	}

	table.initRound();

	int playerDecision = 0;
	for (int index = 0; index < table.getNumberOfPlayers(); ++index)
	{
		cout << "Player	" << index + 1 << ":" << endl;
		for (int cards = 0; cards < table.getPlayerHand(index).size(); ++cards)
		{
			cout << table.getPlayerHand(index).at(cards) << " ";
		}

		while (table.playerAbleToHit(index))
		{
			cout << "Hit(1) or stand?(0)" << endl;
			cin >> playerDecision;
			table.playerTurn(index, playerDecision);
		}

		cout << endl << endl;
	}


	system("pause");
	return 0;
}