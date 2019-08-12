#pragma once

#include "Player.h"
class computerPlayer : public Player {
private:
	int currentHandValue;
public:
	computerPlayer() {
		this->currentHandValue = 0;
	}
	bool HitOrStand(int currentHandTotal, string dealerFaceUpCard)
	{
		//If player hand value is greater or equal to 17 or greater, stand
		if (currentHandTotal >= 17)
		{
				return false;
		}
		//If player hand value is equal to 13 and dealer face-up card is 2 or 3, stand
		if ((currentHandTotal >= 13 && dealerFaceUpCard == "2") ||
            (currentHandTotal >= 13 && dealerFaceUpCard == "3"))
		{
			return false;
		}
		//If player hand value is equal to 12 or more and dealer face-up card is 4, 5 or 6, stand 
		if ((currentHandTotal >= 12 && dealerFaceUpCard == "4") ||
			(currentHandTotal >= 12 && dealerFaceUpCard == "5") ||
			(currentHandTotal >= 12 && dealerFaceUpCard == "6")) 
		{
			return false;
		}
		//Hit otherwise
		return true;
	}

};
