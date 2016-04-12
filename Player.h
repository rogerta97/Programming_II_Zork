#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Combat.h"
#include "Inventory.h"
#include "Entity.h"

#define MAX_PLAYER_INVENTORY 10

class player : public combat, public inventorys{
public:
	int current_room;
	int weapon;
	int card_hability; 

public: 
	char* item_name(int item_num); 
};

#endif

