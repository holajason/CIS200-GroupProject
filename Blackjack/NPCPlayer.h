#pragma once
#include "Player.h"
class NPCPlayer : public Players {
private:
	int currentHandValue;
	string cardTwo = "2";
public:
	NPCPlayer() : Players(1) {
		Players::setPlayersBets(1);
	}


	bool HitOrStand(int currentHandTotal, string dealerFaceUpCard)
	{
		if (currentHandTotal >= 17 && currentHandTotal <= 21)
		{
				return false;
		}

		if ((currentHandTotal >= 13 && dealerFaceUpCard == "2") ||
            (currentHandTotal >= 13 && dealerFaceUpCard == "3") ||
			(currentHandTotal >= 13 && dealerFaceUpCard == "4") ||
			(currentHandTotal >= 13 && dealerFaceUpCard == "5") ||
			(currentHandTotal >= 13 && dealerFaceUpCard == "6"))
		{
			return false;
		}

		if ((currentHandTotal >= 12 && dealerFaceUpCard == "4") ||
			(currentHandTotal >= 12 && dealerFaceUpCard == "5") ||
			(currentHandTotal >= 12 && dealerFaceUpCard == "6")
			) 
		{
			return false;
		}

		if (((currentHandTotal == 16) && dealerFaceUpCard == "9") ||
			((currentHandTotal == 16) && dealerFaceUpCard == "10") ||
			((currentHandTotal == 16) && dealerFaceUpCard == "J") ||
			((currentHandTotal == 16) && dealerFaceUpCard == "Q") ||
			((currentHandTotal == 16) && dealerFaceUpCard == "K") ||
			((currentHandTotal == 16) && dealerFaceUpCard == "A"))
		{
			return false;
		}

		if ((currentHandTotal == 15 && dealerFaceUpCard == "10") ||
		    (currentHandTotal == 15 && dealerFaceUpCard == "J") ||
		    (currentHandTotal == 15 && dealerFaceUpCard == "Q") ||
		    (currentHandTotal == 15 && dealerFaceUpCard == "K"))
		{
			return false;
		}
		
		if (((getCardValue("A") == 11 && (currentHandTotal == 20 || currentHandTotal == 19)) && dealerFaceUpCard == "2") ||
			((getCardValue("A") == 11 && (currentHandTotal == 20 || currentHandTotal == 19)) && dealerFaceUpCard == "3") ||
			((getCardValue("A") == 11 && (currentHandTotal == 20 || currentHandTotal == 19)) && dealerFaceUpCard == "4") ||
			((getCardValue("A") == 11 && (currentHandTotal == 20 || currentHandTotal == 19)) && dealerFaceUpCard == "5") ||
			((getCardValue("A") == 11 && (currentHandTotal == 20 || currentHandTotal == 19)) && dealerFaceUpCard == "6") ||
			((getCardValue("A") == 11 && (currentHandTotal == 20 || currentHandTotal == 19)) && dealerFaceUpCard == "7") ||
			((getCardValue("A") == 11 && (currentHandTotal == 20 || currentHandTotal == 19)) && dealerFaceUpCard == "8") ||
			((getCardValue("A") == 11 && (currentHandTotal == 20 || currentHandTotal == 19)) && dealerFaceUpCard == "9") ||
			((getCardValue("A") == 11 && (currentHandTotal == 20 || currentHandTotal == 19)) && dealerFaceUpCard == "10") ||
			((getCardValue("A") == 11 && (currentHandTotal == 20 || currentHandTotal == 19)) && dealerFaceUpCard == "J") ||
			((getCardValue("A") == 11 && (currentHandTotal == 20 || currentHandTotal == 19)) && dealerFaceUpCard == "Q") ||
			((getCardValue("A") == 11 && (currentHandTotal == 20 || currentHandTotal == 19)) && dealerFaceUpCard == "K") ||
			((getCardValue("A") == 11 && (currentHandTotal == 20 || currentHandTotal == 19)) && dealerFaceUpCard == "A"))
		{
			return false;
		}

		if (((getCardValue("A") == 11 && (currentHandTotal == 18)) && dealerFaceUpCard == "2") ||
			((getCardValue("A") == 11 && (currentHandTotal == 18)) && dealerFaceUpCard == "3") ||
			((getCardValue("A") == 11 && (currentHandTotal == 18)) && dealerFaceUpCard == "4") ||
			((getCardValue("A") == 11 && (currentHandTotal == 18)) && dealerFaceUpCard == "5") ||
			((getCardValue("A") == 11 && (currentHandTotal == 18)) && dealerFaceUpCard == "6") ||
			((getCardValue("A") == 11 && (currentHandTotal == 18)) && dealerFaceUpCard == "7") ||
			((getCardValue("A") == 11 && (currentHandTotal == 18)) && dealerFaceUpCard == "8"))
		{
			return false;
		}

		return true;
	}

};
