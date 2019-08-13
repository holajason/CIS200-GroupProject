#include "Table.h"
#include "Deck.h"
int main() {
	srand(unsigned(time(0)));
	int numPlayers;
	int menuOption;
	try {
		cout << "Players Per Table: ";
		cin >> numPlayers;
		Table table(numPlayers);
		do {
			table.removeInsufficientFundPlayer();
			table.getPlayersBet();
			table.initRound();
			table.showDealerFaceupCard();
			table.playerTurn();
			table.computerPlayerTurn();
			table.dealerTurn();
			table.gameSummary();
			cout << "1. Play Again" << endl;
			cout << "2. Quit" << endl;
			cin >> menuOption;
		} while (menuOption == 1);
	}
	catch (exception& e) {
		cout << e.what();
	}
	system("pause");
	return 0;
}