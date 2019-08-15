#pragma once
#include "Player.h"


class NPCPlayer : public Player {
private:
	int currentHandValue;
	
public:
	NPCPlayer() {
		this->currentHandValue = 0;
	}

	bool HitOrStand(int currentHandTotal, string dealerFaceUpCard)
	{
		if (currentHandTotal >= 17)
		{
			return false;
		}
		if ((currentHandTotal >= 13 && dealerFaceUpCard == "2") ||
            (currentHandTotal >= 13 && dealerFaceUpCard == "3"))
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

		return true;
	}

};
