#ifndef _ITEM_H_
#define _ITEM_H_

#include "Entity.h"

class item : public Entity{

public:
	item(const char* name2, const char* desc2) : Entity(name2, desc2){}
	int Get_Room(const int item_num);
	char* Get_Name(const int item_num) const; 


public: 
	int item_num; 
	int attack_plus, shield_plus, hp_plus; 
	bool carried; 
	int item_room;

};

#endif
