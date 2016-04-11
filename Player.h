#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Combat.h"
#include "Entity.h"

class player : public combat{
public:
	int current_room;
	int weapon;
	int card_hability; 
	int inventory[10];

public: 
	char* item_name(int item_num); 
};

#endif

