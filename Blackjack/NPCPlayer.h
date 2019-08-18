#pragma once
#include "Player.h"


class NPCPlayer : public Player {
private:
	int currentHandValue;
	
public:
	
	bool HitOrStand(int currentHandTotal, string dealerFaceUpCard)
	{
		if (currentHandTotal >= 17 && currentHandTotal <= 20)
		{
			return false;
		}
		if ((currentHandTotal == 16 && dealerFaceUpCard == "9") ||
			(currentHandTotal == 16 && dealerFaceUpCard == "A"))
		{
			return false;
		}

		if ((currentHandTotal >= 15 && dealerFaceUpCard == "10") ||
			(currentHandTotal >= 15 && dealerFaceUpCard == "J") ||
			(currentHandTotal >= 15 && dealerFaceUpCard == "Q") ||
			(currentHandTotal >= 15 && dealerFaceUpCard == "K"))
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
