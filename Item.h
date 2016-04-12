#ifndef _ITEM_H_
#define _ITEM_H_

#include "Entity.h"
#include "Inventory.h"


class item : public Entity, public inventorys{

public:
	item(const char* name2, const char* desc2, bool storage) : Entity(name2, desc2), storage_item(storage){}
	int Get_Room(const int item_num);
	char* Get_Name(const int item_num) const; 


public: 
	int item_num; 
	int attack_plus, shield_plus, hp_plus; 
	bool carried; 
	int item_room;
	bool storage_item;

};

#endif
