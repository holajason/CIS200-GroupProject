#pragma once
#include "Player.h"
class NPCPlayer : public Players {
private:
	int bet;
public:
	NPCPlayer() : Players(1) {
		this->bet = 1;
	}
};