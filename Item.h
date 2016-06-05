#ifndef _ITEM_H_
#define _ITEM_H_

#include "Inventory.h"


#define MAX_ITEMS_STORAGE 5
class item : public Entity {
public:
	item(const char* name2, const char* desc2, bool storage, int item_room_temp) : Entity(name2, desc2), storage_item(storage), item_room(item_room_temp){}
	char* Get_Name(int item_num) const{
		switch (item_num){
		case 0: return "glass"; break;
		case 1: return "key"; break;
		case 2: return "matchstick"; break;
		case 3: return "sword"; break;
		case 4: return "chest"; break;
		case 5: return "AttackCard"; break;
		case 6: return "Hammer"; break;
		case 7: return "note"; break;
		case 8: return "shield"; break;
		case 9: return "peak"; break;
		case 10: return "gunpowder"; break;
		case 11: return "DefenseCard"; break;
		case 12: return "stringbox"; break;
		case 13: return "wick"; break;
		case 14: return "bomb"; break;
		case 15: return "fan"; break;
		case 16: return "+20-HPCard"; break;
		}
	}

public: 
	int item_num; 
	int attack, shield_plus, hp_plus, cost; 
	bool carried; 
	int item_room;
	bool storage_item;
	int prov_inv[MAX_ITEMS_STORAGE];
};

#endif
