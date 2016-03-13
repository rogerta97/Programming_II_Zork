#include <iostream>

#include "Player.h"
#include "Exits.h"
#include "Rooms.h"

class world{
public: 
	void CreateWorld(); 
	void Show(); 
	void Chek_input();
public: 
	Rooms* room; 
	exits* exit; 
	player* main_character; 
};


