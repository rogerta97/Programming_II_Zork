#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Creature.h"
#include "Inventory.h"

#define MAX_PLAYER_INVENTORY 10

class player : public creature{
public:
	player(){}
	/*int carried_weapon;
	int card_hability; 
	int prov_inv[MAX_PLAYER_INVENTORY];*/ 

public: 
	char* item_name(int item_num); 
};

#endif

