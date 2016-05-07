#ifndef _CREATURE_H_
#define _CREATURE_H_

#define MAX_PLAYER_INVENTORY 10

#include "Entity.h"

class creature : public Entity{
public: 
	creature(){}
	creature(const char* name2, const char* desc2, int current_room2): Entity(name2, desc2), current_room(current_room2){}
	int current_room, item, special_card = 0; 
	bool death = false;
	int hp, attack, defense, coins, damage; 

	int prov_inv[MAX_PLAYER_INVENTORY];
	char* item_name(int item_num);
};

#endif