#ifndef _CREATURE_H_
#define _CREATURE_H_

#define MAX_PLAYER_INVENTORY 10

#include "Entity.h"
#include "Vector.h"
#include <list>


class creature : public Entity{
public: 
	creature(){}
	creature(const char* name2, const char* desc2, int current_room2, int item2, int hp2, int attack2, int defense2, int coins2): Entity(name2, desc2), current_room(current_room2), item(item2), hp(hp2), attack(attack2), defense(defense2), coins(coins2){}
	int current_room, item, special_card = 0; 
	bool death = false;
	int hp, attack, defense, coins, damage; 

	
	Vector<int> inventory; 
	//int prov_inv[MAX_PLAYER_INVENTORY];
	char* item_name(int item_num);

};

#endif
