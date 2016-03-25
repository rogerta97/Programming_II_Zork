#include <iostream>

#include "Player.h"
#include "Entity.h"
#include "Exits.h"
#include "Rooms.h"

class world{
private:
	void move_character(const char*, bool&, bool&);
public:
	void CreateWorld();
	void Chek_input();
	void Destroy_World(); 
public:
	Rooms* room;
	exits* exit;
	player* main_character;
};
