#include <iostream>

#include "Player.h"
#include "Entity.h"
#include "Item.h"
#include "Exits.h"
#include "Strings.h"
#include "Simple_Objects.h"
#include "Rooms.h"

#define ROOMS_NUMB 18
#define EXITS_NUMB 17
#define ITEMS_NUMB 4
#define SIMPLE_NUMB 5

class world{
private:
	void move_character(const char*, bool&, bool&);
	void Show_Items(const int) const; 
	void Pick_Item(const char*, const int); 
	void Drop_item(const char*, int);
	void Move_Simple_Obj(const char*); 
	void Open_Stuff(int current_room, bool& action_done, int object_open);
	void Close_Stuff(const char* move, int current_room, bool& action_done);
	unsigned int Carried_Obj_Numb();
	void Full_inventory(int);
	void empty_inventory(int);
	void Show_inventory() const; 
	void Equip_item(const char*);
	void Unequip_item(const char*);
	int Get_Num(const char* item_num) const;
	bool isin_inventory(const char*);
	void Put_Objects(); 
	void put_object_into_object(int, int);
	
	bool operator==(const char*); 

	enum open_type{
		OPEN_DOOR,
		OPEN_DRAWER,
		OPEN_CLOSET,
	};
	enum simple_objects{
		SIMPLE_SHELV,
		SIMPLE_FIREPLACE,
		SIMPLE_DRAWER,
		SIMPLE_CLOSET,
	};
	enum items{
		ITEM_GLASS,
		ITEM_KEY,
		ITEM_MATCH,
		ITEM_SWORD,
	};

public:
	void CreateWorld();
	void Check_input();
	void Destroy_World(); 

public:
	Rooms* room[ROOMS_NUMB];
	exits* exit[EXITS_NUMB];
	player* main_character;
	item* items[ITEMS_NUMB];
	Simple_Objects* simple_obj[SIMPLE_NUMB]; 
	String* test_string; 
};
