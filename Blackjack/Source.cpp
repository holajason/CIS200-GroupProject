#include "Deck.h"
#include "Player.h"


/*
int main() {
	srand(unsigned(time(0)));
	int numberOfPlayers;
	int playerBets, choice;
	int menuOption = 0;
	bool valid = false;
	string card;
	Deck deck;
	NPCPlayer computerPlayer;
	vector<Player> players;
	//Player dealer(1);
	//Player npcPlayer(1);
	Player dealer;
	Player npcPlayer;

	deck.createDeck();
	while (!valid) {
		try
		{
			cout << "Number of Players: ";
			cin >> numberOfPlayers;
			//dealer.getNumberOfPlayers(numberOfPlayers);

			for (int numPlayers = 0; numPlayers < numberOfPlayers; numPlayers++) 
			{
				players.emplace_back(numPlayers);
			}
			do 
			{
				//If play again, remove any player with insufficient fund
				for (int index = 0; index < players.size(); index++) 
				{
					if (players[index].getBalance() <= 0) {
						players.erase(players.begin() + index); //Remove player
					}
					if (players.size() <= 0) 
					{
						cout << "Not Enought Players. " << endl;
						return 0;
					}
				}
				//After resizing the collection of players, reset and start again
				for (int index = 0; index < players.size(); index++) {
					players[index].playAgain(); // reset player hand
					dealer.playAgain();			//reset dealer hand
					npcPlayer.playAgain();
					cout << "Player " << index + 1 << " Please Place Your Bet: ";
					cin >> playerBets;
					players[index].setPlayersBets(playerBets);	//get player bets
					players[index].getRemainingBalance();
					npcPlayer.setPlayersBets(1);		//Computer player bet
					npcPlayer.getRemainingBalance();
				}
			
				for (int cards = 0; cards < 2; cards++)  //Draw 2 cards for each player
				{	
					for (int index = 0; index < players.size(); index++)
					{
						card = deck.drawCards();
						players[index].distributeCards(card);
					}
					//dealer 
                    card = deck.drawCards();
                    dealer.distributeCards(card);
					//Computer player
                    card = deck.drawCards();
                    npcPlayer.distributeCards(card);    
					if (deck.getNumberOfCards() < 30)   //reshuffle if less than 30 cards
					{	
						deck.reshuffle();
					}
				}

			

				cout << "===================================" << endl;
				cout << "DEALER Hand: |#| " << dealer.displayOneCard();	//One card face down, one card face up

				for (int index = 0; index < players.size(); index++)
				{
					cout << "\n-----------------------------------" << endl;
					cout << "Player: " << index + 1 << " | " << "Current Balance: " << players[index].getBalance() << endl;
					cout << "Current hand: " << players[index] << endl;	//display current hand
					cout << "===================================" << endl;

					do 
					{
						if (players[index].isBlackjack()) 	//if player first two card is blackjack, automatically wins
						{
							cout << "  *  Blackjack!  *" << endl;
							choice = 2;
							break;
						}
						else
						{
							cout << "Player: " << index + 1 << " | Hit(1) OR Stand(2): ";
							cin >> choice;
							switch (choice) {
							case 1:
								card = deck.drawCards();
								cout << "===================================" << endl;
								cout << "Player: " << index + 1 << endl;
								players[index].distributeCards(card);
								cout << "Current hand: " << players[index] << endl;
								if (players[index].isBusted(players[index].playerCurrentHandValue())) //check if busted
								{	
						
									cout << "  *  Busted!  *" << endl;
					
									choice = 2;
									break;
								}
								cout << "\n-----------------------------------" << endl;
								break;
							case 2:
								cout << "===================================" << endl;
								cout << "\n***********************************" << endl;
								cout << "  Player: " << index + 1 << " | Current Hand: " << players[index] << endl;
								cout << "***********************************" << endl;
								break;
							}
						}
					} while (choice != 2);
				}

				cout << "\n=====================================================\n";
              
				bool again = false;

                while (!again)
				{
					npcPlayer.playerCurrentHandValue();
                    if (computerPlayer.HitOrStand(npcPlayer.getPlayerHandTotal(), dealer.displayOneCard()))
					{
                        card = deck.drawCards();
                        npcPlayer.distributeCards(card);
                        again = false;
                    }
                    else 
					{
                        cout << "Computer Player Hand: " << npcPlayer << endl;
                        again = true;
                    }
				}
				cout << "Current Hand Value : " << npcPlayer.getPlayerHandTotal() << endl;
				cout << "Computer Player Balance: " << npcPlayer.getBalance() << endl;

				do
				{
					cout << "DEALER Hand: " << dealer << endl;
					dealer.playerCurrentHandValue();
					card = deck.drawCards();
					dealer.distributeCards(card);
				} while (!(dealer.getPlayerHandTotal() >= 17));	//draw another card until 17 or more

				cout << "Dealer Hand Total: " << dealer.getPlayerHandTotal() << endl;



				for (int index = 0; index < players.size(); index++) 
				{
					cout << "\n------------------------------------------" << endl;
					cout << "Player: " << index + 1 << " | Balance: " << players[index].getBalance() << endl;

					if (players[index].isBlackjack())
					{	
						players[index].getWinningAmount();
						cout << "Current Hand: " << players[index] << endl;
						cout << "Blackjack!!! "<< endl;
					}
					else 
					{
						cout << "Current Hand: " << players[index] << endl;
						players[index].playerCurrentHandValue();		

						//check if player has busted first
						if (players[index].isBusted(players[index].getPlayerHandTotal())) 
						{	
							cout << "Player Bets: " << players[index].getPlayerBets() << endl;
						}

						//check if player and dealer have same amount of points, if so, there's no winner
						else if (players[index].isEqualHand(players[index].getPlayerHandTotal(), dealer.getPlayerHandTotal()))
						{
							cout << "Player Bets: " << players[index].getPlayerBets() << endl;
							cout << "*** No Winner ***" << endl;
							players[index].drawRound();
						}

						//Players wins, if not busted and have more points than the dealer
						else if (players[index].playerWins(players[index].getPlayerHandTotal(), dealer.getPlayerHandTotal()))
						{
							cout << "Player Bets: " << players[index].getPlayerBets() << endl;
							players[index].getWinningAmount();
						}
						else 
						{
                           
							cout << "Player Bets: " << players[index].getPlayerBets() << endl;
						}
					}

                    cout << "Player Hand Total: " << players[index].getPlayerHandTotal() <<endl;
					cout << "Current Balance: " << players[index].getBalance() << endl;
				}

				cout << "\n=====================================================\n";

				//reshuffle if less than 30 cards
				if (deck.getNumberOfCards() < 30)
				{
					deck.reshuffle();
				}

				cout << "1. Play Again" << endl;
				cout << "2. Quit" << endl;
				cin >> menuOption;
				//players.clear();
				valid = true;

			} while (menuOption != 2);
		}
		catch (exception & e) {
			cout << e.what() << endl;
		}
	}

	system("pause");
	return 0;
}

*/