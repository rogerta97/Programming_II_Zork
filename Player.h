#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Creature.h"
#include "Inventory.h"

#define MAX_PLAYER_INVENTORY 10

class player : public creature{
public:
	player(const char* name2, const char* desc2, int current_room2, int item2, int hp2, int attack2, int defense2, int coins2) : creature(name2, desc2, current_room2, item2, hp2, attack2, defense2, coins2){}

public: 
	char* item_name(int item_num); 
};

#endif

