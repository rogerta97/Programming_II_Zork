#ifndef _NPC_H_
#define _NPC_H_

#include "Creature.h"

class NPC : public creature{
public: 
	NPC(const char* name2, const char* desc2, int current_room2, int item2, int hp2, int attack2, int defense2, int coins2) : creature(name2, desc2, current_room2, item2, hp2, attack2, defense2, coins2){}
};

#endif